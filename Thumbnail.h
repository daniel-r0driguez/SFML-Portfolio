#ifndef PORTFOLIO_PROJECT_THUMBNAIL_H
#define PORTFOLIO_PROJECT_THUMBNAIL_H
#include "SFML/Graphics.hpp"
#include "SFMLObject.h"
#include "MouseEvents.h"
#include "Runnable.h"

class Thumbnail : public SFMLObject {
private:
    sf::Sprite _thumbnail;
    Runnable* _project;
    const sf::Texture* _texture;

public:
    Thumbnail();
    Thumbnail(const sf::Texture* texture, const sf::Vector2f& size, const sf::Vector2f& position);
    const Runnable* getProject();
    void setTexture(const sf::Texture* texture, const sf::Vector2f& size);
    void setRunnable(Runnable* runnable);
    sf::Vector2f getPosition() const override;
    void update(float dt) const override;
    void setPosition(const sf::Vector2f &position) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void eventHandler(sf::RenderWindow& target, sf::Event event) const override;
    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;

private:
    void scaleToSize(const sf::Texture* texture, const sf::Vector2f& size);
};

#endif //PORTFOLIO_PROJECT_THUMBNAIL_H