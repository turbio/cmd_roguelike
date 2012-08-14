#include "Controller.h"
#include <time.h>

int HEIGHT = 24, WIDTH = 79;	//width and height to draw

//CONSTRUCTOR
Controller::Controller(void){
	running = true;	//renning is used to keep main loop going
	begin = false;	//used to deternim if the game has been inited

	char playerChar = 1;	//the players
	player = new Sprite(2, 3, playerChar, Sprite::FOREGROUND);	//create main sprite which the user controlls
	player->setColor(10);	//set player color to green

	display = new Display(&WIDTH, &HEIGHT);	//initilize display
	display->showIntro(player->getChar());	//display begining message

	run();	//enter main loop
}

//DESTRUCTOR
Controller::~Controller(void){
	delete display;
	delete player;
}

//main program loop
void Controller::run(void){
	string input = "";	//takes input from cin

	while(running){	//loop forever while running (in case you can't read)
		cin >> input;
		checkInput(input);	//check input and run logic
		if(begin){	//if the game has started (inited, generated everything) 
			display->render();	//render and print to console/ screen
		}
	}
}

//initalize all objects and generate dungeon game
void Controller::init(void){
	cout << "starting...\n";

	display->addSprite(player);	//add main player to display list

	srand(time(NULL));	//create random seed for generation

	//add rooms
	int x, y, w, h;	//holds temporary position and size data
	bool startAdded = false, endAdded = false;	//if an exit and entrence have been added
	for(int i = 0; i < 10; i++){
		Sprite * sprite;	//create empty sprite variable

		w = (rand() % 35) + 4;	//random w h x and y
		h = (rand() % 20) + 4;
		x = (rand() % (WIDTH - w));
		y = (rand() % (HEIGHT - h));

		sprite = new Sprite(y, x, h, w);	//create sprite with random pos and size
		display->addSprite(sprite);

		//add chests to each room
		int chestCount = (rand() % 3);	//add a random amount of chestes to each room 0-2
		char chestChar = 232;

		for(; chestCount > 0 ; chestCount--){
			Sprite * sprite = new Sprite(x + (rand() % (w - 1)) + 1, y + (rand() % (h - 1)) + 1, chestChar, Sprite::MIDDLEGROUND);	//creat single character sprite at random position in current room
			display->addSprite(sprite);	//add sprite to display list
		}

		//add starting positon/entrance
		if(!startAdded){
			Sprite * start = new Sprite(x + (rand() % (w - 1)) + 1, y + (rand() % (h - 1)) + 1, 'S', Sprite::MIDDLEGROUND);	//crate entrance sprite
			display->addSprite(start);	//add entrance sprite to display list

			player->setX(start->getX());	//set player to level entrance
			player->setY(start->getY());

			startAdded = true;	//cannot add any more starts
		}else if(!endAdded){	//add exit from dungeion
			char exitChar = 233;
			Sprite * sprite = new Sprite(x + (rand() % (w - 1)) + 1, y + (rand() % (h - 1)) + 1, exitChar, Sprite::MIDDLEGROUND);	//create exit sprite
			display->addSprite(sprite);	//add exit sprite to display list

			endAdded = true;	//cannot add any more exits
		}
	}

	begin = true;
}

//move player
void Controller::move(Direction d){
	if((d == UP && display->charAt(player->getX(), player->getY() - 1) == '.') ||
		(d == DOWN && display->charAt(player->getX(), player->getY() + 1) == '.') ||
		(d == RIGHT && display->charAt(player->getX() + 1, player->getY() + 0) == '.') ||
		(d == LEFT && display->charAt(player->getX() - 1, player->getY() + 0) == '.')){
		player->move(d);
	}
}

//read keywords from input
void Controller::checkInput(string s){
	if(/*!begin && */s == "start"){	//if not already inited
		init();	//initalize
		return;	//end function
		cout << "this should never happen\n";	//NOOOOOooooo
	}

	int length = s.length();
	char * tempArray;
	try{
		tempArray = new char[length];
	}catch(...){
		cout << "able to yam the yams";
		return;
	};
	for(int i = 0; i < length; i++){
		tempArray[i] = s[i];
	}

	if(tempArray[0] == 'i'){

	}else if(tempArray[0] == 'w' 
		|| tempArray[0] == 'd' 
		|| tempArray[0] == 's' 
		|| tempArray[0] == 'a'){
			for(int i = 0; i < length; i++){
				if(tempArray[i] == 'w'){
					move(UP);
				}else if(tempArray[i] == 'd'){
					move(RIGHT);
				}else if(tempArray[i] == 's'){
					move(DOWN);
				}else if(tempArray[i] == 'a'){
					move(LEFT);
				}
			}
	}

	delete tempArray;
}