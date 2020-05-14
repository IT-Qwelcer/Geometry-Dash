#include "player.h"

#include "../camera.h"
#include "../texture_manager.h"

const int EPlayer::WIDTH;
const int EPlayer::HEIGHT;

EPlayer::EPlayer()
{}

EPlayer::~EPlayer()
{}

void EPlayer::spawn(int x, int y)
{
	setPosition(x, y);
	spawn();
}

void EPlayer::spawn()
{
	m_velX = DEF_VELX;
	m_velY = DEF_VELY;
	m_fSpeed = DEF_SPEED;

	m_bAlive = true;
}

void EPlayer::kill()
{
	m_bAlive = false;
}

bool EPlayer::isAlive()
{
	return m_bAlive;
}

void EPlayer::setTexture(SDL_Texture* pTexture)
{
	m_pTexture = pTexture;
}

void EPlayer::jump()
{
	if (m_bJumping || !m_bCanJump)
	{
		return;
	}

	m_dAngle += 15;
	m_bJumping = true;
	m_bCanJump = false;
	m_velY *= -1.5;
}

void EPlayer::setJumpStatus(bool bCanJump)
{
	m_bCanJump = bCanJump;
}

bool EPlayer::isJumping()
{
	return m_bJumping;
}

void EPlayer::rotate()
{
	m_dAngle += 5;
}

void EPlayer::normalizeAngle()
{
	while (m_dAngle > 360)
	{
		m_dAngle -= 360;
	}

	for (double a = 360; a >= 0; a -= 90)
	{
		if (m_dAngle - a >= 0)
		{
			m_dAngle = a;
			break;
		}
	}
}

void EPlayer::update()
{
	if (!m_bAlive)
	{
		return;
	}

	m_x += static_cast<int>(m_velX * m_fSpeed);

	if (m_bJumping)
	{
		if (m_velY < DEF_VELY)
		{
			m_velY += DEF_VELY / 25 * m_fSpeed;
		}
		else
		{
			m_velY = DEF_VELY;
			m_bJumping = false;
		}
	}

	m_y += static_cast<int>(m_velY * m_fSpeed);
}

void EPlayer::draw(SDL_Renderer* pRenderer)
{
	if (m_bAlive)
	{
		SDL_Rect srcRect{0, 0, m_w, m_h};
		SDL_Rect dstRect{ m_x - CCamera::x, m_y - CCamera::y, m_w, m_h };
		SDL_Point point = { m_w / 2, m_h / 2 };
		SDL_RenderCopyEx(pRenderer, m_pTexture, &srcRect, &dstRect, m_dAngle, &point, SDL_FLIP_NONE);
	}
}

void EPlayer::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

Vector2d EPlayer::getPosition()
{
	return Vector2d(m_x, m_y);
}

void EPlayer::setSize(int w, int h)
{
	m_w = w;
	m_h = h;
}

Vector2d EPlayer::getSize()
{
	return Vector2d(m_w, m_y);
}

SDL_Rect EPlayer::getRect()
{
	SDL_Rect rect{ m_x, m_y, m_w, m_h };
	return rect;
}