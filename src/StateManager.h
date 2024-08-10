#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "menu.h"
#include "game.h"

class StateManager {

public:
    StateManager(); //Constructor, initialize the StateManager
    void run(); //Run the game loop

private:
    void update(); //Update the game state based on the current state
    void render(); //clear the window and render the current state

    sf::RenderWindow window; //Window to render to
    GameState currentState; //creating a variable to hold the current state of the game
    Menu menu; //Menu state
    Game game; //Game state


};

















#endif // STATEMANAGER_H