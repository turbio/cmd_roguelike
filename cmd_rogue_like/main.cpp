/*the most complex class of them all*/
#include "Controller.h"

int main(int x){
	Controller controller;	//calls controller constructor
	return 0;	//end program
}

/*
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
*/