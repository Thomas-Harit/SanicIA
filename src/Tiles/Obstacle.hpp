/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Obstacle
*/

#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Obstacle {
    public:
        Obstacle(sf::Sprite &mSprite);
        ~Obstacle();

        sf::Sprite &getSprite();
        void setSprite(sf::Sprite newSprite);

        void setPos(float newX, float newY);
        void setDecal(float newDecalX, float newDecalY);

        sf::Sprite sprite;
        float x;
        float y;
        float decalX;
        float decalY;

    protected:
    private:
};

#endif /* !OBSTACLE_HPP_ */
