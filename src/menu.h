#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    bool initialize(); //responsibility of loading the font, texture, and setting up the text and buttons , returns false if there is an error
    void handleInput(sf::RenderWindow& window); //takes a reference to the window to handle input
    void render(sf::RenderWindow& window); //takes a reference to the window to render to
    bool isStartClicked(const sf::Vector2i& mousePos); //takes a reference to the mouse position
    bool isSettingsClicked(const sf::Vector2i& mousePos); //
    bool isQuitClicked(const sf::Vector2i& mousePos);


private:
    sf::Font font; // this class is used to load and manipulate font files
    sf::Texture backgroundTexture; // this class is used to load and manipulate texture files
    sf::Sprite backgroundSprite; // this class is used to create a sprite which is a 2D image that can be drawn to the window
    sf::Text title; // this class is used to create text
    sf::RectangleShape startButton; // this class is used to create a rectangle shape
    sf::Text startText; // this class is used to create text
    sf::RectangleShape settingsButton; // allows us to define the size, positon  and color of the rectangle
    sf::Text settingsText; // allows us to define the size, positon  and color of the text
    sf::RectangleShape quitButton; // allows us to define the size, positon  and color of the rectangle
    sf::Text quitText; // allows us to define the size, positon  and color of the text
};

#endif // MENU_H
