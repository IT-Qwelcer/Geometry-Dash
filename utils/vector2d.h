#ifndef __UTILS__VECTOR2D_H__
#define __UTILS__VECTOR2D_H__

struct Vector2d
{
	Vector2d()
	{
		x = 0;
		y = 0;
	}

	Vector2d(int v)
	{
		x = y = v;
	}

	Vector2d(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int x;
	int y;
};

#endif
