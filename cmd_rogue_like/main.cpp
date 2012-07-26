#include <iostream>
#include <string>
#include <Windows.h>
#include "Sprite.h"
#include "Item.h"
#include <ctime>
#include <cstdlib>

using namespace std;

bool running = true, started = false, inventory = false, ingame = false;
char display[24][80];
char map[23][80];
Item invItems[40];

void logic(string);
void move(string);
void warning(string);
void print();
void render();
void drawString(int, int, string);

Sprite plr(4, 3, 'X');

void init(){
	cout << "initializing...\n";
	for(int i = 0; i < sizeof(display) / sizeof(display[0]); i++){
		for(int x = 0; x < sizeof(display[i]) / sizeof(display[i][0]); x++){
			display[i][x] = '.';
		}
	}
	int x, y, w, h;
	for(int i = 0; i < 10; i++){
		x = (rand() % ( sizeof(map[0]) / sizeof(map[0][0])));
		y = (rand() % ( sizeof(map) / sizeof(map[0])));
		w = (rand() % ( sizeof(map[0]) / sizeof(map[0][0])));
		h = (rand() % ( sizeof(map[0]) / sizeof(map[0][0])));

		string top, side = "-";

		for(int wi = 0; wi < w; wi++){
			top += "-";
			if(wi < w - 2){
				side += " ";
			}
		}

		side += "-";

		for(int y = 0; y < h; y++){
			if(y == 0 || y == h - 1){
				
			}else{
				cout << side << endl;
			}
		}
	}

	ingame = true;
}

int main(){
	string input = "";

	cout << 
	"************************************************\n"
	"*     Welcome to the amazing adventures of     *\n"
	"*                   ZIP ZONANT                 *\n"
	"*                                              *\n"
	"*                   CONTROLLS:                 *\n"
	"*   A S D W = move                             *\n"
	"*   I = inventory                              *\n"
	"*   T = attack                                 *\n"
	"*   X <--- this is you                         *\n"
	"*                                              *\n"
	"*             TYPE START TO BEGIN              *\n"
	"************************************************\n";

	while(running){
		cin >> input;
		logic(input);
		if(started){
			render();
		}
	}

	return 0;
}

void logic(string s){
	if(s == "start"){
		if(!started){
			started = true;
			init();
		}else{
			warning("you already started the game");
		}
	}

	if(started){
		if(inventory){
			if(s == "i" || s == "exit" || s == "back"){
				inventory = false;
				ingame = true;
			}
		}else{
			if(s == "i" || s == "inventory"){
				inventory = true;
				ingame = false;
			}
			if(s == "a" || s == "w" || s == "s" || s == "d"){
				move(s);
			}
			if(s == "exit"){
				cout << "are you sure you want to" << s << endl;
			}
		}
	}
}

void move(string s){
	if(s == "w"){
		plr.setY(plr.getY() - 1);
	}else if(s == "s"){
		plr.setY(plr.getY() + 1);
	}else if(s == "a"){
		plr.setX(plr.getX() - 1);
	}else if(s == "d"){
		plr.setX(plr.getX() + 1);
	}
}

void warning(string s){

}

void drawChar(int x, int y, char c){
	display[y][x] = c;
}

void drawString(int y, int x, string s){
	for(int a = 0; a < s.length(); a++){
		display[y][a] = s.at(a);
	}
	
}

void drawBg(char c){
	for(int i = 0; i < sizeof(display) / sizeof(display[0]); i++){
		for(int x = 0; x < sizeof(display[i]) / sizeof(display[i][0]); x++){
			display[i][x] = c;
		}
	}
}

void render(){
	drawBg('.');

	if(ingame){
		drawChar(plr.getX(), plr.getY(), plr.getChar());
	}else if(inventory){
		drawBg(' ');
		drawString(0, 0, "+====Inventory=========================+====Character==========================+");
		drawString(1, 0, "|                                                                              |");
		for(int i = 0; i < 23; i++){
			if(!invItems[i].isEmpty()){
				drawString(i + 2, 0,"                     " + invItems[i + 20].getName());
			}
			if(!invItems[i].isEmpty()){
				drawString(i + 2, 0, "| " + invItems[i].getName());
			}
		}
		for(int i = 1; i < 23; i++){
			drawChar(79, i, '|');
			drawChar(39, i, '|');
			drawChar(0, i, '|');
			drawChar(19, i, ':');
		}
		drawString(22, 0, "+======================================+=======================================+");
		drawString(23, 0, "| I / EXIT / BACK | USE [item] | INSPECT [item] | EQUIPT [item] | DROP [item]  |");
	}
	cout << endl;
	print();
}

void print(){
	for(int i = 0; i < sizeof(display) / sizeof(display[0]); i++){
		for(int x = 0; x < sizeof(display[i]) / sizeof(display[i][0]); x++){
			cout << display[i][x];
		}
	}

	cout << ">";
}