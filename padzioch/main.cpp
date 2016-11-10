#include "SDL/SDL.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
SDL_Surface *screen = NULL;
SDL_Joystick *stick[32];
SDL_Event event;
int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    if (screen == NULL)
        exit(-1);
    if (SDL_NumJoysticks() < 1 || SDL_NumJoysticks() >= 32)
        exit(-1);
    for (int i=0; i<SDL_NumJoysticks(); i++) {
        stick[i] = SDL_JoystickOpen(i);
        if (stick[i] == NULL)
            exit(-1);
        std::cout << "Joystick " << i << std::endl;
        std::cout << " # Name \"" << SDL_JoystickName(i) << "\"" << std::endl;
        std::cout << " # Axes " << SDL_JoystickNumAxes(stick[i]) << std::endl;
        std::cout << " # Balls " << SDL_JoystickNumBalls(stick[i]) << std::endl;
        std::cout << " # Hats " << SDL_JoystickNumHats(stick[i]) << std::endl;
        std::cout << " # Buttons " << SDL_JoystickNumButtons(stick[i]) << std::endl;
    }
    bool quit = false;
    while (quit == false) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            if (event.type == SDL_JOYBUTTONDOWN) {
                for (int i=0; i<SDL_NumJoysticks(); i++) {
                    for (int j=0; j<SDL_JoystickNumButtons(stick[i]); j++) {
                        if (SDL_JoystickGetButton(stick[i], j)) {
                            std::cout << "Button " << i << ":" << j << std::endl;
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<SDL_NumJoysticks(); i++)
        SDL_JoystickClose(stick[i]);
    SDL_Quit();
    return 0;
}
