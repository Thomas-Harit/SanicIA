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
        Obstacle();
        ~Obstacle();

        void Draw(const sf::RenderWindow &window);

        sf::Sprite &getSprite();
        void setSprite(sf::Sprite newSprite);

        sf::Sprite sprite;
        float x;
        float y;

    protected:
    private:
};

#endif /* !OBSTACLE_HPP_ */
