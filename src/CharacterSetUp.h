#ifndef CHARACTERSETUP_H
#define CHARACTERSETUP_H

#include <SFML/Graphics.hpp>

class CharacterSetUp {

public:
    void setUpJonah();
    void render(sf::RenderWindow& window);

private:
    sf::Texture characterTexture;
    sf::Sprite characterSprite;
    sf::Font font;
    sf::Text bibleVerse;


};

#endif // CHARACTERSETUP_H