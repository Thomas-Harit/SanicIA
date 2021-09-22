/*
** EPITECH PROJECT, 2021
** atelierJPO
** File description:
** main
*/

#include "Game/Game.hpp"

int main(int ac, char **av)
{
    Game game;

    if (ac >= 2) {
        game.MapReader(av[1]);
        game.Loop();
    }
    return 0;
}