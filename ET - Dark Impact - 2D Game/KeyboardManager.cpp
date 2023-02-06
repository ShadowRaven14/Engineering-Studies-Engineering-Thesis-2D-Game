#include "KeyboardManager.h"

//Obs³uga klawiatury
CoordinatesOfHero KeyboardManager::HandleKeyboard(CoordinatesOfHero cordsOfHero)
{
    int speed = 4;
    int hero_x_velocity = 0;
    int hero_y_velocity = 0;
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_RETURN])
        printf("<RETURN> is pressed.\n");

    if (state[SDL_SCANCODE_ESCAPE])
        Game::isGameRunning = false;

    if (state[SDL_SCANCODE_LSHIFT])
        speed = speed * 2;

    if (state[SDL_SCANCODE_W])
    {
        hero_y_velocity = -speed;
    }

    if (state[SDL_SCANCODE_A])
    {
        hero_x_velocity = -speed;
        cordsOfHero.ntexture = 1;
    }

    if (state[SDL_SCANCODE_S])
    {
        hero_y_velocity = speed;
    }

    if (state[SDL_SCANCODE_D])
    {
        hero_x_velocity = speed;
        cordsOfHero.ntexture = 0;
    }

    if (state[SDL_SCANCODE_F])
    {
        cordsOfHero.input = 'f';
    }


    cordsOfHero.point.x += hero_x_velocity;
    cordsOfHero.point.y += hero_y_velocity;
    return cordsOfHero;
}