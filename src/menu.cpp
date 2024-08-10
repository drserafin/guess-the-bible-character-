#include "menu.h"
#include <iostream>

Menu::Menu() {}

// initialize the menu by setting up the font, background image, title, buttons, and text
bool Menu::initialize() {

    //creating a function to load the font, texture, and setting up the text and buttons
    //returns false if there is an error
    if (!font.loadFromFile("resources/Eczar-VariableFont_wght.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return false;
    }

    if (!backgroundTexture.loadFromFile("/Users/kevinserafin/Documents/SFML_Project/resources/menuBackground.jpg")) {
        std::cerr << "Error loading background image" << std::endl;
        return false;
    }

    backgroundSprite.setTexture(backgroundTexture); //this sets up the image to used by the sprite
    sf::Vector2u textureSize = backgroundTexture.getSize(); //gets the size of the texture (image)
    float scaleX = static_cast<float>(1200) / textureSize.x; //scales the image to the window size
    float scaleY = static_cast<float>(600) / textureSize.y;
    float scale = std::max(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);

    title.setFont(font);
    title.setString("Welcome to Guess the Bible Character!");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    sf::FloatRect titleRect = title.getLocalBounds(); //gets the size of the text
    title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
    title.setPosition(1200 / 2.0f, 600 / 2.0f - 150);

    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color::Cyan);
    startButton.setPosition(1200 / 2.0f - 100, 600 / 2.0f);

    startText.setFont(font);
    startText.setString("Start Game");
    startText.setCharacterSize(35);
    startText.setFillColor(sf::Color::Black);
    sf::FloatRect startTextRect = startText.getLocalBounds();
    startText.setOrigin(startTextRect.left + startTextRect.width / 2.0f, startTextRect.top + startTextRect.height / 2.0f);
    startText.setPosition(startButton.getPosition().x + startButton.getSize().x / 2.0f, startButton.getPosition().y + startButton.getSize().y / 2.0f);

    settingsButton.setSize(sf::Vector2f(200, 50));
    settingsButton.setFillColor(sf::Color::Cyan);
    settingsButton.setPosition(1200 / 2.0f - 100, 600 / 2.0f + 70);

    settingsText.setFont(font);
    settingsText.setString("Settings");
    settingsText.setCharacterSize(35);
    settingsText.setFillColor(sf::Color::Black);
    sf::FloatRect settingsTextRect = settingsText.getLocalBounds();
    settingsText.setOrigin(settingsTextRect.left + settingsTextRect.width / 2.0f, settingsTextRect.top + settingsTextRect.height / 2.0f);
    settingsText.setPosition(settingsButton.getPosition().x + settingsButton.getSize().x / 2.0f, settingsButton.getPosition().y + settingsButton.getSize().y / 2.0f);

    quitButton.setSize(sf::Vector2f(200, 50));
    quitButton.setFillColor(sf::Color::Cyan);
    quitButton.setPosition(1200 / 2.0f - 100, 600 / 2.0f + 140);

    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(35);
    quitText.setFillColor(sf::Color::Black);
    sf::FloatRect quitTextRect = quitText.getLocalBounds();
    quitText.setOrigin(quitTextRect.left + quitTextRect.width / 2.0f, quitTextRect.top + quitTextRect.height / 2.0f);
    quitText.setPosition(quitButton.getPosition().x + quitButton.getSize().x / 2.0f, quitButton.getPosition().y + quitButton.getSize().y / 2.0f);

    return true;
}

bool Menu::isStartClicked(const sf::Vector2i& mousePos) {
    return startButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Menu::isSettingsClicked(const sf::Vector2i& mousePos) {
    return settingsButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool Menu::isQuitClicked(const sf::Vector2i& mousePos) {
    return quitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) &&
           sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Menu::handleInput(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (isStartClicked(mousePos)) {
        std::cout << "Start Game button clicked" << std::endl;
    }
    if (isSettingsClicked(mousePos)) {
        std::cout << "Settings button clicked" << std::endl;
    }
    if (isQuitClicked(mousePos)) {
        std::cout << "Quit button clicked" << std::endl;
        window.close();
    }
}

// the render function uses the memeber variables to draw the menu to the window
void Menu::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite); // Draw the background image
    window.draw(title); // Draw the title text
    window.draw(startButton); // Draw the start button
    window.draw(startText); // Draw the start button text
    window.draw(settingsButton); // Draw the settings button
    window.draw(settingsText); // Draw the settings button text
    window.draw(quitButton); // Draw the quit button
    window.draw(quitText); // Draw the quit button text
}
