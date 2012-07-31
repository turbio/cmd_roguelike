#pragma once

#include <iostream>
#include <string>
#include "Display.h"
#include "Sprite.h"

using namespace std;

class Controller{
private:
	bool running;	//boolean for if running
	bool begin;	//detect if program inited

	Display * display;	//holds the display class
	Sprite * player;	//the main player

	void checkInput(string s);	//function to run keyword check
	void init(void);	//start game
	void move(int direction);	//move player in direction
public:
	Controller(void);	//CONSTRUCTOR
	~Controller(void);	//DESTRUCTOR
	void run(void);	//start program
};

