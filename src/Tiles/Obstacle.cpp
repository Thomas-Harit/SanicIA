/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Obstacle
*/

#include "Obstacle.hpp"

Obstacle::Obstacle(sf::Sprite &mSprite) : sprite(mSprite)
{
}

Obstacle::~Obstacle()
{
}

sf::Sprite &Obstacle::getSprite()
{
    return sprite;
}

void Obstacle::setSprite(sf::Sprite newSprite)
{
    sprite = newSprite;
}

void Obstacle::setPos(float newX, float newY)
{
    x = newX;
    y = newY;
}