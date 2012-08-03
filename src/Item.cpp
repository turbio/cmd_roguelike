#include "Item.h"
#include <string.h>
#include <string>

using namespace std;

Item::Item(void){
	name = "null";
	empty = true;
}


Item::~Item(void){

}

string Item::getName(){
	return name;
}

bool Item::isEmpty(){
	return empty;
}