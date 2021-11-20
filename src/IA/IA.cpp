/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** IA
*/

#include "IA.hpp"
#include <iostream>

IA::IA() : isJumping(false), isFalling(true), gravity(5), AnimationState(0), JumpingSpeed(5), JumpingHeight(0)
{
    this->sprite.setTexture(still_text, true);
}

IA::IA(const IA &other) : run_text(other.run_text), jump_text(other.jump_text), still_text(other.still_text),
                        gravity(other.gravity), velocity(other.velocity), AnimationState(other.AnimationState),
                        JumpingSpeed(other.JumpingSpeed), JumpingHeight(other.JumpingHeight)
{
    this->sprite.setTexture(still_text, true);
}

void IA::GoFaster()
{
    if (this->isFalling == false && this->isJumping == false && this->speed < 50) {
        this->speed += 2;
        if (this->speed > 50)
            this->speed = 50;
    }
}

void IA::GoSlower()
{
    if (this->isFalling == false && this->isJumping == false && this->speed > 0) {
        this->speed -= 5;
        if (this->speed < 0)
            this->speed = 0;
    }
}

void IA::Jump()
{
    if (this->isFalling == false && this->isJumping == false) {
        this->isJumping = true;
        if (this->speed > 10) {
            this->JumpingSpeed = this->speed / 10;
            this->JumpingHeight = this->sprite.getPosition().y - this->speed * 5;
        } else {
            this->JumpingSpeed = 5;
            this->JumpingHeight = this->sprite.getPosition().y - 100;
        }
    }
}

void IA::Falling()
{
    sf::FloatRect rect;

    if (this->isJumping == false) {
        this->isFalling = true;
        this->sprite.move(0, this->gravity);
        for (rect = this->Collision(); rect.width != 0 && rect.height != 0; rect = this->Collision()) {
            this->sprite.move(0, -1 * rect.height);
            this->isFalling = false;
            std::cout << "MOVE UP : " << rect.height << std::endl;
        }
    }
}

void IA::Jumping()
{
    sf::FloatRect rect;

    if (this->isJumping == true) {
        std::cout << this->JumpingHeight << std::endl;
        this->JumpingSpeed += this->JumpingSpeed * 0.1;
        this->sprite.move(0, -1 * this->JumpingSpeed);
        for (rect = this->Collision(); rect.width != 0 && rect.height != 0; rect = this->Collision()) {
            this->sprite.move(0, rect.height);
            this->isJumping = false;
            this->JumpingSpeed = 5;
        }
        if (this->sprite.getPosition().y <= this->JumpingHeight) {
            this->isJumping = false;
            this->JumpingSpeed = 5;
        }
    }
}

sf::FloatRect IA::Collision(void)
{
    sf::FloatRect inter = {0, 0, 0, 0};
    sf::FloatRect SanicRect = this->sprite.getGlobalBounds();
    sf::FloatRect ObjRect;

    for (auto it : this->obstacles) {
        ObjRect = it.getSprite().getGlobalBounds();
        if (ObjRect.intersects(SanicRect, inter)) {
            return inter;
        }
    }
    for (auto it : this->grounds) {
        ObjRect = it.getSprite().getGlobalBounds();
        if (ObjRect.intersects(SanicRect, inter)) {
            return inter;
        }
    }
    return inter;
}

void IA::Run(void)
{
    sf::FloatRect rect;

    this->sprite.move(this->speed, 0);
    for (rect = this->Collision(); rect.width != 0 && rect.height != 0; rect = this->Collision()) {
        this->sprite.move(-1 * rect.width, 0);
        this->speed = 0;
    }
}

void IA::Animation()
{
    if (this->isFalling || this->isJumping) {
        this->AnimationInTheAir();
        this->AnimationState = 1;
    } else if (this->speed > 0) {
        this->AnimationRunning();
        this->AnimationState = 2;
    } else {
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