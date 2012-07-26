#include "Sprite.h"

Sprite::Sprite(int x, int y, char c){
	xPos = x;
	yPos = y;
	character = c;
}

Sprite::~Sprite(){

}

void Sprite::setX(int i){
	xPos = i;
}

void Sprite::setY(int i){
	yPos = i;
}

int Sprite::getX(){
	return xPos;
}

int Sprite::getY(){
	return yPos;
}

char Sprite::getChar(){
	return character;
}
void Sprite::setChar(char c){
	character = c;
}