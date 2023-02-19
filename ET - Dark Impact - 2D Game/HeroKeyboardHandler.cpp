#include "HeroKeyboardHandler.h"

HeroKeyboardHandler::HeroKeyboardHandler()
{
    pointInGame.x = 640;
    pointInGame.y = 448;
    inputFromKeyboard = ' ';
    textureNumber = 0;
    speedShift = 6;
}

//Obs³uga klawiatury
void HeroKeyboardHandler::HandleKeyboard()
{
    int speed = 6;
    int hero_x_velocity = 0;
    int hero_y_velocity = 0;
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_RETURN])
        printf("<RETURN> is pressed.\n");

    if (state[SDL_SCANCODE_ESCAPE])
        Game::isGameRunning = false;

    if (state[SDL_SCANCODE_LSHIFT])
        speed = speed * 2;

    if (state[SDL_SCANCODE_LCTRL])
        speed = speed / 2;

    if (state[SDL_SCANCODE_W])
    {
        hero_y_velocity = -speedShift;
    }

    if (state[SDL_SCANCODE_A])
    {
        hero_x_velocity = -speedShift;
        textureNumber = 1;
    }

    if (state[SDL_SCANCODE_S])
    {
        hero_y_velocity = speedShift;
    }

    if (state[SDL_SCANCODE_D])
    {
        hero_x_velocity = speedShift;
        textureNumber = 0;
    }

    if (state[SDL_SCANCODE_F])
    {
        inputFromKeyboard = 'f';
    }

    pointInGame.x += hero_x_velocity;
    pointInGame.y += hero_y_velocity;
    speedShift = speed;
}