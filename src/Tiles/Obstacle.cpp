/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Obstacle
*/

#include "Tiles/Obstacle.hpp"

Obstacle::Obstacle(sf::Sprite &mSprite) : sprite(mSprite), x(0), y(0)
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

void Obstacle::setDecal(float newDecalX, float newDecalY)
{
    decalX = newDecalX;
    decalY = newDecalY;
    sprite.setPosition(x + decalX, y + decalY);
}

void Obstacle::setPos(float newX, float newY)
{
    x = newX;
    y = newY;
    sprite.setPosition(x + decalX, y + decalY);
}