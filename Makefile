# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/opt/homebrew/Cellar/sfml/2.6.1/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Targets
all: bin/main

# Build the executable
bin/main: obj/main.o obj/game.o obj/CharacterSetUp.o obj/StateManager.o obj/menu.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Build the main object file
obj/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the game object file
obj/game.o: src/game.cpp src/game.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the CharacterSetUp object file
obj/CharacterSetUp.o: src/CharacterSetUp.cpp src/CharacterSetUp.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the StateManager object file
obj/StateManager.o: src/StateManager.cpp src/StateManager.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the Menu object file
obj/menu.o: src/menu.cpp src/menu.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f obj/*.o bin/main
