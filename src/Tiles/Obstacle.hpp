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

        sf::Sprite sprite;
        float x;
        float y;

    protected:
    private:
};

#endif /* !OBSTACLE_HPP_ */
