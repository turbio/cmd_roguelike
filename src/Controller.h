#pragma once

#include <iostream>
#include <string>
#include "Display.h"
#include "Sprite.h"

using namespace std;

class Controller{
public:
	enum Direction{UP = 0, RIGHT, DOWN, LEFT};	//used for direction

	Controller(void);	//CONSTRUCTOR
	~Controller(void);	//DESTRUCTOR
	void run(void);	//start program
	char charAt(int x, int y);	//return the rendered char at specific x and y
private:
	bool running;	//boolean for if running
	bool begin;	//detect if program inited

	Display * display;	//holds the display class
	Sprite * player;	//the main player

	void checkInput(string s);	//function to run keyword check
	void init(void);	//start game
	void move(Direction direction);	//move player in direction
	void generate();	//create level
};

