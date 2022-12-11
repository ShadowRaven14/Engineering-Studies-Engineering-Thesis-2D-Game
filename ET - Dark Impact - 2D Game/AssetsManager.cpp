#include "AssetsManager.h"

//gdzieœ tutaj jest problem

AssetsManager::AssetsManager()
{

}

AssetsManager::~AssetsManager()
{

}

SDL_Texture* AssetsManager::GetTexture(std::string id)
{
	//return textures[id];
	return NULL;
}

void AssetsManager::LoadTexture(std::string id, const char* path)
{
	//textures.emplace(id, TextureManager::LoadTexture(path));
}

TTF_Font* AssetsManager::GetFont(std::string id)
{
	//return fonts[id];
	return NULL;
}

void AssetsManager::LoadFont(std::string id, std::string path, int fontSize)
{
	//fonts.emplace(id, TTF_OpenFont(path.c_str(), fontSize));
}