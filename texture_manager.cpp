#include "texture_manager.h"

std::vector<SDL_Texture*> CTextureManager::m_vcTextures;

SDL_Texture* CTextureManager::load(SDL_Renderer* pRenderer, const char* filePath)
{
	SDL_Surface* src = IMG_Load(filePath);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(pRenderer, src);

	m_vcTextures.push_back(texture);

	return texture;
}

void CTextureManager::free()
{
	for (auto* texture : m_vcTextures)
	{
		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
		}
	}
}