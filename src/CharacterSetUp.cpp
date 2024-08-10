#include "CharacterSetUp.h"
#include <iostream>

void CharacterSetUp::setUpJonah() {
	if (!characterTexture.loadFromFile("resources/jonahbeingswalloed.jpeg")) {
		std::cerr << "Failed to load character texture" << std::endl;
	}

	characterSprite.setTexture(characterTexture);
	characterSprite.setPosition(50, 50);

	if (!font.loadFromFile("resources/Eczar-VariableFont_wght.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
	}

	bibleVerse.setFont(font);
	bibleVerse.setString("But the Lord provided a great fish to \n"
						 "swallow Jonah, and Jonah was inside the fish for three days and \n"
						 "three nights. - Jonah 1:17 (NIV)");

	// Move the bible verse to the right side of the window
	bibleVerse.setCharacterSize(30);
	bibleVerse.setFillColor(sf::Color::Black);
	bibleVerse.setStyle(sf::Text::Bold);
	sf::FloatRect bibleVerseRect = bibleVerse.getLocalBounds();
	bibleVerse.setOrigin(bibleVerseRect.width / 2.0f, bibleVerseRect.height / 2.0f);
	bibleVerse.setPosition(1200 / 2.0f, 600 / 2.0f);
}

void CharacterSetUp::render(sf::RenderWindow& window) {
	window.draw(bibleVerse);
	window.draw(characterSprite);
}