#include "StateManager.h"
#include <iostream>

StateManager::StateManager()
    : window(sf::VideoMode(1200, 600), "SFML Game"), currentState(GameState::Menu) {
    menu.initialize();
    game.initialize();
}

void StateManager::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        update();
        render();
    }
}

void StateManager::update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    switch (currentState) {
        case GameState::Menu:
            menu.handleInput(window);
            if (menu.isStartClicked(mousePos)) {
                currentState = GameState::Game;
            }
            break;

        case GameState::Game:
            game.handleInput(window);
            game.update();
            break;
    }
}

void StateManager::render() {
    window.clear();

    switch (currentState) {
        case GameState::Menu:
            menu.render(window);
            break;

        case GameState::Game:
            game.render(window);
            break;
    }

    window.display();
}
