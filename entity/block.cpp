#include "block.h"

#include "../camera.h"

const int EBlock::WIDTH;
const int EBlock::HEIGHT;

EBlock::EBlock()
{}

EBlock::~EBlock()
{}

void EBlock::update()
{

}

void EBlock::draw(SDL_Renderer* pRenderer)
{
	SDL_Rect rect{ m_x - CCamera::x, m_y - CCamera::y, m_w, m_h };
	SDL_SetRenderDrawColor(pRenderer, m_color.r, m_color.g, m_color.b, m_color.a);
	SDL_RenderFillRect(pRenderer, &rect);
}

void EBlock::setColor(Color color)
{
	m_color = color;
}

Color EBlock::getColor()
{
	return m_color;
}

void EBlock::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

Vector2d EBlock::getPosition()
{
	return Vector2d(m_x, m_y);
}

void EBlock::setSize(int w, int h)
{
	m_w = w;
	m_h = h;
}

Vector2d EBlock::getSize()
{
	return Vector2d(m_w, m_y);
}

SDL_Rect EBlock::getRect()
{
	SDL_Rect rect{ m_x, m_y, m_w, m_h };
	return rect;
}

int EBlock::getType()
{
	return m_iType;
}

void EBlock::setType(int iType)
{
	m_iType = iType;
}