#pragma once

#include <iostream>
#include <string>
#include "Display.h"

using namespace std;

class Controller{
private:
	Display * display;
	bool running;

public:
	Controller(void);
	~Controller(void);
	void run(void);
};

