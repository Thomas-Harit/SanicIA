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
        Ground(sf::Texture &texture);
        ~Ground();

        void Draw(const sf::RenderWindow &window);
        
        sf::Sprite &getSprite();
        void setSprite(sf::Sprite newSprite);

        //sf::Texture &texture;
        sf::Sprite sprite;
        float x;
        float y;

    protected:
    private:
};

#endif /* !Ground_HPP_ */
