
#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <map>

#include "IA/IA.hpp"
#include "Tiles/Ground.hpp"
#include "Tiles/Obstacle.hpp"

class Game {
public: 
    Game();
    ~Game(void);

    void Draw(void);
    void Loop(void);
    void Event(void);

    void MapReader(const std::string &filename);
    void placeGround(int x, int y, char var);
    void placeObstacles(int x, int y, char var);

    sf::RenderWindow Window;

private:
    std::map<std::string, sf::Texture> textures;
    std::vector<Ground> grounds;
    std::vector<Obstacle> obstacles;
    IA Sanic;
};

#endif /* GAME_HPP_ */
