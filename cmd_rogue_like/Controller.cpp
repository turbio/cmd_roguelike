#include "Controller.h"
#include <iostream>
#include <string>
#include "Sprite.h"

using namespace std;

int HEIGHT = 24, WIDTH = 79;

//CONSTRUCTOR
Controller::Controller(void){
	running = true;
	begin = false;

	player = new Sprite(10, 10, 1);
	player->setColor(10);

	display = new Display(&WIDTH, &HEIGHT);
	display->showIntro(player->getChar());

	run();
}

//DESTRUCTOR
Controller::~Controller(void){

}

//main program loop
void Controller::run(void){
	string input = "";	//takes input from cin

	while(running){	//loop forever while running (in case you can't read)
		cin >> input;
		checkInput(input);	//check input and run logic
	}

}

//move player
void Controller::move(int d){
	switch(d){
		case 0:{	//move up
			//player->setY(player->getY() - 1);
		}break;
		case 1:{	//move right

		}break;
		case 2:{	//move down

		}break;
		case 3:{	//move left

		}break;
		default:{	//noooooooo
			//do nothing
		}break;
	}
}

//read keywords from input
void Controller::checkInput(string s){
	if(!begin){	//if not already inited
		init();	//initalize
		return;	//end function
		cout << "this should never happen\n";	//NOOOOOooooo
	}

	int length = sizeof(s) / sizeof(s[0]);
	char * tempArray = new char[length];
	for(int i = 0; i < length; i++){
		tempArray[i] = s[i];
	}

	if(tempArray[0] == 'i'){

	}else if(tempArray[0] == 'w'){

	}else if(tempArray[0] == 'd'){

	}else if(tempArray[0] == 's'){

	}else if(tempArray[0] == 'a'){

	}

	delete tempArray;
	display->render();
}

//load game
void Controller::init(void){
	cout << "starting...\n";

	display->addSprite(player);

	display->drawFill(177);
	display->render();

	begin = true;
}