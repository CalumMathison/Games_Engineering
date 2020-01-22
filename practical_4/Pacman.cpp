#include <iostream>
#include <sstream>
#include "Pacman.h"
#include "SystemRenderer.h"
#include "Player.h"
#include "Ghost.h"

void Scene::Load() { }

void Scene::Update(double dt) { _ents.Update(dt); }

void Scene::Render() { _ents.Render(); }

void MenuScene::Update(double dt)
{
	if (Keyboard::isKey)
	{

	}

	Scene::Update(dt);
	stringstream s;
	text.setString("Almost Pacman");
}

void MenuScene::Render()
{
	Renderer::Queue(&text);
	Scene::Render();
}

void GameScene::Load()
{
	shared_ptr<Player> p(new Player);
	_ents.list.push_back(p);
	shared_ptr<Ghost> pinky(new Ghost(Color::Magenta));
	_ents.list.push_back(pinky);
	shared_ptr<Ghost> inky(new Ghost(Color::Cyan));
	_ents.list.push_back(inky);
	shared_ptr<Ghost> blinky(new Ghost(Color::Red));
	_ents.list.push_back(blinky);
	shared_ptr<Ghost> clyde(new Ghost(Color::Color(255, 127, 80, 1)));
	_ents.list.push_back(clyde);
}