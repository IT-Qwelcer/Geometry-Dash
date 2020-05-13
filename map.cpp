#include "map.h"
#include <string>
#include <fstream>
#include "game_manager.h"

Map::Map()
{}

Map::Map(GameManager* pGameManager)
{
	m_pGameManager = pGameManager;
}

Map::~Map()
{}

bool Map::load(const char* fileName)
{
	const std::string filePath("data/maps/" + std::string(fileName) + ".txt");

	std::ifstream input(filePath);

	if (!input.is_open())
	{
		return m_bLoaded = false;
	}

	m_startPos = Vector2d();
	m_mapSize = Vector2d();

	int y = 0;

	for (std::string line; getline(input, line); y++)
	{
		size_t lineLenght = line.length();

		if (m_mapSize.x < lineLenght * EBlock::WIDTH)
		{
			m_mapSize.x = lineLenght * EBlock::WIDTH;
		}

		for (int x = 0; x < lineLenght; x++)
		{
			if (line[x] == '#')
			{
				m_pGameManager->createBlock(0, x * EBlock::WIDTH, y * EBlock::HEIGHT);
			}
			else if (line[x] == '*')
			{
				m_pGameManager->createBlock(1, x * EBlock::WIDTH, y * EBlock::HEIGHT);
			}
			else if (line[x] == '@')
			{
				m_pGameManager->setPlayerPosition(x * EBlock::WIDTH, y * EBlock::HEIGHT);
			}
		}
	}

	m_mapSize.y = y * EBlock::HEIGHT;

	input.close();

	return m_bLoaded = true;
}

Vector2d Map::getMapSize()
{
	return m_mapSize;
}

Vector2d Map::getStartPosition()
{
	return m_startPos;
}

bool Map::isLoaded()
{
	return m_bLoaded;
}