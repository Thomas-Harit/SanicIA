/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_

#include "SFML/Graphics.hpp"
#include "Clock/Clock.hpp"
#include "Tiles/Obstacle.hpp"
#include "Tiles/Ground.hpp"
#include <memory>

class IA {
    public:
        IA();
        IA(const IA &other);
        ~IA() = default;

        void Loop();

        void GoFaster();
        void GoSlower();
        void Jump();

        void Gravity(void);
        void ResolveCollision(sf::FloatRect inter);
        void Collision(void);
        void Move(void);

        void Animation();
        void AnimationRunning();
        void AnimationInTheAir();

        bool IsThereAHole(float distance);
        bool IsThereAnObstacle(float distance);

        void updateMap(std::vector<Obstacle> newObstacles, std::vector<Ground> newGrounds);
        void updateTexture(sf::Texture newRunText, sf::Texture newJumpText, sf::Texture newStillText);

        float x;
        float y;
        sf::Sprite sprite;
        float speed;
        float gravity;
        float jumpHeight;

    protected:
    private:
        Clock clock;
        bool isJumping;
        bool isFalling;
        int AnimationState;
        sf::Vector2i velocity;
        sf::Texture run_text;
        sf::Texture jump_text;
        sf::Texture still_text;
        std::vector<Obstacle> obstacles;
        std::vector<Ground> grounds;
};

#endif /* !IA_HPP_ */
