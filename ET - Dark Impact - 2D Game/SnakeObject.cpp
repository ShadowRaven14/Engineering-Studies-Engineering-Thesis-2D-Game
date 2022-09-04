#include "SnakeObject.h"
#include "TextureManager.h"


int Level[29][41] =
{
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},

	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,},
	{0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,}
};


//TABLICA WÊ¯A
void SnakeObject::LoadMap(int arr[29][41])
{
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void SnakeObject::DrawMap(int arr[29][41])
{
	int type = 0;
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			type = arr[row][column];
			//type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(blank, src, dest);
				break;

			case 1:
				TextureManager::Draw(pixelsnake, src, dest);
				break;

			case 2:
				TextureManager::Draw(pixelapple, src, dest);
				break;

			case 3:
				TextureManager::Draw(pixelgoldenapple, src, dest);
				break;

			case 4:
				TextureManager::Draw(pixelraven, src, dest);
				break;


				//g³owa
			case 11:
				TextureManager::Draw(snake_head_down, src, dest);
				break;

			case 12:
				TextureManager::Draw(snake_head_up, src, dest);
				break;

			case 13:
				TextureManager::Draw(snake_head_right, src, dest);
				break;

			case 14:
				TextureManager::Draw(snake_head_left, src, dest);
				break;


				//ogon
			case 21:
				TextureManager::Draw(snake_tail_down, src, dest);
				break;

			case 22:
				TextureManager::Draw(snake_tail_up, src, dest);
				break;

			case 23:
				TextureManager::Draw(snake_tail_right, src, dest);
				break;

			case 24:
				TextureManager::Draw(snake_tail_left, src, dest);
				break;


				//skrêty
			case 31:
				TextureManager::Draw(snake_turn_1, src, dest);
				break;

			case 32:
				TextureManager::Draw(snake_turn_2, src, dest);
				break;

			case 33:
				TextureManager::Draw(snake_turn_3, src, dest);
				break;

			case 34:
				TextureManager::Draw(snake_turn_4, src, dest);
				break;


				//proste cia³o
			case 41:
				TextureManager::Draw(snake_body_vert, src, dest);
				break;

			case 42:
				TextureManager::Draw(snake_body_horizon, src, dest);
				break;


			default:
				TextureManager::Draw(blank, src, dest);
				break;
			}
		}
	}
}

void SnakeObject::InitializeTextures()
{
	blank = TextureManager::LoadTexture("Assets/blank.png");
	apple = TextureManager::LoadTexture("Assets/apple.png");

	//pliki dodatków
	pixelapple = TextureManager::LoadTexture("Assets/apple.png");
	pixelgoldenapple = TextureManager::LoadTexture("Assets/apple_golden1.png");
	pixelraven = TextureManager::LoadTexture("Assets/crow1.png");
	pixelsnake = TextureManager::LoadTexture("Assets/pix_green.png");

	//Pliki wê¿a
	snake_head_down = TextureManager::LoadTexture("Assets/head_down.png");
	snake_head_up = TextureManager::LoadTexture("Assets/head_up.png");
	snake_head_right = TextureManager::LoadTexture("Assets/head_right.png");
	snake_head_left = TextureManager::LoadTexture("Assets/head_left.png");

	snake_tail_down = TextureManager::LoadTexture("Assets/tail_down.png");
	snake_tail_up = TextureManager::LoadTexture("Assets/tail_up.png");
	snake_tail_right = TextureManager::LoadTexture("Assets/tail_right.png");
	snake_tail_left = TextureManager::LoadTexture("Assets/tail_left.png");

	snake_turn_1 = TextureManager::LoadTexture("Assets/turn1.png");
	snake_turn_2 = TextureManager::LoadTexture("Assets/turn2.png");
	snake_turn_3 = TextureManager::LoadTexture("Assets/turn3.png");
	snake_turn_4 = TextureManager::LoadTexture("Assets/turn4.png");

	snake_body_vert = TextureManager::LoadTexture("Assets/body_vert.png");
	snake_body_horizon = TextureManager::LoadTexture("Assets/body_horizon.png");
}

//TABLICA WÊ¯A


//KONTRUKTOR
SnakeObject::SnakeObject(const char* texturesheet, int x, int y)
{
	//ZARZ¥DZANIE WÊ¯EM
	std::cout << "Snake utworzony" << std::endl;
	width = 41, height = 31;
	input = 's', previnput = 's';
	speed = 4; delay = 120;
	rozmiar = 3; punkty = 0;
	item_count = 0;
	apple_count = 0; golden_apple_count = 0; crow_count = 0;

	//TABLICA
	std::cout << "Tablica dla Snake utworzona" << std::endl;
	InitializeTextures();
	LoadMap(Level);
	interval1 = 0; interval2 = 0; interval3 = 0;
	src.h = 64; src.w = 64;
	src.x = 0; src.y = 0;
	dest.h = src.h / 2; dest.w = src.w / 2;


	//ZARZ¥DZNIE WÊ¯EM
	InitializeSnake();
}


//UPDATE
void SnakeObject::Update()
{
	interval1 = interval1 + 5;
	interval2 = interval2 + 5;
	interval3 = interval3 + 5;
	MoveWithSnake();

	//AppleTree(Level);
}

//RENDER
void SnakeObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	DrawMap(Level);
}



//ZARZ¥DZANIE WÊ¯EM
void SnakeObject::InitializeSnake()
{
	// Wymiarowanie Wê¿a
	snakeX[0] = width / 2;	snakeY[0] = (height / 4) + 1;
	snakeX[1] = width / 2;	snakeY[1] = (height / 4) + 0;
	snakeX[2] = width / 2;	snakeY[2] = (height / 4) - 1;

	// Wyzerowanie czêœci Wê¿a
	for (int i = 3; i < 100; i++)
	{
		snakeX[i] = NULL;
		snakeY[i] = NULL;
	}

	// Umieszczenie Wê¿a na planszy
	for (int i = 0; i < rozmiar; i++)
		Level[snakeY[i]][snakeX[i]] = 1;
}


void SnakeObject::MoveWithSnake()
{

	// Prêdkoœæ Wê¿a
	SetSnakeSpeed();

	// Dodawanie œladów ogona
	tailY = snakeY[rozmiar - 1];
	tailX = snakeX[rozmiar - 1];

	// Usuwanie œladów po ogonie
	Level[tailY][tailX] = '0';

	// Karmienie i powiêkszanie wê¿a
	FeedingSnake();

	// Kopiowanie Wê¿a do tablicy temp
	for (int i = 0; i < rozmiar - 1; i++)
	{
		tempX[i + 1] = snakeX[i];	// Kopiowanie wartoœci y
		tempY[i + 1] = snakeY[i];	// Kopiowanie wartoœci x
	}

	// Kopiowanie g³owy Wê¿a
	tempX[0] = snakeX[0];
	tempY[0] = snakeY[0];

	// Kopiowanie z tablicy temp
	for (int i = 0; i < rozmiar; i++)
	{
		snakeX[i] = tempX[i];						// Kopiowanie wartoœci Y
		snakeY[i] = tempY[i];						// Kopiowanie wartoœci X
	}

	// Obs³uguj input z klawiatury
	HandleKeyboard();

	// OBS£UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (previnput == 's')
	{
		snakeY[0] += 1;			// Zestaw g³ów na nowej pozycji
		if (input == 'a')		// IdŸ w lewo
			previnput = 'a';
		else if (input == 'd')	// IdŸ w prawo
			previnput = 'd';
	}
	// WHILE MOVING UP
	else if (previnput == 'w')
	{
		snakeY[0] -= 1;			// Zestaw g³ów na nowej pozycji
		if (input == 'a')		// IdŸ w lewo
			previnput = 'a';
		else if (input == 'd')	// IdŸ w prawo
			previnput = 'd';
	}
	// WHILE MOVING RIGHT
	else if (previnput == 'd')
	{
		snakeX[0] += 1;			// Zestaw g³ów na nowej pozycji
		if (input == 'w')		// IdŸ w górê
			previnput = 'w';
		else if (input == 's')	// IdŸ w dó³
			previnput = 's';
	}
	// WHILE MOVING LEFT
	else if (previnput == 'a')
	{
		snakeX[0] -= 1;			// Zestaw g³ów na nowej pozycji
		if (input == 'w')		// IdŸ w góre
			previnput = 'w';
		else if (input == 's')	// IdŸ w dó³
			previnput = 's';
	}


	// Rysowanie i zmiana pozycji Wê¿a		
	for (int i = 0; i < rozmiar; i++)
	{
		// Jeœli wyjdzie poza mapê
		if (snakeY[i] < 0 || snakeY[i] > 28 || snakeX[i] < 0 || snakeX[i]>40)
		{
			snakeY[i] = 15;
			snakeX[i] = 20;
			//return;
		}

		// Zbieranie jab³ek
		if (Level[snakeY[i]][snakeX[i]] == 2)
		{
			rozmiar++;
			punkty = punkty + 100;
			//cout << "Zdobyto jab³ko, aktualny wynik: " << punkty << endl;
			apple_count--;
		}

		// Zbieranie jab³ek
		if (Level[snakeY[i]][snakeX[i]] == 3)
		{
			rozmiar = rozmiar + 3;
			punkty = punkty + 501;
			//cout << "Zdobyto z³ote jab³ko, aktualny wynik: " << punkty << endl;
			golden_apple_count--;
		}

		// Zbieranie jab³ek
		if (Level[snakeY[i]][snakeX[i]] == 4)
		{
			punkty = punkty - 300;
			//cout << "Wpadniêto na Kruka, aktualny wynik: " << punkty << endl;
			crow_count--;
		}



		HandleSnakeGraphics();


		//cout << " Pozycja Snake  " << " snakeY =" << snakeY[i] << " snakeX =" << snakeX[i] << " gdzie i = " << i << endl;
	}
}

//USTAW PRÊDKOŒÆ WÊ¯A
void SnakeObject::SetSnakeSpeed()
{
	SDL_Delay(delay);
}

//USTAW PRÊDKOŒÆ WÊ¯A
void SnakeObject::IsGameOver()
{

}

void SnakeObject::HandleSnakeGraphics()
{
	//Rysowanie wê¿a
	for (int i = 0; i < rozmiar; i++)
	{
		//G£OWA
		if (i == 0)
		{
			if (input == 's') Level[snakeY[i]][snakeX[i]] = 11;
			if (input == 'w') Level[snakeY[i]][snakeX[i]] = 12;
			if (input == 'd') Level[snakeY[i]][snakeX[i]] = 13;
			if (input == 'a') Level[snakeY[i]][snakeX[i]] = 14;
		}

		//OGON
		if (i == (rozmiar - 1))
		{

			if (Level[snakeY[rozmiar - 2]][snakeX[rozmiar - 2]] == 41)
			{
				if (Level[snakeY[0]][snakeX[0]] == 11)
				{
					Level[snakeY[i]][snakeX[i]] = 21;
				}

				if (Level[snakeY[0]][snakeX[0]] == 12)
				{
					Level[snakeY[i]][snakeX[i]] = 22;
				}

				if (Level[snakeY[0]][snakeX[0]] == 13)
				{
					Level[snakeY[i]][snakeX[i]] = 23;
				}

				if (Level[snakeY[0]][snakeX[0]] == 14)
				{
					Level[snakeY[i]][snakeX[i]] = 24;
				}


			}

			if (Level[snakeY[rozmiar - 2]][snakeX[rozmiar - 2]] == 42)
			{
				if (Level[snakeY[0]][snakeX[0]] == 13)
				{
					Level[snakeY[i]][snakeX[i]] = 23;
				}

				if (Level[snakeY[0]][snakeX[0]] == 14)
				{
					Level[snakeY[i]][snakeX[i]] = 24;
				}

				if (Level[snakeY[0]][snakeX[0]] == 11)
				{
					Level[snakeY[i]][snakeX[i]] = 21;
				}

				if (Level[snakeY[0]][snakeX[0]] == 12)
				{
					Level[snakeY[i]][snakeX[i]] = 22;
				}
			}

		}

		else
		{

			//NORMALNE
			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 11
				|| Level[snakeY[i - 1]][snakeX[i - 1]] == 12
				)
				Level[snakeY[i]][snakeX[i]] = 41;

			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 13
				|| Level[snakeY[i - 1]][snakeX[i - 1]] == 14
				)
				Level[snakeY[i]][snakeX[i]] = 42;


			//SKRÊTY
			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 41
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 42) //z pionu na poziomy
			{
				//jeœli porusza³ siê w dó³, a teraz skrêca w prawo
				if (Level[snakeY[0]][snakeX[0]] == 13) Level[snakeY[i]][snakeX[i]] = 31;

				//jeœli porusza³ siê w dó³, a teraz skrêca w lewo
				if (Level[snakeY[0]][snakeX[0]] == 14) Level[snakeY[i]][snakeX[i]] = 32;

				//jeœli porusza³ siê w górê, a teraz skrêca w prawo
				if (Level[snakeY[0]][snakeX[0]] == 13) Level[snakeY[i]][snakeX[i]] = 33;

				//jeœli porusza³ siê w górê, a teraz skrêca w lewo
				if (Level[snakeY[0]][snakeX[0]] == 14) Level[snakeY[i]][snakeX[i]] = 34;
			}


			//SKRÊTY
			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 42
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 41) //z poziomu na pion
			{
				//jeœli porusza³ siê w prawo, a teraz skrêca w dó³
				if (Level[snakeY[0]][snakeX[0]] == 11) Level[snakeY[i]][snakeX[i]] = 34;

				//jeœli porusza³ siê w prawo, a teraz skrêca w górê
				if (Level[snakeY[0]][snakeX[0]] == 12) Level[snakeY[i]][snakeX[i]] = 32;

				//jeœli porusza³ siê w lewo, a teraz skrêca w dó³
				if (Level[snakeY[0]][snakeX[0]] == 11) Level[snakeY[i]][snakeX[i]] = 33;

				//jeœli porusza³ siê w lewo, a teraz skrêca w górê
				if (Level[snakeY[0]][snakeX[0]] == 12) Level[snakeY[i]][snakeX[i]] = 31;
			}


			/*
			//SKRÊTY
			if (
				Level[snakeY[i - 1]][snakeX[i - 1]] == 41 //pionowo
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 42 // poziomo
				&& Level[snakeY[0]][snakeX[0]] == 13 //g³owa w prawo
				)
			{
				Level[snakeY[i]][snakeX[i]] = 31;
			}

			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 41 //pionowo
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 42 // poziomo
				&& Level[snakeY[0]][snakeX[0]] == 14 //g³owa w lewo
				)
			{
				Level[snakeY[i]][snakeX[i]] = 32;
			}

			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 42 // poziomo
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 41 //pionowo
				&& Level[snakeY[0]][snakeX[0]] == 12 //g³owa w górê
				)
			{
				Level[snakeY[i]][snakeX[i]] = 31;
			}

			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 42 // poziomo
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 41 //pionowo
				&& Level[snakeY[0]][snakeX[0]] == 12 //g³owa w górê
				)
			{
				Level[snakeY[i]][snakeX[i]] = 32;
			}
			*/


		}
	}
}

//OB£SUGUJ KLAWIATURÊ
void SnakeObject::HandleKeyboard()
{
	//WCZYTYWANIE KLAWIATURY
	if (Game::event.type == SDL_KEYDOWN)
	{
		// WHILE MOVING DOWN
		if (Game::event.key.keysym.sym == SDLK_s)
		{
			//if(ypos % 32 == 0 && ypos % 32 == 0)
			//cout << " Przycisk S" << endl;
			//objTexture = TextureManager::LoadTexture("Assets/head_down.png");
			previnput = input; input = 's';
		}
		// WHILE MOVING UP
		else if (Game::event.key.keysym.sym == SDLK_w)
		{
			//cout << " Przycisk W" << endl;
			//objTexture = TextureManager::LoadTexture("Assets/head_up.png");
			previnput = input; input = 'w';
		}
		// WHILE MOVING RIGHT
		else if (Game::event.key.keysym.sym == SDLK_d)
		{
			//cout << " Przycisk D" << endl;
			//objTexture = TextureManager::LoadTexture("Assets/head_right.png");
			previnput = input; input = 'd';
		}
		// WHILE MOVING LEFT
		else if (Game::event.key.keysym.sym == SDLK_a)
		{
			//cout << " Przycisk A" << endl;
			//objTexture = TextureManager::LoadTexture("Assets/head_left.png");
			previnput = input; input = 'a';
		}
	}
}


//NAKARM WÊ¯A
void SnakeObject::FeedingSnake()
{

	AppleTree(Level);

	// SprawdŸ pozycje
	for (int i = 0; i < item_count; i++)
	{
		if ((snakeX[0] == itemX.at(i)) && (snakeY[0] == itemY.at(i)))
		{

			// Usuwanie pozycji
			item_count--;
			itemY.erase(itemY.begin() + 1);
			itemX.erase(itemX.begin() + 1);

			// W¹¿ roœnie
			rozmiar++;
			snakeX[rozmiar - 1] = tailX;
			snakeY[rozmiar - 1] = tailY;
		}
	}
}

//Sadzenie Jab³ek
void SnakeObject::AppleTree(int arr[29][41])
{
	srand((unsigned)time(NULL));
	int rx;
	int ry;

	//trzeba zmieniæ interval, bo siê zeruje


	//losowanie zwyk³ego jab³ka
	rx = (rand() % (41 - 2) + 1);
	ry = (rand() % (31 - 2) + 1);
	if (apple_count < 15)
	{
		//oczekiwanie kiedy mo¿na wygenerowaæ nowy obiekt
		if (interval1 > delay)
		{
			if (Level[ry][rx] == 0)
			{
				//cout << "+New Apple" << endl;
				Level[ry][rx] = 2;
				DrawMap(Level);
				interval1 = 0;
				apple_count++;
			}
		}
	}


	//losowanie z³otego jab³ka
	rx = (rand() % (41 - 2) + 1);
	ry = (rand() % (31 - 2) + 1);

	//oczekiwanie kiedy mo¿na wygenerowaæ nowy obiekt
	if (golden_apple_count < 3)
	{
		if (interval2 > delay * 3)
		{
			if (Level[ry][rx] == 0)
			{
				//cout << "+New GOLDEN Apple" << endl;
				Level[ry][rx] = 3;
				DrawMap(Level);
				interval2 = 0;
				golden_apple_count++;
			}
		}
	}

	//animacja golden apple
	if (interval2 == delay) pixelgoldenapple = TextureManager::LoadTexture("Assets/apple_golden2.png");
	if (interval2 == delay * 2) pixelgoldenapple = TextureManager::LoadTexture("Assets/apple_golden1.png");


	//losowanie kruka
	rx = (rand() % (41 - 2) + 1);
	ry = (rand() % (31 - 2) + 1);

	if (crow_count < 2)
	{
		//oczekiwanie kiedy mo¿na wygenerowaæ nowy obiekt
		if (interval3 > delay * 5)
		{
			if (Level[ry][rx] == 0)
			{
				//cout << "+New Raven" << endl;
				Level[ry][rx] = 4;
				DrawMap(Level);
				interval3 = 0;
				crow_count++;
			}
		}
	}

	//animacja golden apple
	if (interval3 == delay) pixelraven = TextureManager::LoadTexture("Assets/crow2.png");
	if (interval3 == delay * 2) pixelraven = TextureManager::LoadTexture("Assets/crow1.png");

}