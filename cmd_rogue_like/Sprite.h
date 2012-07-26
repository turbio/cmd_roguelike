#pragma once
class Sprite
{
public:
	Sprite(int, int, char);
	~Sprite();	
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	char getChar();
	void setChar(char);

private:
	int xPos;
	int yPos;
	char character;
};

