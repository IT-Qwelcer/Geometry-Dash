#ifndef __UTILS__COLOR_H__
#define __UTILS__COLOR_H__

#include <SDL.h>

struct Color
{
	Color()
	{
		r = g = b = a = 0;
	}

	Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};

#endif
