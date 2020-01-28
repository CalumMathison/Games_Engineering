#pragma once 
#include "scene.h"

using namespace std;
using namespace sf;

extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;

class MenuScene : public Scene
{
private:
	Text text;
public:
	MenuScene() { }
	void Update(double dt) override;
	void Render() override;
	void Load() override;
};

class GameScene : public Scene
{
private:
	Text text;
	Clock scoreClock;
	void Respawn();

public:
	GameScene() = default;
	void Update(double dt) override;
	void Render() override;
	void Load() override;
};