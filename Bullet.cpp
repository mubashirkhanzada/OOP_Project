#include "Bullet.h"

// Default constructor for the Bullet class
Bullet::Bullet()
{
    // No initialization required for the default constructor
}

// Parameterized constructor to initialize the Bullet object
Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
    // Set the texture for the bullet's shape
    this->shape.setTexture(*texture);

    // Set the initial position of the bullet
    this->shape.setPosition(pos_x, pos_y);

    // Set the direction vector for the bullet's movement
    this->direction.x = dir_x;
    this->direction.y = dir_y;

    // Set the movement speed of the bullet
    this->movementSpeed = movement_speed;
}

// Destructor for the Bullet class
Bullet::~Bullet()
{
    // No dynamically allocated resources to clean up
}

// Function to get the global bounds of the bullet's shape
const sf::FloatRect Bullet::getBounds() const
{
    // Returns the bounding box of the bullet's shape (used for collision detection)
    return this->shape.getGlobalBounds();
}

// Update the bullet's position based on its direction and movement speed
void Bullet::update()
{
    // Move the bullet in the direction multiplied by its speed
    this->shape.move(this->movementSpeed * this->direction);
}

// Render the bullet on the target (e.g., window or render texture)
void Bullet::render(sf::RenderTarget* target)
{
    // Draw the bullet's shape onto the specified render target
    target->draw(this->shape);
}