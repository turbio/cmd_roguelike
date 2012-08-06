/*controlls all drawing*/
#include "Display.h"
#include <vector>

using namespace std;

HANDLE hConsole;	//used to switch console colors

//CONSTRUCTOR
Display::Display(int *h, int *w){
	//mostly testing n stuff
	width = w;
	height = h;
	cout << "yams are ready";	//YAMS!!!
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //setup console color sys

	cout << "setting up display...\n";
	try{
		screen = new item*[*w];

		for(int i = 0; i < *w; i++){
			screen[i] = new item[*h];
		}
	}catch(...){
		//if out of memory or something :(
		cout << "unable to alocate memory\n";
	}

	for(int x = 0; x < *w; x++){	//set default value for all screen chars
		for(int y = 0; y < *h; y++){
			screen[x][y].character = 177;
			screen[x][y].color = ((x * y) % 254) + 1;
		}
	}

	cout << "display setup\n";

	for(int i = 0; i <= 255; i++){	//for testing - display all 255 chars
		char c = i;
		cout << i << " : " << c << "\t\t";
		if(i % 3 == 0){	//for tabing / spacing
			cout << "\n";
		}
	}
	/*
	*/
	
	char c = 177;
	for(int i = 0; i <= 15; i++){	//test all colors
		SetConsoleTextAttribute(hConsole, i);
		cout << i << c << c << c << c << c << "\t\t\n";
	}
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

//add sprite to spritelist
void Display::addSprite(Sprite *spr){
	spriteList.push_back(spr);
}

//refresh screen data
void Display::render(void){
	//fill screen (background)
	item tempItem;
	tempItem.character = 177;
	tempItem.color = 7;
	drawFill(tempItem);

	//draw sprites
	for(int i = 0; i < spriteList.size(); i++){
		if(spriteList.at(i)->getType() == Sprite::CHAR){

			item * tempItem;
			tempItem = new item;
			tempItem->character = spriteList.at(i)->getChar();
			tempItem->color = spriteList.at(i)->getColor();
			screen[spriteList.at(i)->getY()][spriteList.at(i)->getX()] = *tempItem;
		}else if(spriteList.at(i)->getType() == Sprite::RECT){

			drawRect(spriteList.at(i)->getX(),
				spriteList.at(i)->getY(),
				spriteList.at(i)->getWidth(),
				spriteList.at(i)->getHeight(),
				spriteList.at(i)->getColor());
		}
	}

	print();
}

//show warning or message on screen
void Display::warning(string s){

}

//draw a specific character at x and y on screen
void Display::drawChar(int x, int y, char c){
	//cout << "X:" << x << "  /  Y:" << y << "\t#\t" << "W:" << *width << "  /  H:" << *height << "\n";
	if(x < *width && y <= *height && x >= 0 && y >= 0){
		screen[x][y].character = c;
	}
}

//draw an entire string on the screen at specified x y
void Display::drawString(int y, int x, string s){
	for(int a = 0; a < s.length(); a++){
		screen[y][a].character = s.at(a);
	}
}

//fill the screen with one character
void Display::drawFill(char c){
	for(int x = 0; x < *width; x++){	//set default value for all screen chars
		for(int y = 0; y < *height; y++){
			drawChar(x, y, c);
		}
	}
}

//fill the screen with one item (char and color c c C COMBO)
void Display::drawFill(item it){
	for(int x = 0; x < *width; x++){	//set default value for all screen chars
		for(int y = 0; y < *height; y++){
			screen[x][y] = it;
		}
	}
}

//draw rectangle on screen
void Display::drawRect(int x, int y, int w, int h, int color){
	for(int a = 0; a < w; a++){
		for(int b = 0; b < h; b++){
			//draw fill
			for(int i = 0; i < w; i++){
				if(b < h - 1){
					drawChar(i + x, b + y + 1, '.');
				}
			}

			//draw lines
			if(a * b % 2 == 0){
				drawChar(x + a, y, 186);
			}

			drawChar(x, y + b, 205);
			drawChar(x + a, y + h, 186);
			drawChar(x + w, y + b, 205);

			//draw corners
			drawChar(x, y, 201);
			drawChar(x + w, y, 200);
			drawChar(x + w, y + h, 188);
			drawChar(x, y + h, 187);
		}
	}

	int chestCount = (rand() % 3) + 1;
	for(; chestCount >= 0 ; chestCount--){
		drawChar(x + (rand() % (w + 0)) - 0, 0, 'C');
	}
}

//display with cout
void Display::print(void){
	system("cls");
	for(int x = 0; x < *width; x++){
		for(int y = 0; y < *height; y++){
			SetConsoleTextAttribute(hConsole, screen[x][y].color);
			cout << screen[x][y].character;
		}
		cout << "\n";
	}

	SetConsoleTextAttribute(hConsole, 7);
	cout << ">";
}
