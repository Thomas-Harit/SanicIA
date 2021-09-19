
#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <map>

class Game {
public: 
    Game(void);
    ~Game(void) = default;

    void tick(void);
    void importSprite(const std::string &filepath, const std::string &name);
    void importSprite(const std::string &filepath, const std::string &name, float x, float y);
    void draw(const std::string &name);

    sf::RenderWindow window;

private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Sprite> sprites;
};

#endif /* GAME_HPP_ */
