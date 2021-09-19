
#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <map>

#include "IA.hpp"

class Game {
public: 
    Game(void);
    ~Game(void) = default;

    void Draw(const std::string &name);
    void Loop(void);

    sf::RenderWindow Window;

private:
    std::map<std::string, sf::Texture> Textures;
    std::map<std::string, sf::Sprite> Sprites;
    IA Sonic;
};

#endif /* GAME_HPP_ */
