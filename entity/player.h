#ifndef __ENTITY__PLAYER_H__
#define __ENTITY__PLAYER_H__

#include <SDL.h>
#include "../utils/vector2d.h"
#include "../utils/color.h"

struct EPlayer
{
	EPlayer();
	~EPlayer();

	void spawn();
	void spawn(int x, int y);
	void kill();
	bool isAlive();

	void setTexture(SDL_Texture* pTexture);

	void rotate();
	void normalizeAngle();

	bool isJumping();

	void jump();
	void setJumpStatus(bool bCanJump);

	void setPosition(int x, int y);
	Vector2d getPosition();

	void setSize(int w, int h);
	Vector2d getSize();

	SDL_Rect getRect();

	void update();
	void draw(SDL_Renderer* pRenderer);

	static const int WIDTH = 32;
	static const int HEIGHT = 32;

private:
	int m_x = 0;
	int m_y = 0;
	int m_w = WIDTH;
	int m_h = HEIGHT;

	float m_velX = 0.f;
	float m_velY = 0.f;

	float m_fSpeed = 0;

	double m_dAngle = 0;

	SDL_Texture* m_pTexture = NULL;

	bool m_bAlive = false;
	bool m_bJumping = false;
	bool m_bCanJump = false;

	const float DEF_VELX = 2.f;
	const float DEF_VELY = 2.f;
	const float DEF_SPEED = 2.f;
};

#endif
