#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL2/SDL.h>
#include "entity.hpp"

class Character : public Entity
{
public:
	Character(int r, int g, int b, int x, int y, int width, int height, float speed, float lifePoints, float power, float defense);
	Character(int r, int g, int b, int x, int y, int width, int height, float speed, float lifePoints, float power, float defense, float shield);
	Character(int r, int g, int b, int x, int y, int width, int height, float speed);
	Character(int r, int g, int b, int x, int y, int width, int height, float speed, float dirX, float dirY);
	~Character();
	void move();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	float speed;
	float lifePoints;
	float maxLifePoints;
	float dirX;
	float dirY;
	float power;
	float defense;
	float shield;

	unsigned long long int timeSinceLastShot;

	void takeDamage(float damage);

private:
};

#endif