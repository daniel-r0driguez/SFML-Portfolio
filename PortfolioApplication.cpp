#include "PortfolioApplication.h"

sf::RenderWindow PortfolioApplication::_window;
std::vector<SFMLObject*> PortfolioApplication::_objects;
sf::RenderTexture PortfolioApplication::_drawableTexture;
sf::Sprite PortfolioApplication::_renderedTexture;
std::vector<Runnable*> PortfolioApplication::_projects;
Thumbnail PortfolioApplication::_thumbnail;
int PortfolioApplication::_curIndex;

void PortfolioApplication::run()
{
    _window.create({1000, 800, 32}, "Portfolio Project");
    _window.setFramerateLimit(60);
    _drawableTexture.create(800, 400);
    _renderedTexture.setTexture(_drawableTexture.getTexture());
    sf::Vector2f thumbnailSize = {800, 400};

    GreenCircleApplication greenCircleApplication;
    BouncingBallApplication bouncingBallApplication;
    sfml2DArrayApplication sfml2DArrayApplication;
    PlayingCardApplication playingCardApplication;
    PhaserApplication phaserApplication;
    PokerAnalysisApplication pokerAnalysisApplication;
    FinalGameApplication finalGameApplication;

    PortfolioApplication::addProject(greenCircleApplication);
    PortfolioApplication::addProject(bouncingBallApplication);
    PortfolioApplication::addProject(sfml2DArrayApplication);
    PortfolioApplication::addProject(playingCardApplication);
    PortfolioApplication::addProject(phaserApplication);
    PortfolioApplication::addProject(pokerAnalysisApplication);
    PortfolioApplication::addProject(finalGameApplication);

    _thumbnail.setRunnable(_projects.at(0));
    _thumbnail.setTexture(&PortfolioImages::getImage(_thumbnail.getProject()->getImageEnum()), thumbnailSize);
    addObject(_thumbnail);

    TextBox textBox("Controls:\n"
                    "[Arrow Keys]: Use the arrow keys to navigate through the projects.\n"
                    "Click or press [Enter] while on a project to run it.\n"
                    "Press [Esc] to stop current project and return to main screen", 30, 10, 10);

    sf::FloatRect bounds = _renderedTexture.getGlobalBounds();
    textBox.setTextColor(sf::Color::Black);
    textBox.setOutlineColor(sf::Color::Black);
    textBox.setOutlineThickness(-5);
    textBox.setPosition(bounds.left, bounds.height + bounds.top);

    sf::Event event;
    while (_window.isOpen())
    {
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (_curIndex > 0)
                {
                    --_curIndex;
                    _thumbnail.setRunnable(_projects.at(_curIndex));
                }
                else
                {
                    _curIndex = static_cast<int>(_projects.size()) - 1;
                    _thumbnail.setRunnable(_projects.at(_curIndex));
                }
                const Runnable* project = _thumbnail.getProject();
                _thumbnail.setTexture(&PortfolioImages::getImage(project->getImageEnum()), thumbnailSize);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (_curIndex < _projects.size() - 1)
                {
                    ++_curIndex;
                    _thumbnail.setRunnable(_projects.at(_curIndex));
                }
                else
                {
                    _curIndex = 0;
                    _thumbnail.setRunnable(_projects.at(_curIndex));
                }
                const Runnable* project = _thumbnail.getProject();
                _thumbnail.setTexture(&PortfolioImages::getImage(project->getImageEnum()), thumbnailSize);
            }

            for (SFMLObject* object : _objects)
            {
                object->eventHandler(_window, event);
            }
        }
        _drawableTexture.clear(sf::Color::Black);
        drawObjects();
        _drawableTexture.display();

        _window.clear(sf::Color::Magenta);
        _window.draw(textBox);
        _window.draw(_renderedTexture);
        _window.display();
    }
}

void PortfolioApplication::addObject(SFMLObject& object)
{
    _objects.push_back(&object);
}

void PortfolioApplication::addProject(Runnable &runnable)
{
    runnable.setRenderTexture(&_drawableTexture);
    runnable.setSprite(&_renderedTexture);
    _projects.push_back(&runnable);
}

void PortfolioApplication::drawObjects()
{
    for (SFMLObject* object : _objects)
    {
        _drawableTexture.draw(*object);
    }
}