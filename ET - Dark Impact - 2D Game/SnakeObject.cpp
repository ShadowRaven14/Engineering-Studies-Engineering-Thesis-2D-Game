#include "SnakeObject.h"

/*
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


//TABLICA WʯA
void SnakeObject::LoadMapFromVariable(int arr[29][41])
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

			destRect.x = column * 32;
			destRect.y = row * 32;

			switch (type)
			{
			case 0:
				ImageTextureManager::DrawImageTexture(blank, srcRect, destRect);
				break;

			case 1:
				ImageTextureManager::DrawImageTexture(pixelsnake, srcRect, destRect);
				break;

			case 2:
				ImageTextureManager::DrawImageTexture(pixelapple, srcRect, destRect);
				break;

			case 3:
				ImageTextureManager::DrawImageTexture(pixelgoldenapple, srcRect, destRect);
				break;

			case 4:
				ImageTextureManager::DrawImageTexture(pixelraven, srcRect, destRect);
				break;


				//g�owa
			case 11:
				ImageTextureManager::DrawImageTexture(snake_head_down, srcRect, destRect);
				break;

			case 12:
				ImageTextureManager::DrawImageTexture(snake_head_up, srcRect, destRect);
				break;

			case 13:
				ImageTextureManager::DrawImageTexture(snake_head_right, srcRect, destRect);
				break;

			case 14:
				ImageTextureManager::DrawImageTexture(snake_head_left, srcRect, destRect);
				break;


				//ogon
			case 21:
				ImageTextureManager::DrawImageTexture(snake_tail_down, srcRect, destRect);
				break;

			case 22:
				ImageTextureManager::DrawImageTexture(snake_tail_up, srcRect, destRect);
				break;

			case 23:
				ImageTextureManager::DrawImageTexture(snake_tail_right, srcRect, destRect);
				break;

			case 24:
				ImageTextureManager::DrawImageTexture(snake_tail_left, srcRect, destRect);
				break;


				//skr�ty
			case 31:
				ImageTextureManager::DrawImageTexture(snake_turn_1, srcRect, destRect);
				break;

			case 32:
				ImageTextureManager::DrawImageTexture(snake_turn_2, srcRect, destRect);
				break;

			case 33:
				ImageTextureManager::DrawImageTexture(snake_turn_3, srcRect, destRect);
				break;

			case 34:
				ImageTextureManager::DrawImageTexture(snake_turn_4, srcRect, destRect);
				break;


				//proste cia�o
			case 41:
				ImageTextureManager::DrawImageTexture(snake_body_vert, srcRect, destRect);
				break;

			case 42:
				ImageTextureManager::DrawImageTexture(snake_body_horizon, srcRect, destRect);
				break;


			default:
				ImageTextureManager::DrawImageTexture(blank, srcRect, destRect);
				break;
			}
		}
	}
}

void SnakeObject::InitializeTextures()
{
	blank = ImageTextureManager::LoadTexture("Assets/_blank.png");
	apple = ImageTextureManager::LoadTexture("Assets/apple.png");

	//pliki dodatk�w
	pixelapple = ImageTextureManager::LoadTexture("Assets/apple.png");
	pixelgoldenapple = ImageTextureManager::LoadTexture("Assets/apple_golden1.png");
	pixelraven = ImageTextureManager::LoadTexture("Assets/crow1.png");
	pixelsnake = ImageTextureManager::LoadTexture("Assets/pix_green.png");

	//Pliki w�a
	snake_head_down = ImageTextureManager::LoadTexture("Assets/head_down.png");
	snake_head_up = ImageTextureManager::LoadTexture("Assets/head_up.png");
	snake_head_right = ImageTextureManager::LoadTexture("Assets/head_right.png");
	snake_head_left = ImageTextureManager::LoadTexture("Assets/head_left.png");

	snake_tail_down = ImageTextureManager::LoadTexture("Assets/tail_down.png");
	snake_tail_up = ImageTextureManager::LoadTexture("Assets/tail_up.png");
	snake_tail_right = ImageTextureManager::LoadTexture("Assets/tail_right.png");
	snake_tail_left = ImageTextureManager::LoadTexture("Assets/tail_left.png");

	snake_turn_1 = ImageTextureManager::LoadTexture("Assets/turn1.png");
	snake_turn_2 = ImageTextureManager::LoadTexture("Assets/turn2.png");
	snake_turn_3 = ImageTextureManager::LoadTexture("Assets/turn3.png");
	snake_turn_4 = ImageTextureManager::LoadTexture("Assets/turn4.png");

	snake_body_vert = ImageTextureManager::LoadTexture("Assets/body_vert.png");
	snake_body_horizon = ImageTextureManager::LoadTexture("Assets/body_horizon.png");
}

//TABLICA WʯA


//KONTRUKTOR
SnakeObject::SnakeObject(const char* texturesheet, int x, int y)
{
	//ZARZ�DZANIE WʯEM
	std::cout << "Snake utworzony" << std::endl;
	width = 41, height = 31;
	input = 's', previnput = 's';
	speed = 4; delay = 120;
	size = 3; points = 0;
	item_count = 0;
	apple_count = 0; golden_apple_count = 0; crow_count = 0;

	//TABLICA
	std::cout << "Tablica dla Snake utworzona" << std::endl;
	InitializeTextures();
	LoadMapFromVariable(Level);
	interval1 = 0; interval2 = 0; interval3 = 0;
	srcRect.h = 64; srcRect.w = 64;
	srcRect.x = 0; srcRect.y = 0;
	destRect.h = srcRect.h / 2; destRect.w = srcRect.w / 2;


	//ZARZ�DZNIE WʯEM
	InitializeSnake();
}


//UPDATE
void SnakeObject::Update()
{
	interval1 = interval1 + 5;
	interval2 = interval2 + 5;
	interval3 = interval3 + 5;
	MoveWithSnake();
}

//RENDER
void SnakeObject::Render()
{
	SDL_RenderCopy(Game::mainGameRender, objTexture, &srcRect, &destRect);
	DrawMap(Level);
}



//ZARZ�DZANIE WʯEM
void SnakeObject::InitializeSnake()
{
	// Wymiarowanie W�a
	snakeX[0] = width / 2;	snakeY[0] = (height / 4) + 1;
	snakeX[1] = width / 2;	snakeY[1] = (height / 4) + 0;
	snakeX[2] = width / 2;	snakeY[2] = (height / 4) - 1;

	// Wyzerowanie cz�ci W�a
	for (int i = 3; i < 100; i++)
	{
		snakeX[i] = NULL;
		snakeY[i] = NULL;
	}

	// Umieszczenie W�a na planszy
	for (int i = 0; i < size; i++)
		Level[snakeY[i]][snakeX[i]] = 1;
}


void SnakeObject::MoveWithSnake()
{

	// Pr�dko�� W�a
	SetSnakeSpeed();

	// Dodawanie �lad�w ogona
	tailY = snakeY[size - 1];
	tailX = snakeX[size - 1];

	// Usuwanie �lad�w po ogonie
	Level[tailY][tailX] = '0';

	// Karmienie i powi�kszanie w�a
	FeedingSnake();

	// Kopiowanie W�a do tablicy temp
	for (int i = 0; i < size - 1; i++)
	{
		tempX[i + 1] = snakeX[i];	// Kopiowanie warto�ci y
		tempY[i + 1] = snakeY[i];	// Kopiowanie warto�ci x
	}

	// Kopiowanie g�owy W�a
	tempX[0] = snakeX[0];
	tempY[0] = snakeY[0];

	// Kopiowanie z tablicy temp
	for (int i = 0; i < size; i++)
	{
		snakeX[i] = tempX[i];						// Kopiowanie warto�ci Y
		snakeY[i] = tempY[i];						// Kopiowanie warto�ci X
	}

	// Obs�uguj input z klawiatury
	HandleKeyboard();

	// OBS�UGA PORUSZANIA
	// WHILE MOVING DOWN
	if (previnput == 's')
	{
		snakeY[0] += 1;			// Zestaw g��w na nowej pozycji
		if (input == 'a')		// Id� w lewo
			previnput = 'a';
		else if (input == 'd')	// Id� w prawo
			previnput = 'd';
	}
	// WHILE MOVING UP
	else if (previnput == 'w')
	{
		snakeY[0] -= 1;			// Zestaw g��w na nowej pozycji
		if (input == 'a')		// Id� w lewo
			previnput = 'a';
		else if (input == 'd')	// Id� w prawo
			previnput = 'd';
	}
	// WHILE MOVING RIGHT
	else if (previnput == 'd')
	{
		snakeX[0] += 1;			// Zestaw g��w na nowej pozycji
		if (input == 'w')		// Id� w g�r�
			previnput = 'w';
		else if (input == 's')	// Id� w d�
			previnput = 's';
	}
	// WHILE MOVING LEFT
	else if (previnput == 'a')
	{
		snakeX[0] -= 1;			// Zestaw g��w na nowej pozycji
		if (input == 'w')		// Id� w g�re
			previnput = 'w';
		else if (input == 's')	// Id� w d�
			previnput = 's';
	}


	// Rysowanie i zmiana pozycji W�a		
	for (int i = 0; i < size; i++)
	{
		// Je�li wyjdzie poza map�
		if (snakeY[i] < 0 || snakeY[i] > 28 || snakeX[i] < 0 || snakeX[i]>40)
		{
			snakeY[i] = 15;
			snakeX[i] = 20;
		}

		// Zbieranie jab�ek
		if (Level[snakeY[i]][snakeX[i]] == 2)
		{
			size++;
			points = points + 100;
			std::cout << "Zdobyto jab�ko, aktualny wynik: " << points << std::endl;
			apple_count--;
		}

		// Zbieranie jab�ek
		if (Level[snakeY[i]][snakeX[i]] == 3)
		{
			size = size + 3;
			points = points + 501;
			std::cout << "Zdobyto z�ote jab�ko, aktualny wynik: " << points << std::endl;
			golden_apple_count--;
		}

		// Zbieranie jab�ek
		if (Level[snakeY[i]][snakeX[i]] == 4)
		{
			points = points - 300;
			std::cout << "Wpadni�to na Kruka, aktualny wynik: " << points << std::endl;
			crow_count--;
		}

		HandleSnakeGraphics();
	}
}

//USTAW PR�DKO�� WʯA
void SnakeObject::SetSnakeSpeed()
{
	SDL_Delay(delay);
}

//USTAW PR�DKO�� WʯA
void SnakeObject::IsGameOver()
{
	//TO-DO
}

void SnakeObject::HandleSnakeGraphics()
{
	//Rysowanie w�a
	for (int i = 0; i < size; i++)
	{
		//G�OWA
		if (i == 0)
		{
			if (input == 's') Level[snakeY[i]][snakeX[i]] = 11;
			if (input == 'w') Level[snakeY[i]][snakeX[i]] = 12;
			if (input == 'd') Level[snakeY[i]][snakeX[i]] = 13;
			if (input == 'a') Level[snakeY[i]][snakeX[i]] = 14;
		}

		//OGON
		if (i == (size - 1))
		{

			if (Level[snakeY[size - 2]][snakeX[size - 2]] == 41)
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

			if (Level[snakeY[size - 2]][snakeX[size - 2]] == 42)
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


			//SKR�TY
			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 41
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 42) //z pionu na poziomy
			{
				//je�li porusza� si� w d�, a teraz skr�ca w prawo
				if (Level[snakeY[0]][snakeX[0]] == 13) Level[snakeY[i]][snakeX[i]] = 31;

				//je�li porusza� si� w d�, a teraz skr�ca w lewo
				if (Level[snakeY[0]][snakeX[0]] == 14) Level[snakeY[i]][snakeX[i]] = 32;

				//je�li porusza� si� w g�r�, a teraz skr�ca w prawo
				if (Level[snakeY[0]][snakeX[0]] == 13) Level[snakeY[i]][snakeX[i]] = 33;

				//je�li porusza� si� w g�r�, a teraz skr�ca w lewo
				if (Level[snakeY[0]][snakeX[0]] == 14) Level[snakeY[i]][snakeX[i]] = 34;
			}


			//SKR�TY
			if (Level[snakeY[i - 1]][snakeX[i - 1]] == 42
				&& Level[snakeY[i + 1]][snakeX[i + 1]] == 41) //z poziomu na pion
			{
				//je�li porusza� si� w prawo, a teraz skr�ca w d�
				if (Level[snakeY[0]][snakeX[0]] == 11) Level[snakeY[i]][snakeX[i]] = 34;

				//je�li porusza� si� w prawo, a teraz skr�ca w g�r�
				if (Level[snakeY[0]][snakeX[0]] == 12) Level[snakeY[i]][snakeX[i]] = 32;

				//je�li porusza� si� w lewo, a teraz skr�ca w d�
				if (Level[snakeY[0]][snakeX[0]] == 11) Level[snakeY[i]][snakeX[i]] = 33;

				//je�li porusza� si� w lewo, a teraz skr�ca w g�r�
				if (Level[snakeY[0]][snakeX[0]] == 12) Level[snakeY[i]][snakeX[i]] = 31;
			}


		}
	}
}

//OB�SUGUJ KLAWIATUR�
void SnakeObject::HandleKeyboard()
{
	//WCZYTYWANIE KLAWIATURY
	if (Game::mainGameEvent.type == SDL_KEYDOWN)
	{
		// WHILE MOVING DOWN
		if (Game::mainGameEvent.key.keysym.sym == SDLK_s)
		{
			std::cout << " Przycisk S" << std::endl;
			previnput = input; input = 's';
		}
		// WHILE MOVING UP
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_w)
		{
			std::cout << " Przycisk W" << std::endl;
			previnput = input; input = 'w';
		}
		// WHILE MOVING RIGHT
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_d)
		{
			std::cout << " Przycisk D" << std::endl;
			previnput = input; input = 'd';
		}
		// WHILE MOVING LEFT
		else if (Game::mainGameEvent.key.keysym.sym == SDLK_a)
		{
			std::cout << " Przycisk A" << std::endl;
			previnput = input; input = 'a';
		}
	}
}


//NAKARM WʯA
void SnakeObject::FeedingSnake()
{

	AppleTree(Level);

	// Sprawd� pozycje
	for (int i = 0; i < item_count; i++)
	{
		if ((snakeX[0] == itemX.at(i)) && (snakeY[0] == itemY.at(i)))
		{

			// Usuwanie pozycji
			item_count--;
			itemY.erase(itemY.begin() + 1);
			itemX.erase(itemX.begin() + 1);

			// W�� ro�nie
			size++;
			snakeX[size - 1] = tailX;
			snakeY[size - 1] = tailY;
		}
	}
}

//Sadzenie Jab�ek
void SnakeObject::AppleTree(int arr[29][41])
{
	srand((unsigned)time(NULL));
	int rx;
	int ry;

	//trzeba zmieni� interval, bo si� zeruje


	//losowanie zwyk�ego jab�ka
	rx = (rand() % (41 - 2) + 1);
	ry = (rand() % (31 - 2) + 1);
	if (apple_count < 15)
	{
		//oczekiwanie kiedy mo�na wygenerowa� nowy obiekt
		if (interval1 > delay)
		{
			if (Level[ry][rx] == 0)
			{
				std::cout << "+New Apple" << std::endl;
				Level[ry][rx] = 2;
				DrawMap(Level);
				interval1 = 0;
				apple_count++;
			}
		}
	}


	//losowanie z�otego jab�ka
	rx = (rand() % (41 - 2) + 1);
	ry = (rand() % (31 - 2) + 1);

	//oczekiwanie kiedy mo�na wygenerowa� nowy obiekt
	if (golden_apple_count < 3)
	{
		if (interval2 > delay * 3)
		{
			if (Level[ry][rx] == 0)
			{
				std::cout << "+New GOLDEN Apple" << std::endl;
				Level[ry][rx] = 3;
				DrawMap(Level);
				interval2 = 0;
				golden_apple_count++;
			}
		}
	}

	//animacja golden apple
	if (interval2 == delay) pixelgoldenapple = ImageTextureManager::LoadTexture("Assets/apple_golden2.png");
	if (interval2 == delay * 2) pixelgoldenapple = ImageTextureManager::LoadTexture("Assets/apple_golden1.png");


	//losowanie kruka
	rx = (rand() % (41 - 2) + 1);
	ry = (rand() % (31 - 2) + 1);

	if (crow_count < 2)
	{
		//oczekiwanie kiedy mo�na wygenerowa� nowy obiekt
		if (interval3 > delay * 5)
		{
			if (Level[ry][rx] == 0)
			{
				std::cout << "+New Raven" << std::endl;
				Level[ry][rx] = 4;
				DrawMap(Level);
				interval3 = 0;
				crow_count++;
			}
		}
	}

	//animacja golden apple
	if (interval3 == delay) pixelraven = ImageTextureManager::LoadTexture("Assets/crow2.png");
	if (interval3 == delay * 2) pixelraven = ImageTextureManager::LoadTexture("Assets/crow1.png");

}
*/