#pragma once

#include <string>
#include <iostream>

using namespace std;

class Display{
private:
	char **screen;

public:
	Display(int width, int height);
	~Display(void);
	void render(void);
};

