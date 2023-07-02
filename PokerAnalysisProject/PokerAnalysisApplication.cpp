#include "PokerAnalysisApplication.h"

PokerAnalysisApplication::PokerAnalysisApplication()
{
    this->_image = ThumbnailImage::POKER_ANALYSIS;
}

void PokerAnalysisApplication::addComponent(Component &component)
{
    if (this->_components)
    {
        this->_components->push_back(&component);
    }
}

void PokerAnalysisApplication::clearComponents()
{
    delete this->_components;
    this->_components = nullptr;
}

void PokerAnalysisApplication::run2(sf::RenderWindow &mainWindow)
{
    // Original size of the window.
    sf::Vector2u originalWindowSize = mainWindow.getSize();
    // The original size of the texture. Usually from the main SFML loop.
    sf::Vector2u originalTextureSize = this->_textureToDrawOn->getSize();

    // The new size of the texture for this particular project.
    sf::Vector2u newTextureSize = {1024, 920};
    // Set the new size of the window to fit the contents of this project.
    mainWindow.setSize(newTextureSize);

    // Clear the contents from before.
    this->_textureToDrawOn->clear();
    // Set the new size of the sf::RenderTexture.
    this->_textureToDrawOn->create(newTextureSize.x, newTextureSize.y);

    // Update the texture rect of the sf::Sprite, which is our this->_textureToRender->
    // This way, the drawing does not look stretched out or messed up.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(newTextureSize.x), static_cast<int>(newTextureSize.y)});

    bool isRunning = true;
    sf::Event event;

    while (isRunning)
    {
        while(mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isRunning = false;
                // Delete the components before we close the window to avoid memory leaks.
                clearComponents();
                mainWindow.close();
            }
            if (event.key.code == sf::Keyboard::Escape)
            {
                isRunning = false;
                clearComponents();
            }
        }
        this->_textureToDrawOn->clear(sf::Color::Green);
        if (this->_components)
        {
            for (Component* c : *this->_components)
            {
                this->_textureToDrawOn->draw(*c);
            }
        }
        this->_textureToDrawOn->display();

        mainWindow.clear(sf::Color::Black);
        mainWindow.draw(*this->_textureToRender);
        mainWindow.display();
    }
    // We have to reset to the previous  state that the sf::RenderTexture and sf::Sprite came in with.
    // Reset the window to its original size.
    mainWindow.setSize(originalWindowSize);
    // Set the sf::RenderTexture to its previous size.
    this->_textureToDrawOn->create(originalTextureSize.x, originalTextureSize.y);
    // Set the textureRect to fit this original size.
    this->_textureToRender->setTextureRect({0, 0, static_cast<int>(originalTextureSize.x), static_cast<int>(originalTextureSize.y)});
    // Clear the contents drawn from this project, just in case any was left.
    this->_textureToDrawOn->clear();
}


void PokerAnalysisApplication::run(sf::RenderWindow& mainWindow)
{
    checkIfRunnable();
    // Make a new Vector to hold our items.
    this->_components = new std::vector<Component*>();

    // Constants for the program.
    const int MAX_ROUNDS = 650000;
    const int MAX_SCORES = PokerScore::Scores::LAST_POKER_SCORE;

    // Simulating the Poker rounds 650,000 times.
    // The collection of scores is returned after the simulation is complete.
    std::vector<int> globalScores = SimulatePokerRounds::simulate(MAX_ROUNDS);

    // SFML part
    const float X_POS = 100;
    const float Y_POS = 0;
    const float SPACING = 20;
    sf::FloatRect prevBounds = {sf::Vector2f(X_POS, Y_POS), sf::Vector2f(0,0)};
    // Declare vectors which will hold the card hands, poker scores, and hand information...
    // ...which will represent each of the ten possible poker scores.
    std::vector<CardHandSFML> cardHands(MAX_SCORES);
    std::vector<PokerScore> cardScores(MAX_SCORES);
    std::vector<TextBox> handInformation(MAX_SCORES);

    // For each possible Poker score...
    for (int i = 0; i < MAX_SCORES; ++i)
    {
        // 1. Generate a hand of cards able to achieve that score.
        SetHand::setHandTo(static_cast<PokerScore::Scores>(i), cardHands.at(i));
        // 2. Score the hand of cards.
        cardScores.at(i) = CardHandScorer::scorePokerHand(cardHands.at(i));
        // 3. Configure the current CardHandSFML object for displaying.
        configureHandForSFML(cardHands.at(i), prevBounds.left, prevBounds.top + prevBounds.height + SPACING);
        // 4. Grab the previous bounds in order to have spacing.
        prevBounds = cardHands.at(i).getPosition();
        // 5. Configure the TextBox object.
        configureTextBox(handInformation.at(i), "Hand Type: " + PokerScore::SCORES_STR[static_cast<PokerScore::Scores>(i)] +
                                                "\nHand can count as a: " + cardScores.at(i).toString() +
                                                "\n" + ((globalScores.at(i) != 0) ? "Probability is [1 : " +
                                                                                    std::to_string(MAX_ROUNDS / float(globalScores.at(i))) + "]": "No Pulls"),
                         prevBounds.left + cardHands.at(i).getWidth() + SPACING, prevBounds.top);
    }

    // Once the simulation is complete and all the SFML components are configured...
    // ...add these new components into the FinalGameApplication.
    for (int i = 0; i < MAX_SCORES; ++i)
    {
        addComponent(cardHands.at(i));
        addComponent(handInformation.at(i));
    }
    // Run the SFML part of the program.
    run2(mainWindow);
}

void PokerAnalysisApplication::configureHandForSFML(CardHandSFML& hand, float xPos, float yPos)
{
    const float SPACING_BETWEEN_CARDS = 10;
    const float CARD_SCALE = 0.35;
    hand.setSpacing(SPACING_BETWEEN_CARDS);
    hand.setCardScale(CARD_SCALE);
    hand.setPosition(xPos, yPos);
}

void PokerAnalysisApplication::configureTextBox(TextBox& textBox, const std::string& text, float xPos, float yPos)
{
    const float PADDING = 10;
    const float OUTLINE_THICKNESS = - (PADDING / 5);
    unsigned int CHARACTER_SIZE = 10;
    textBox.setCharacterSize(CHARACTER_SIZE);
    textBox.setOutlineThickness(OUTLINE_THICKNESS);
    textBox.setOutlineColor(sf::Color(217, 182, 59));
    textBox.setText(text);
    textBox.setTextColor(sf::Color::Black);
    textBox.setPadding(PADDING, PADDING);
    textBox.setPosition(xPos, yPos);
}
