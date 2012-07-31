#include "Sprite.h"

//CONSTRUCTOR
Sprite::Sprite(int x, int y, char c){
	xPos = x;
	yPos = y;
	character = c;
	color = 7;
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

int Sprite::getColor(){
	return color;
}