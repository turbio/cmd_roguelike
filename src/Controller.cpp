#include "Controller.h"
#include <ctime>

int HEIGHT = 24, WIDTH = 79;

//CONSTRUCTOR
Controller::Controller(void){
	running = true;
	begin = false;

	player = new Sprite(2, 3, 1);
	player->setColor(10);

	display = new Display(&WIDTH, &HEIGHT);
	display->showIntro(player->getChar());

	run();
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
		if(begin){
			display->render();
		}
	}
}

//load game
void Controller::init(void){
	cout << "starting...\n";

	display->addSprite(player);
	display->drawFill(177);

	srand(time(NULL));

	int x, y, w, h;
	for(int i = 0; i < 8; i++){
		Sprite * sprite;

		w = (rand() % 25) + 4;
		h = (rand() % 15) + 4;
		x = (rand() % (WIDTH - w / 2));
		y = (rand() % (HEIGHT - h / 2));

		sprite = new Sprite(y, x, h, w);
		display->addSprite(sprite);
	}

	begin = true;
}

void Controller::generate(){
	
}

//move player
void Controller::move(Direction d){
	player->move(d);
	switch(d){
		case UP:{	//move up
			
		}break;
		case RIGHT:{	//move right
			
		}break;
		case DOWN:{	//move down
			
		}break;
		case LEFT:{	//move left
			
		}break;
		default:{	//noooooooo
			//do nothing
		}break;
	}
}

//read keywords from input
void Controller::checkInput(string s){
	if(!begin && s == "start"){	//if not already inited
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