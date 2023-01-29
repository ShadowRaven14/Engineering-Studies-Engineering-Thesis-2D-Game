#include "KeyboardManager.h"

//Obs³uga klawiatury
CoordinatesOfHero KeyboardManager::HandleKeyboard(CoordinatesOfHero cordsOfObject)
{
    int speed = 4;
    int hero_x_velocity = 0;
    int hero_y_velocity = 0;
    const Uint8* state = SDL_GetKeyboardState(NULL);

    //INTERAKCJE
    if (Game::mainGameEvent.type == SDL_KEYDOWN)
    {
        //INTERAKCJA Z INNYM OBIEKTEM
        if (Game::mainGameEvent.key.keysym.sym == SDLK_f)
        {
            cordsOfObject.previnput = cordsOfObject.input;
            cordsOfObject.input = 'f';
        }
        //WYJŒCIE Z GRY
        if (Game::mainGameEvent.key.keysym.sym == SDLK_ESCAPE)
        {
            Game::isGameRunning = false;
        }
    }

    if (state[SDL_SCANCODE_RETURN])
        printf("<RETURN> is pressed.\n");

    if (state[SDL_SCANCODE_LSHIFT])
        speed = speed * 2;

    if (state[SDL_SCANCODE_W])
        hero_y_velocity = -speed;

    if (state[SDL_SCANCODE_A])
        hero_x_velocity = -speed;

    if (state[SDL_SCANCODE_S])
        hero_y_velocity = speed;

    if (state[SDL_SCANCODE_D])
        hero_x_velocity = speed;
        
    
    
    cordsOfObject.point.x += hero_x_velocity;
    cordsOfObject.point.y += hero_y_velocity;
    return cordsOfObject;
}