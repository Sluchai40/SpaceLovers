#include <SDL2/SDL.h>

#include "level.hpp"
#include "enemy.hpp"
#include "projectile.hpp"
#include "game.hpp"

std::set<Projectile *> Level::projectiles = {};
std::set<Enemy *> Level::enemies = {};
std::set<InGameItem *> Level::powerUps = {};
Level* Level::instance = nullptr;

Level::Level()
	: timeSinceLastSpawn(0), timeSinceLastPoweUp(0)
{
	Level::instance = this;
	Player::instance->lifePoints = Player::instance->maxLifePoints;
}

Level::~Level()
{
	for (auto projectile : projectiles)
	{
		projectiles.erase(projectile);
	}
	for (auto enemy : enemies)
	{
		enemies.erase(enemy);
	}
	Game::currentState = MENU;
}

void Level::update()
{
	this -> timeSinceLastSpawn += Game::frameTime;
	this -> timeSinceLastPoweUp += Game::frameTime;
	if (this -> timeSinceLastSpawn > 2000000000)
	{
		new Enemy(10, 10);
		this -> timeSinceLastSpawn = 0;
	}
	if (this -> timeSinceLastPoweUp > 2000000000)
	{
		new InGameItem();
		this -> timeSinceLastPoweUp = 0;
	}
}

// void Level::render()
// {
// 	for (auto enemy : std::set<Enemy *>(Level::enemies))
//     {
//         enemy->update();
//         enemy->render();
//     }

//     for (auto projectile : std::set<Projectile *>(Level::projectiles))
//     {
//         projectile->update();
//         projectile->render();
//     }
// }