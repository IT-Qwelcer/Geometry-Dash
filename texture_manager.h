#ifndef __TEXTURE_MANAGER_H
#define __TEXTURE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

struct CTextureManager
{
	static SDL_Texture* load(SDL_Renderer* pRenderer, const char* filePath);
	static void free();

private:
	static std::vector<SDL_Texture*> m_vcTextures;
};

#endif