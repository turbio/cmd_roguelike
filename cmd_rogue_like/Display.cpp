#include "Display.h"


Display::Display(int w, int h){
	//cout << "yams are ready";
		for(int i = 0; i <= 255; i++){
		char c = i;
		cout << i << " : " << c << "\t\t";
		if(i % 3 == 0){
			cout << "\n";
		}
	}
	cout << "setting up display...\n";
	try{
		screen = new char*[w];

		for(int i = 0; i < w; i++){
			screen[i] = new char[h];
		}
	}catch(...){
		cout << "unable to alocate memory\n";
	}

	for(int x = 0; x < w; x++){
		for(int y = 0; y < h; y++){
			screen[x][y] = 177;
		}
	}

	cout << "display setup\n";
}


Display::~Display(void){
	delete screen;
}
