/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Ground
*/

#ifndef Ground_HPP_
#define Ground_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ground {
    public:
        Ground(sf::Sprite &mSprite);
        ~Ground();
        
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

#endif /* !Ground_HPP_ */
