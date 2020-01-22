#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>
#include "maths.h"

#define ls LevelSystem

class LevelSystem
{
public:
	enum TILE { EMPTY, START, END, WALL, ENEMY, WAYPOINT };

	static void LoadLevelFile(const std::string& path, float tileSize = 100.0f);
	static void Render(sf::RenderWindow& window);
	static sf::Color GetColor(TILE t);
	static void SetColor(TILE t, sf::Color c);

	//Get Tile at grid coordinate
	static TILE GetTile(sf::Vector2ul);
	//Get Screenspace coordinate of tile
	static sf::Vector2f GetTilePosition(sf::Vector2ul);
	//Get the tile at screenspace pos
	static TILE GetTileAt(sf::Vector2f);
	static size_t GetHeight() { return _height; }
	static size_t GetWidth() { return _width; }
protected:
	static std::unique_ptr<TILE[]> _tiles; //Internal array of tiles
	static size_t _width; //How many tiles wide is level
	static size_t _height; //How many tiles high is level
	static sf::Vector2f _offset; //Screenspace offset of level, when rendered
	static float _tileSize; //Screenspace size of each tile, when rendered
	static std::map<TILE, sf::Color> _colors; //Color to render each tile type

	//Array of sfml sprites of each tile
	static std::vector<std::unique_ptr<sf::RectangleShape>> _sprites;
	//Generate the _sprites array
	static void BuildSprites();
private:
	LevelSystem() = delete;
	~LevelSystem() = delete;
};