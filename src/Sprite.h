#pragma once

class Sprite{
public:
	enum drawType{CHAR, RECT, STRING};	//how to draw sprite
private:
	int xPos, yPos, width, height, color;	//sprite x y and color
	char character;	//the sprites character
	drawType type;
public:
	Sprite(int x, int y, char);	//CONSTRUCTOR or character sprites
	Sprite(int xPositon, int yPosition, int width, int height);	//CONSTRUCTOR for rect type sprite
	~Sprite(void);	//DESTRUCTOR
	void setX(int x = 0);	//set x position
	void setY(int y = 0);	//set y position
	int getX(void);	//return the x position
	int getY(void);	//return the y position
	char getChar();	//return sprites character
	void setChar(char character = 'X');	//set character of sprite
	void setColor(int color = 7);	//set sprite color
	int getColor(void);	//return sprite color
	void move(int d = 0);	//move sprite in direction
	drawType getType(void);	//return the drawing method (used in rendering)
	int getWidth(void);	//return sprite width
	int getHeight(void);	//return sprite height
};

