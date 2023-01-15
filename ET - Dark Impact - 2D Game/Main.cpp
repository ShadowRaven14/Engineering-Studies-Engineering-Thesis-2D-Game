#include "Game.h"
Game* mainGame = nullptr;


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    mainGame = new Game();
    mainGame->Init("MainGameWindow", 1312, 928, false);

    //const char* text = "Hi, this is my pixel game!";
    //TTF_Font* font = TTF_OpenFont("Fonts/pixel.fon", 25);
    //SDL_Color color = { 255, 255, 255 };
    //SDL_Surface* mainGameFontSurface =  TTF_RenderText_Solid(font, text, color);
    //SDL_Texture* mainGameFontTexture =  SDL_CreateTextureFromSurface(Game::mainGameRender, mainGameFontSurface);
    //int texW = 0;  int texH = 928;
    //SDL_QueryTexture(mainGameFontTexture, NULL, NULL, &texW, &texH);
    //SDL_Rect dstrect = { 0, 0, texW, texH };

    while (mainGame->Running())
    {
        frameStart = SDL_GetTicks();

        mainGame->HandleEvents();
        mainGame->Render();
        mainGame->Update();
        
        //Tu renderuj sta³y tekst.
        //SDL_RenderCopy(Game::mainGameRender, mainGameFontTexture, NULL, &dstrect);
        //SDL_RenderPresent(Game::mainGameRender);

        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        
    }

    mainGame->Clean();
    return 0;
}


//#include <SDL.h>
//#include <SDL_ttf.h>
//#include <iostream>
//
//int main(int argc, char** argv)
//{
//    bool quit = false;
//    SDL_Event event;
//
//    SDL_Init(SDL_INIT_VIDEO);
//
//    SDL_Window* window = SDL_CreateWindow("SDL_ttf in SDL2",
//        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
//        480, 0);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
//
//    TTF_Init();
//
//    const char* text = "Hi, this is my pixel game!";
//
//    TTF_Font* font = TTF_OpenFont("Fonts/pixel.fon", 25);
//    SDL_Color color = { 255, 255, 255 };
//    SDL_Surface* mainGameFontSurface = 
//        TTF_RenderText_Solid(font, 
//            text, color);
//    SDL_Texture* mainGameFontTexture = 
//        SDL_CreateTextureFromSurface(renderer, mainGameFontSurface);
//
//    int texW = 0;
//    int texH = 0;
//    SDL_QueryTexture(mainGameFontTexture, NULL, NULL, &texW, &texH);
//    SDL_Rect dstrect = { 0, 0, texW, texH };
//    
//
//    while (!quit)
//    {
//        SDL_WaitEvent(&event);
//        
//        switch (event.type)
//        {
//        case SDL_QUIT:
//            quit = true;
//            break;
//        }
//        //SDL_RenderCopy(renderer, mainGameFontTexture, NULL, NULL);
//        SDL_RenderCopy(renderer, mainGameFontTexture, NULL, &dstrect);
//        SDL_RenderPresent(renderer);
//
//        
//    }
//
//    TTF_CloseFont(font);
//    TTF_Quit();
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    return 0;
//}