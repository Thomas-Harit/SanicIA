/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Ground
*/

#include "Ground.hpp"

Ground::Ground(sf::Sprite &mSprite) : sprite(mSprite)
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

void Ground::setPos(float newX, float newY)
{
    x = newX;
    y = newY;
}