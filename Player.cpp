#include "Player.h"

// Initialize the player's variables
void Player::initVariables()
{
    this->movementSpeed = 2.f; // Sets the movement speed of the player

    this->attackCooldownMax = 10.f; // Maximum cooldown time for attacks
    this->attackCooldown = this->attackCooldownMax; // Start with the cooldown ready to attack

    this->hpMax = 400; // Set the maximum health points
    this->hp = this->hpMax; // Initialize current health points to maximum
}

// Load the texture for the player sprite
void Player::initTexture()
{
    // Load texture file and handle errors
    if (!this->texture.loadFromFile("Textures/chicken.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
    }
}

// Initialize the player's sprite and set its texture
void Player::initSprite()
{
    // Set the loaded texture to the player's sprite
    this->sprite.setTexture(this->texture);

    // Scale the sprite to make it smaller
    this->sprite.scale(0.25f, 0.25f);
}

// Constructor for the Player class
Player::Player()
{
    this->initVariables(); // Initialize player-specific variables
    this->initTexture();   // Load the texture
    this->initSprite();    // Initialize and set up the sprite
}

// Destructor for the Player class
Player::~Player()
{
    // No dynamic memory to clean up
}

// Get the current position of the player sprite
const sf::Vector2f& Player::getPos() const
{
    return this->sprite.getPosition();
}

// Get the global bounds of the player sprite (used for collision detection)
const sf::FloatRect Player::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

// Get the current health points of the player
const int& Player::getHp() const
{
    return this->hp;
}

// Get the maximum health points of the player
const int& Player::getHpMax() const
{
    return this->hpMax;
}

// Set the position of the player sprite using an sf::Vector2f
void Player::setPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}

// Set the position of the player sprite using x and y coordinates
void Player::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

// Set the current health points of the player
void Player::setHp(const int hp)
{
    this->hp = hp;
}

// Reduce the player's health points by a given value
void Player::loseHp(const int value)
{
    this->hp -= value;
    // Ensure health does not drop below 0
    if (this->hp < 0)
        this->hp = 0;
}

// Move the player in a given direction
void Player::move(const float dirX, const float dirY)
{
    // Update the player's position based on the movement speed and direction
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

// Check if the player can attack (based on the cooldown timer)
const bool Player::canAttack()
{
    if (this->attackCooldown >= this->attackCooldownMax)
    {
        // Reset the cooldown timer after an attack
        this->attackCooldown = 0.f;
        return true;
    }

    return false;
}

// Update the attack cooldown timer
void Player::updateAttack()
{
    if (this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 0.5f; // Increment cooldown over time
}

// Update the player's state (called every frame)
void Player::update()
{
    this->updateAttack(); // Update the attack cooldown
}

// Render the player sprite on the given render target
void Player::render(sf::RenderTarget& target)
{
    target.draw(this->sprite); // Draw the player's sprite
}