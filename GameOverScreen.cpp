#include "GameOverScreen.h"
#include <iostream>

// Constructor for GameOverScreen
// Initializes the screen with given dimensions, displays the score, and sets up options for the game over menu.
GameOverScreen::GameOverScreen(float width, float height, int score)
    : WelcomeScreen(width, height), selectedOptionIndex(0) // Calls the WelcomeScreen constructor and initializes selectedOptionIndex
{
    // Load the background texture for the game over screen
    if (!this->backgroundTexture.loadFromFile("Textures/death.png")) {
        std::cout << "ERROR::GAMEOVER SCREEN::Could not load background texture" << std::endl;
    }

    // Set the texture for the background and scale it to fit the window dimensions
    this->background.setTexture(this->backgroundTexture);
    this->background.setScale(
        width / this->backgroundTexture.getSize().x, 
        height / this->backgroundTexture.getSize().y);

    // Set up the "Game Over" title text
    title.setFont(font);  // Use the font defined in the WelcomeScreen class
    title.setString("Game Over");  // Display "Game Over"
    title.setCharacterSize(60);  // Set the font size
    title.setFillColor(sf::Color::Red);  // Set the text color to red
    title.setPosition(width / 2 - title.getGlobalBounds().width / 2, height / 4);  // Center the title text

    // Set up the score text to display the player's final score
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));  // Display the score
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);  // Set the text color to white
    scoreText.setPosition(width / 2 - scoreText.getGlobalBounds().width / 2, height / 2.5);  // Center the score text

    // Set up the menu options (Restart and Exit)
    std::string optionStrings[] = {"Restart", "Exit"};  // Menu options
    for (int i = 0; i < 2; ++i) {
        options[i].setFont(font);
        options[i].setString(optionStrings[i]);
        options[i].setCharacterSize(40);
        options[i].setFillColor(i == selectedOptionIndex ? sf::Color::Yellow : sf::Color::White);  // Highlight the selected option
        options[i].setPosition(width / 2 - options[i].getGlobalBounds().width / 2, height / 1.8 + i * 50);  // Position the options
    }
}

// Function to draw the game over screen elements on the window
void GameOverScreen::draw(sf::RenderWindow& window) {
    window.draw(background);  // Draw the background image
    window.draw(title);       // Draw the "Game Over" title
    window.draw(scoreText);   // Draw the score text
    for (int i = 0; i < 2; ++i) {
        window.draw(options[i]);  // Draw each menu option
    }
}

// Move the selection in the menu upwards
void GameOverScreen::moveUp() {
    if (selectedOptionIndex > 0) {  // Ensure we don't move above the first option
        options[selectedOptionIndex].setFillColor(sf::Color::White);  // Reset the current option's color
        --selectedOptionIndex;  // Move the selection up
        options[selectedOptionIndex].setFillColor(sf::Color::Yellow);  // Highlight the new selected option
    }
}

// Move the selection in the menu downwards
void GameOverScreen::moveDown() {
    if (selectedOptionIndex < 1) {  // Ensure we don't move below the last option
        options[selectedOptionIndex].setFillColor(sf::Color::White);  // Reset the current option's color
        ++selectedOptionIndex;  // Move the selection down
        options[selectedOptionIndex].setFillColor(sf::Color::Yellow);  // Highlight the new selected option
    }
}

// Get the currently selected option index
// 0 for "Restart" and 1 for "Exit"
int GameOverScreen::getSelectedOption() const {
    return selectedOptionIndex;
}