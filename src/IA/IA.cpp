/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** IA
*/

#include "IA.hpp"
#include <iostream>

IA::IA() : isJumping(false), isFalling(false), gravity(3), velocity({0, 0}), AnimationState(0)
{
    this->sprite.setTexture(still_text, true);
}

IA::IA(const IA &other) : run_text(other.run_text), jump_text(other.jump_text), still_text(other.still_text), gravity(other.gravity), velocity(other.velocity), AnimationState(other.AnimationState)
{
    this->sprite.setTexture(still_text, true);
}

void IA::GoFaster()
{
    if (velocity.y >= -0.5 && this->velocity.y <= 0.5) {
        velocity.x += 10;
    }
}

void IA::GoSlower()
{
    //if (velocity.x >= 1) {
    //    velocity.x -= 1;
    //} else {
    //    velocity.x = 0;
    //}
}

void IA::Jump()
{
}

void IA::Gravity()
{
    velocity.y += this->gravity;
    if (velocity.y > this->gravity) {
        velocity.y = this->gravity;
    }
}

void IA::ResolveCollision(sf::FloatRect inter)
{
    float scale = 0;

    std::cout << "*** COLLISION ***" << std::endl;
    std::cout << "Velocity : " << this->velocity.x << " | " << this->velocity.y << std::endl;
    if (this->velocity.x != 0 && this->velocity.y != 0 && inter.width / std::abs(this->velocity.x) >= inter.height / std::abs(this->velocity.y)) {
        scale = inter.height / std::abs(this->velocity.y);
    } else if (this->velocity.x != 0) {
        scale = inter.width / std::abs(this->velocity.x);
    } else if (this->velocity.y != 0) {
        scale = inter.height / std::abs(this->velocity.y);
    } else if (inter.height > inter.width) {
        this->velocity.x = -1 * inter.width;
    } else {
        this->velocity.y = -1 * inter.height;
    }
    this->velocity.x -= this->velocity.x * scale;
    this->velocity.y -= this->velocity.y * scale;
    std::cout << "INTER.WIDTH = " << inter.width << " | INTER.HEIGHT = " << inter.height << std::endl;
    std::cout << "FORCE.X = " << this->velocity.x * scale << " | FORCE.Y = " << this->velocity.y * scale << std::endl;
    std::cout << "New Velocity : " << this->velocity.x << " | " << this->velocity.y << std::endl << std::endl;
}

void IA::Collision(void)
{
    sf::FloatRect inter;
    sf::FloatRect SanicRect = this->sprite.getGlobalBounds();
    sf::FloatRect ObjRect;

    SanicRect.left += this->velocity.x;
    SanicRect.top += this->velocity.y;
    for (auto it : this->obstacles) {
        ObjRect = it.getSprite().getGlobalBounds();
        if (ObjRect.intersects(SanicRect, inter)) {
            this->ResolveCollision(inter);
            SanicRect = this->sprite.getGlobalBounds();
            SanicRect.left += this->velocity.x;
            SanicRect.top += this->velocity.y;
        }
    }
    for (auto it : this->grounds) {
        ObjRect = it.getSprite().getGlobalBounds();
        if (ObjRect.intersects(SanicRect, inter)) {
            this->ResolveCollision(inter);
            SanicRect = this->sprite.getGlobalBounds();
            SanicRect.left += this->velocity.x;
            SanicRect.top += this->velocity.y;
        }
    }
}

void IA::Move(void)
{
    this->sprite.move(this->velocity.x, this->velocity.y);
}

void IA::Animation()
{
    if (this->velocity.y < -0.5 || this->velocity.y > 0.5) {
        this->AnimationInTheAir();
        this->AnimationState = 1;
    } else if (this->velocity.x != 0) {
        this->AnimationRunning();
        this->AnimationState = 2;
    } else if (this->AnimationState != 0) {
        this->sprite.setTexture(still_text, true);
        this->AnimationState = 0;
    }
}

void IA::AnimationRunning()
{
    sf::IntRect rect(0, 0, 48, 36);
    static int i = 0;
    float timing = 0.1;

    if (this->AnimationState != 2) {
        this->sprite.setTexture(run_text, true);
        i = 0;
        this->sprite.setTextureRect(rect);
        clock.reset();
    }
    if (speed > 0)
        timing = 0.1 / speed;
    else
        timing = 0.1;
    if (clock.time() >= timing) {
        rect.left = i * 48;
        if (i >= 3)
            i = 0;
        this->sprite.setTextureRect(rect);
        clock.reset();
        i += 1;
    }
}

void IA::AnimationInTheAir()
{
    sf::IntRect rect(0, 0, 34, 35);
    static int i = 0;
    float timing = 0.1;

    if (this->AnimationState != 1) {
        this->sprite.setTexture(jump_text, true);
        i = 0;
        this->sprite.setTextureRect(rect);
        clock.reset();
    }
    if (speed > 0)
        timing = 0.1 / speed;
    else
        timing = 0.1;
    if (clock.time() >= timing) {
        rect.left = i * 34;
        if (i >= 3)
            i = 0;
        this->sprite.setTextureRect(rect);
        clock.reset();
        i += 1;
    }
}

bool IA::IsThereAHole(float distance)
{
    sf::FloatRect rect_1 = this->sprite.getGlobalBounds();
    sf::FloatRect rect_2;

    rect_1.top += rect_1.height;
    rect_1.left += distance;
    for (auto it : grounds) {
        rect_2 = it.sprite.getGlobalBounds();
        if (rect_1.intersects(rect_2) == true)
            return false;
    }
    return true;
}

bool IA::IsThereAnObstacle(float distance)
{
    sf::FloatRect rect_1 = this->sprite.getGlobalBounds();
    sf::FloatRect rect_2;

    rect_1.left += distance;
    for (auto it : obstacles) {
        rect_2 = it.sprite.getGlobalBounds();
        if (rect_1.intersects(rect_2) == true)
            return true;
    }
    return false;
}

void IA::updateMap(std::vector<Obstacle> newObstacles, std::vector<Ground> newGrounds)
{
    obstacles = newObstacles;
    grounds = newGrounds;
}

void IA::updateTexture(sf::Texture newRunText, sf::Texture newJumpText, sf::Texture newStillText)
{
    still_text = newStillText;
    run_text = newRunText;
    jump_text = newJumpText;
    sprite.setTexture(still_text, true);
}