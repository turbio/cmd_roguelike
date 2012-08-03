#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>
#include "sprite.h"

using namespace std;

class Display{
private:
	struct item{	//one character one screen contains a color and char
		char character;
		int color;
	};
	int * width, *height;	//screen width and height

	item **screen;	//two dimensional array of all characters

	vector<Sprite*> spriteList;

	void print(void);
public:
	Display(int *width, int *height);	//CONSTRUCTOR takes screen width and heigh
	~Display(void);	//DESTRUCTOR
	void render(void);	//update the screen
	void showIntro(char playerChar);	//show the intro
	void drawChar(int x, int y, char c);	//draw char at x y
	void drawString(int x, int y, string s); //draw string at x y
	void warning(string s);	//display warning / message
	void drawFill(char c);	//fill the entire screen with character
	void drawFill(item i);	//fill the entire screen with item
	void addSprite(Sprite *sprite); 	//add sprite to spritelist
	void drawRect(int x, int y, int width, int height, bool fill);	//draw a rectangle on screen
};

