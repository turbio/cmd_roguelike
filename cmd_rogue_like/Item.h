#include <string.h>
#include <string>

using namespace std;

class Item{

public:
	Item(void);
	~Item(void);
	string getName();
	bool isEmpty();

private:
	string name;
	bool empty;
	int amount;
};

