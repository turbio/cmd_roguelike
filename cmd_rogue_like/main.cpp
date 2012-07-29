#define WIDTH 24	//console chars wide
#define HEIGHT 80	//console chars high

#include <iostream>
#include <string>
#include <Windows.h>
#include "Sprite.h"
#include "Item.h"
#include <ctime>
#include <cstdlib>
#include "Display.h"

using namespace std;

void logic(string);
void move(string);
void warning(string);
void print();
void render();
void drawString(int, int, string);
void init();

bool running = true, started = false, inventory = false, ingame = false;


Sprite player(4, 3, 1);

int main(){
	string input = "";

	Display * disp = new Display(WIDTH, HEIGHT);
	disp->showIntro(player.getChar());

	while(running){
		cin >> input;
		logic(input);
		if(started){
			render();
		}
	}

	return 0;
}

void init(){
	cout << "initializing...\n";
	for(int i = 0; i < sizeof(display) / sizeof(display[0]); i++){
		for(int x = 0; x < sizeof(display[i]) / sizeof(display[i][0]); x++){
			
		}
	}
	int x, y, w, h;
	for(int i = 0; i < 10; i++){
		x = (rand() % ( sizeof(map[0]) / sizeof(map[0][0])));
		y = (rand() % ( sizeof(map) / sizeof(map[0])));
		w = (rand() % 15) + 4;
		h = (rand() % 15) + 4;

		string top, bottom, side = "";
		side += 186;

		for(int wi = 0; wi < w; wi++){
			if(wi == 0){
				top += 201;
				bottom += 200;
			}else if(wi == w - 1){
				top += 187;
				bottom += 188;
			}else{
				top += 205;
				bottom += 205;
			}
			if(wi < w - 2){
				side += " ";
			}
		}

		

		for(int y = 0; y < h; y++){
			if(y == 0 || y == h - 1){
				if(y == 0){
					cout << top << endl;
				}else{
					cout << bottom << endl;
				}
				
			}else{
				cout << side << endl;
			}
		}
	}

	ingame = true;
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