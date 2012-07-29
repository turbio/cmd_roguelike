/*controlls all drawing*/

#include <iostream>
#include <string>
#include "Display.h"
#include <Windows.h>

using namespace std;

HANDLE hConsole;	//used to switch console colors

//CONSTRUCTOR
Display::Display(int w, int h){
	//mostly testing
	cout << "yams are ready";	//YAMS!!!
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//setup console color sys
	for(int i = 0; i <= 255; i++){	//for testing - display all 255 chars
		char c = i;
		cout << i << " : " << c << "\t\t";
		if(i % 3 == 0){	//for tabing / spacing
			cout << "\n";
		}
	}
	for(int i = 0; i < 255; i++){	//test all colors
		SetConsoleTextAttribute(hConsole, i);
		cout << i << " cout \t\t\n";
	}
	cout << "setting up display...\n";
	//create screen chars
	try{
		screen = new item*[w];

		for(int i = 0; i < w; i++){
			screen[i] = new item[h];
		}
	}catch(...){
		//if out of memory or something :(
		cout << "unable to alocate memory\n";
	}

	for(int x = 0; x < w; x++){	//set default value for all screen chars
		for(int y = 0; y < h; y++){
			screen[x][y].character = 177;
			screen[x][y].color = 7;
		}
	}

	cout << "display setup\n";
	SetConsoleTextAttribute(hConsole, 7);
}

//DESTRUCTOR
Display::~Display(void){
	delete screen;
}

//shows intro
void Display::showIntro(char c){
	SetConsoleTextAttribute(hConsole, 15);
	cout << 
	"************************************************\n"
	"*     Welcome to the amazing adventures of     *\n"
	"*                   ZIP ZONANT                 *\n"
	"*                                              *\n"
	"*                   CONTROLLS:                 *\n"
	"*   CONTROLS->LIST(...)                        *\n"
	"*   ERROR: INVALID ARGS                        *\n"
	"*                                              *\n"
	"*   "<<c<<" <--- this is you                         *\n"
	"*                                              *\n"
	"*             TYPE START TO BEGIN              *\n"
	"************************************************\n";
	SetConsoleTextAttribute(hConsole, 7);
}

//refresh screen data
void Display::render(void){

}

/*
void Display::render(void){
	drawBg('.');

	if(ingame){
		drawChar(plr.getX(), plr.getY(), plr.getChar());
	}else if(inventory){
		drawBg(' ');
		drawString(0, 0, "+====Inventory=========================+====Character=========================+");
		drawString(1, 0, "                                                                              ");
		for(int i = 0; i < 23; i++){
			if(!invItems[i].isEmpty()){
				drawString(i + 2, 0,"                     " + invItems[i + 20].getName());
			}
			if(!invItems[i].isEmpty()){
				drawString(i + 2, 0, "| " + invItems[i].getName());
			}
		}
		for(int i = 1; i < 23; i++){
			drawChar(78, i, '|');
			drawChar(39, i, '|');
			drawChar(0, i, '|');
			drawChar(19, i, ':');
		}
		drawString(22, 0, "+======================================+======================================+");
		drawString(23, 0, "| I / EXIT / BACK | USE [item] | INSPECT [item] | EQUIPT [item] | DROP [item] |");
	}
	cout << endl;
	print();
}
*/

//show warning or message on screen
void Display::warning(string s){

}

//draw a specific character at x and y on screen
void Display::drawChar(int x, int y, char c){
	screen[x][y].character = c;
}

//draw an entire string on the screen at specified x y
void Display::drawString(int y, int x, string s){
	for(int a = 0; a < s.length(); a++){
		screen[y][a].character = s.at(a);
	}
	
}

//fill the screen with one character
void Display::drawFill(char c){
	for(int i = 0; i < sizeof(screen) / sizeof(screen[0]); i++){
		for(int x = 0; x < sizeof(screen[i]) / sizeof(screen[i][0]); x++){
			screen[i][x].character = c;
		}
	}
}

//display with cout
void Display::print(void){
	system("cls");
	for(int i = 0; i < sizeof(screen) / sizeof(screen[0]); i++){
		for(int x = 0; x < sizeof(screen[i]) / sizeof(screen[i][0]); x++){
			SetConsoleTextAttribute(hConsole, screen[i][x].color);
			cout << screen[i][x].character;
		}
		cout << "\n";
	}

	cout << ">";
}
