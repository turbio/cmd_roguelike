#define WIDTH 24	//console chars wide
#define HEIGHT 80	//console chars high

#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

Controller::Controller(void){
	display = new Display(WIDTH, HEIGHT);

	running = true;

	run();
}

Controller::~Controller(void){

}

void Controller::run(void){
	string input = "";

	while(running){
		cin >> input;
	}
}
