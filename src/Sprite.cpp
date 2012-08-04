#include "Sprite.h"
#include "Controller.h"

//CONSTRUCTOR for char
Sprite::Sprite(int x, int y, char c){
	xPos = x;
	yPos = y;

	character = c;
	setColor();

	type = CHAR;
}

//CONSTRUCTOR for rect
Sprite::Sprite(int x, int y, int w, int h){
	xPos = x;
	yPos = y;
	width = w;
	height = h;

	setColor();
	setChar();

	type = RECT;
}

//DESTRUCTOR
Sprite::~Sprite(){

}

//set sprite x position
void Sprite::setX(int i){
	xPos = i;
}

//set sprite y position
void Sprite::setY(int i){
	yPos = i;
}

//return sprite x position
int Sprite::getX(){
	return xPos;
}

//return sprite y position
int Sprite::getY(){
	return yPos;
}

// return sprite character
char Sprite::getChar(){
	return character;
}

//set sprite character
void Sprite::setChar(char c){
	character = c;
}

//set sprite color
void Sprite::setColor(int c){
	color = c;
}

//return sprite color
int Sprite::getColor(){
	return color;
}

//return sprite type
Sprite::drawType Sprite::getType(){
	return type;
}

//get sprite width
int Sprite::getWidth(){
	return width;
}

//get sprite height
int Sprite::getHeight(){
	return height;
}

//move sprite one unit it a direction
void Sprite::move(int d){
	switch(d){
		case Controller::UP:{
			yPos--;
		}break;
		case Controller::DOWN:{
			yPos++;
		}break;
		case Controller::RIGHT:{
			xPos++;
		}break;
		case Controller::LEFT:{
			xPos--;
		}break;
		default:{
			//do nothing
		}break;
	}
}
