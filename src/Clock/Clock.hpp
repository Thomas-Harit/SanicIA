/*
** EPITECH PROJECT, 2021
** B-CCP-400-BDX-4-1-theplazza-etienne1.delrieux
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>

class Clock {
    public:
        Clock();
        ~Clock();

        // reset the clock time
        void reset(void);

        // get the time elapsed since declaration or last reset
        float time(void);

    protected:
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

#endif /* !CLOCK_HPP_ */
