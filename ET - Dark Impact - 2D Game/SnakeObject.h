/*Do wyrzucenia.*/

#pragma once
#include "_VirtualObject.h"


class SnakeObject
	: public virtual _VirtualObject
{

public:
	SnakeObject(const char* texturesheet, int x, int y);
	~SnakeObject();
	void Update();
	void Render();

	// ZARZ¥DZANIE WÊ¯EM
	void InitializeTextures(); //Inicjalizuj grafiki
	void InitializeSnake();	// Inicjalizuj Wê¿a
	void MoveWithSnake();	// Zarz¹dzaj Wê¿em
	void SetSnakeSpeed();	// Ustaw prêdkoœæ Wê¿a
	void IsGameOver();		// SprawdŸ warunki koñca
	void HandleSnakeGraphics(); // Zarz¹dzaj grafikami Wê¿a
	void HandleKeyboard();	// Obs³uguj input klawiatury
	void FeedingSnake();	// Nakarm Wê¿a
	// ZARZ¥DZANIE WÊ¯EM



	// TABLICA
	void LoadMapFromVariable(int arr[29][41]);
	void DrawMap(int arr[29][41]);
	void AppleTree(int arr[29][41]);
	// TABLICA



	//ZARZ¥DZENIE WÊ¯EM
	int width, height;
	char input, previnput; //poruszanie
	int speed, delay; //szybkoœæ
	int size; //rozmiar
	int snakeX[100], snakeY[100], tempX[100], tempY[100];

	int item_count;
	int apple_count, golden_apple_count, crow_count;
	std::vector<int> itemX, itemY;
	int tailX, tailY;
	int points;



	//TABLICA
	int map[29][45];
	int interval1, interval2, interval3;
	SDL_Rect srcRect, destRect;
	SDL_Texture* blank;
	SDL_Texture* apple;
	SDL_Texture* pixelsnake;
	SDL_Texture* pixelapple;
	SDL_Texture* pixelgoldenapple;
	SDL_Texture* pixelraven;


	//Czêœci Snake'a
	SDL_Texture* snake_head_down;
	SDL_Texture* snake_head_up;
	SDL_Texture* snake_head_right;
	SDL_Texture* snake_head_left;

	SDL_Texture* snake_tail_down;
	SDL_Texture* snake_tail_up;
	SDL_Texture* snake_tail_right;
	SDL_Texture* snake_tail_left;

	SDL_Texture* snake_turn_1;
	SDL_Texture* snake_turn_2;
	SDL_Texture* snake_turn_3;
	SDL_Texture* snake_turn_4;

	SDL_Texture* snake_body_vert;
	SDL_Texture* snake_body_horizon;

};