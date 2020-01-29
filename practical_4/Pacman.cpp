#include <iostream>
#include <sstream>
#include "Pacman.h"
#include "SystemRenderer.h"
#include "Player.h"
#include "Ghost.h"
#include "ecm.h"
#include "cmp_sprite.h"
#include "cmp_player_movement.h"
#include "cmp_enemy_ai.h"

#define GHOSTS_COUNT 4;

std::shared_ptr<Scene> gameScene;;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;

void Scene::Load() 
{

}

void Scene::Update(double dt) { _ents.Update(dt); }

void Scene::Render() { _ents.Render(); }

void MenuScene::Load()
{

}

void MenuScene::Update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		activeScene = gameScene;
	}

	Scene::Update(dt);
	stringstream s;
	text.setString("Almost Pacman");
	text.setPosition(Vector2f(600 / 2, 800 / 2));
}

void MenuScene::Render()
{
	Renderer::Queue(&text);
	Scene::Render();
}

void GameScene::Load()
{
	{
		auto pl = make_shared<Entity>();
		auto s = pl->AddComponent<ShapeComponent>();
		s->SetShape<CircleShape>(12.0f);
		s->GetShape().setFillColor(Color::Yellow);
		s->GetShape().setOrigin(Vector2f(12.0f, 12.0f));
		auto c = pl->AddComponent<PlayerMovementComponent>();

		_ents.list.push_back(pl);
	}

	const Color ghost_cols[]{ {208, 62, 25},		//Red
							{219, 133, 28},		//Orange
							{70, 191, 238},		//Cyan
							{234, 130, 229} };	//Pink

	for (int i = 0; i < 4; ++i)
	{
		auto ghost = make_shared<Entity>();
		auto s = ghost->AddComponent<ShapeComponent>();
		s->SetShape<CircleShape>(12.0f);
		s->GetShape().setFillColor(ghost_cols[i % 4]);
		s->GetShape().setOrigin(Vector2f(12.0f, 12.0f));
		auto c = ghost->AddComponent<EnemyAiMovement>();

		_ents.list.push_back(ghost);
	}
}

void GameScene::Update(double dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Tab))
	{
		activeScene = menuScene;
	}
	Scene::Update(dt);
}

void GameScene::Render()
{
	Scene::Render();
}

void GameScene::Respawn()
{

}