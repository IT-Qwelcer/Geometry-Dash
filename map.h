#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "entity\player.h"
#include "entity\block.h"
#include <SDL.h>

typedef unsigned char BYTE;

struct GameManager;

struct Map
{
	Map();
	Map(GameManager* pGameManager);
	~Map();

	bool load(const char* fileName);

	bool isLoaded();

	Vector2d getStartPosition();
	Vector2d getMapSize();

private:
	GameManager* m_pGameManager = NULL;

	bool m_bLoaded = false;

	Vector2d m_startPos;
	Vector2d m_mapSize;
};

#endif