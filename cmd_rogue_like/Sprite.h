#pragma once

class Sprite{
private:
	int xPos, yPos, color;	//sprite x y and color
	char character;	//the sprites character
public:
	Sprite(int, int, char);	//CONSTRUCTOR
	~Sprite();	//DESTRUCTOR
	void setX(int);	//set x position
	void setY(int);	//set y position
	int getX();	//return the x position
	int getY();	//return the y position
	char getChar();	//return sprites character
	void setChar(char);	//set character of sprite
	void setColor(int);	//set sprite color
	int getColor(void);	//return sprite color
	void move(int d);	//move sprite in direction
};

