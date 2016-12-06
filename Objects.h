#pragma once
//nazwy obiektów
enum IDS { PLAYER, BULLET, ENEMY };

//gracz
struct SpaceShip
{
	int ID;
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;
};

struct bullet
{
	int ID;
	int x;
	int y;
	bool live;
	int speed;

};