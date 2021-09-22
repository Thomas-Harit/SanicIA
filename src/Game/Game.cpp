/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** Game
*/

#include "Game.hpp"
#include <iostream>
#include <fstream>

Game::Game()
{
    Window.setFramerateLimit(60);
    textures["tileset"].loadFromFile("./sprites/Tileset.png");
    textures["sanic_run"].loadFromFile("./sprites/sanic_run.png");
}

Game::~Game()
{
    if (Window.isOpen())
        Window.close();
}

void Game::Draw()
{
    Window.clear(sf::Color::White);
    for (Ground it : grounds) {
        Window.draw(it.getSprite());
    }
    for (Obstacle it : obstacles) {
        Window.draw(it.getSprite());
    }
}

void Game::Loop()
{
    while (Window.isOpen()) {
        this->Draw();
        this->Event();
    }
}

void Game::Event()
{
    sf::Event event;

    while (Window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            Window.close();
        }
    }
}

void Game::MapReader(const std::string &filename)
{
    std::ifstream filebuf(filename);
    std::string linebuf;
    int y = 0;

    while (filebuf.is_open() && getline(filebuf, linebuf)) {
        for (int x = 0; x < linebuf.size(); x += 1) {
            if (linebuf[x] >= '1' && linebuf[x] <= '4') {
                placeGround(x, y, linebuf[x]);
            } else if (linebuf[x] >= '5' && linebuf[x] <= '7') {
                placeObstacles(x, y , linebuf[x]);
            }
        }
        y += 1;
    }
}

void Game::placeGround(int x, int y, char var)
{
    static sf::Texture &tileset = textures["tileset"];
    sf::Sprite sprite(tileset);
    sf::IntRect rect;

    switch (var)
    {
        case '1':
            rect = sf::IntRect(1, 57, 30, 30);
            break;
        case '2':
            rect = sf::IntRect(1, 87, 30, 30);
            break;
        case '3':
            rect = sf::IntRect(161, 58, 30, 30);
            break;
        default:
            rect = sf::IntRect(161, 88, 30, 30);
            break;    
    }
    sprite.setTextureRect(rect);
    grounds.push_back(sprite);
    grounds.back().setPos(x * 30, y * 30);
}

void Game::placeObstacles(int x, int y, char var)
{
    static sf::Texture &tileset = textures["tileset"];
    sf::Sprite sprite(tileset);
    sf::IntRect rect;

    switch (var)
    {
        case '5':
            rect = sf::IntRect(480, 224, 32, 92);
            break;
        case '6':
            rect = sf::IntRect(576, 255, 96, 65);
            break;
        default:
            rect = sf::IntRect(704, 256, 96, 64);
            break;
    }
    sprite.setTextureRect(rect);
    obstacles.push_back(sprite);
    obstacles.back().setPos(x, y + rect.top - 30);
}