#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "CharacterSetUp.h"


class Game {
public:
    Game();
    bool initialize();
    void handleInput(sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);
    void startClock(); // Start the clock

private:
    // Game resources
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text instructions;

    //Timing Resources
    sf::Clock clock;
    sf::Time time;
    bool showInstructions = false; // Flag to show instructions
    bool clockStarted = false; // Flag to check if the clock has started
    bool clockStartedOnce = false; // Flag to check if the clock has started once
    bool hasPrintedInstructionsMessage = false; // Flag to track if the message has been printed

    CharacterSetUp characterSetUp; // Add this member variable

};

#endif // GAME_H