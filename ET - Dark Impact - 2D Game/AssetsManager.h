#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "TextureManager.h"
#include <string>
#include <map>

class AssetsManager
{
public:
	AssetsManager();
	~AssetsManager();

	SDL_Texture* GetTexture (std::string id);
	void LoadTexture(std::string id, const char* path);
	TTF_Font* GetFont(std::string id);
	void LoadFont(std::string id, std::string, int fontSize);

private:
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, TTF_Font*> fonts;
};

