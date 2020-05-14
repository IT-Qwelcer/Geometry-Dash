#ifndef __ENTITY__BLOCK_H__
#define __ENTITY__BLOCK_H__

#include "../utils/vector2d.h"
#include "../utils/color.h"

struct EBlock
{
	EBlock();
	~EBlock();

	void setPosition(int x, int y);
	Vector2d getPosition();
	void setSize(int w, int h);
	Vector2d getSize();

	SDL_Rect getRect();

	void setColor(Color color);
	Color getColor();

	void update();
	void draw(SDL_Renderer* pRenderer);

	int getType();
	void setType(int iType);

	static const int WIDTH = 32;
	static const int HEIGHT = 32;

private:
	int m_x = 0;
	int m_y = 0;
	int m_w = 0;
	int m_h = 0;

	Color m_color;

	int m_iType = 0;
};

#endif
