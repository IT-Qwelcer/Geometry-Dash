#include "collision.h"

#include "utils\vector2d.h"

BYTE Collision::AABB(const SDL_Rect& a, const SDL_Rect& b)
{
	Vector2d lt = Vector2d(a.x, a.y);
	Vector2d lb = Vector2d(a.x, a.y + a.h);
	Vector2d rb = Vector2d(a.x + a.w, a.y + a.h);
	Vector2d rt = Vector2d(a.x + a.w, a.y);

	if (rt.x >= b.x && rt.x <= b.x + b.w && rt.y >= b.y && rt.y <= b.y + b.h)
	{
		return 1;
	}

	if (rt.x >= b.x && rt.x <= b.x + b.w && rt.y + 27 >= b.y && rt.y + 27 <= b.y + b.h)
	{
		return 1;
	}

	if (lb.x >= b.x && lb.x <= b.x + b.w && lb.y >= b.y && lb.y <= b.y + b.h)
	{
		return 2;
	}

	if (rb.x >= b.x && rb.x <= b.x + b.w && rb.y >= b.y && rb.y <= b.y + b.h)
	{
		return 2;
	}

	if (lt.x >= b.x && lt.x <= b.x + b.w && lt.y >= b.y && lt.y <= b.y + b.h)
	{
		return 1;
	}

	return 0;
}