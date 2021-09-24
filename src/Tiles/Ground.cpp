/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Ground
*/

#include "Ground.hpp"

Ground::Ground(sf::Sprite &mSprite) : sprite(mSprite), x(0), y(0)
{
}

Ground::~Ground()
{
}

sf::Sprite &Ground::getSprite()
{
    return sprite;
}

void Ground::setSprite(sf::Sprite newSprite)
{
    sprite = newSprite;
}

void Ground::setDecal(float newDecalX, float newDecalY)
{
    decalX = newDecalX;
    decalY = newDecalY;
    sprite.setPosition(x + decalX, y + decalY);
}

void Ground::setPos(float newX, float newY)
{
    x = newX;
    y = newY;
    sprite.setPosition(x + decalX, y + decalY);
}