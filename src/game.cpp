#include "game.h"
#include "CharacterSetUp.h"
#include <iostream>

Game::Game() {}

bool Game::initialize() {
    if (!backgroundTexture.loadFromFile("resources/gameBackground.jpg")) {
        std::cerr << "Error loading background image" << std::endl;
        return false;
    }
     // Set up the background sprite to cover the window
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    float scaleX = static_cast<float>(1200) / textureSize.x;
    float scaleY = static_cast<float>(600) / textureSize.y;
    float scale = std::max(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);

    if (!font.loadFromFile("resources/Eczar-VariableFont_wght.ttf")) {
            std::cerr << "Error loading font" << std::endl;
            return false;
    }

    instructions.setFont(font);
    instructions.setString(
            "You will be shown an image and you have to guess the character.\n"
            "You'll have 10 seconds to guess the character.\n"
            "God Bless!"
    );
    instructions.setCharacterSize(30);
    instructions.setFillColor(sf::Color::Black); // Use a visible color
    instructions.setStyle(sf::Text::Bold);
    sf::FloatRect instructionsRect = instructions.getLocalBounds();
    instructions.setOrigin(instructionsRect.width / 2.0f, instructionsRect.height / 2.0f);
    instructions.setPosition(1200 / 2.0f, 600 / 2.0f);

     void setUpJonah();


    return true;

}

void Game::update() {
    if (!clockStartedOnce) {
        startClock(); // Start the clock
        clockStartedOnce = true;
    }

    if (showInstructions && clockStarted && clock.getElapsedTime() > sf::seconds(5)) { // once we reached 5 seconds we will hide the instructions
        showInstructions = false; // Hide instructions after 5 seconds
        clockStarted = false; // Stop the clock
    }
}

void Game::handleInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::startClock() {
    clock.restart(); // Start the clock
    showInstructions = true; // this will be passed down to the render function inside our if statement
    clockStarted = true; // Mark that the clock has been started
}


void Game::render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);

   if (showInstructions) {
        if (!hasPrintedInstructionsMessage) {
            std::cout << "Drawing instructions" << std::endl; // Print message once
            hasPrintedInstructionsMessage = true; // Set flag to true after printing
        }
        window.draw(instructions);
    } else {
        hasPrintedInstructionsMessage = false; // Reset flag when instructions are not shown
        void setUpJonah();
    }

}

