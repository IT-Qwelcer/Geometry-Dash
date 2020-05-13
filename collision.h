#ifndef __COLLISION_H
#define __COLLISION_H

#include <SDL.h>

typedef unsigned char BYTE;

struct Collision
{
	static BYTE AABB(const SDL_Rect& a, const SDL_Rect& b);
};

#endif