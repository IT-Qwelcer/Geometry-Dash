#include "game_manager.h"
#include <iostream>
#include <SDL_image.h>
#include "texture_manager.h"
#include "camera.h"
#include "collision.h"

int GameManager::m_winWidth = 0;
int GameManager::m_winHeight = 0;

GameManager::GameManager()
{}

GameManager::~GameManager()
{}

bool GameManager::init(const char* title, int width, int height)
{
	if (m_bRunning)
	{
		return false;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "GameManager::init SDL_Init error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cout << "GameManager::init IMG_Init error: " << IMG_GetError() << std::endl;
		return false;
	}

	m_pWin = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_winWidth = width, m_winHeight = height, SDL_WINDOW_SHOWN);

	if (m_pWin == NULL)
	{
		std::cout << "GameManager::init SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWin, -1, NULL);

	if (m_pRenderer == NULL)
	{
		std::cout << "GameManager::init SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_pWin);
		return false;
	}

	m_map = Map(this);

	if (!m_map.load("map_1"))
	{
		std::cout << "GameManager::init Map::load error: map file not found" << std::endl;
	}

	m_player.setTexture(CTextureManager::load(m_pRenderer, "data/assets/player_1.png"));
	m_player.spawn();

	return m_bRunning = true;
}

void GameManager::destroy()
{
	if (m_bRunning)
	{
		CTextureManager::free();
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWin);
	}

	SDL_Quit();
}

Vector2d GameManager::getWindowSize()
{
	return Vector2d(m_winWidth, m_winHeight);
}

void GameManager::setPlayerPosition(int x, int y)
{
	m_player.setPosition(x, y);
}

void GameManager::createBlock(int iType, int x, int y)
{
	EBlock block;
	Color color = iType ? Color(0, 0, 0, 0) : Color(85, 26, 139, 255);
	block.setColor(color);
	block.setSize(32, 32);
	block.setPosition(x, y);
	block.setType(iType);
	m_vcBlocks.push_back(block);
}

void GameManager::eventHandle()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		switch (m_event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (m_event.key.keysym.sym)
			{
			case SDLK_SPACE:
				if (m_player.isAlive())
				{
					m_player.jump();
				}
				else
				{
					Vector2d startPos = m_map.getStartPosition();
					m_player.spawn(startPos.x, startPos.y);
				}
				break;
			}
			break;
		default:
			break;
		}
	}
}

void GameManager::update()
{
	Vector2d mapSize = m_map.getMapSize();
	Vector2d playerPos = m_player.getPosition();

	Vector2d windowsSize = GameManager::getWindowSize();

	CCamera::x = playerPos.x - windowsSize.x / 4;
	CCamera::y = playerPos.y - windowsSize.y / 1.3;

	m_player.update();

	SDL_Rect playerRect = m_player.getRect();

	if (playerRect.x >= mapSize.x)
	{
		m_player.kill();
	}

	if (playerRect.y >= mapSize.y)
	{
		m_player.kill();
	}

	bool bColliding = false;

	for (auto& block : m_vcBlocks)
	{
		BYTE colSide = Collision::AABB(playerRect, block.getRect());
		if (colSide)
		{
			bColliding = true;

			if (colSide == 1)
			{
				m_player.kill();
			}
			else
			{
				if (block.getType() == 1)
				{
					m_player.kill();
				}

				m_player.setPosition(m_player.getPosition().x, block.getPosition().y - 32);
				m_player.setJumpStatus(true);
			}
		}
	}

	if (!bColliding)
	{
		m_player.setJumpStatus(false);
		m_player.rotate();
	}
	else
	{
		m_player.normalizeAngle();
	}
}

void GameManager::draw()
{
	SDL_SetRenderDrawColor(m_pRenderer, 125, 38, 205, 255);
	SDL_RenderClear(m_pRenderer);

	m_player.draw(m_pRenderer);

	for (auto& block : m_vcBlocks)
	{
		block.draw(m_pRenderer);
	}

	SDL_RenderPresent(m_pRenderer);
}

bool GameManager::isRunning()
{
	return m_bRunning;
}