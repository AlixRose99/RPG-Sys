#include <stdio.h>
#include <string>

using namespace std;

class Enemy
{
public:

	int hp,mp,exp,lootPointer,pAtk,pDef,mAtk,mDef = 0;
	std::string status = "alive";
	std::string name = "Debug";//c_str()

};

class player : public Enemy
{
	void attack() { cout << "You attack for " << rand() << "damage" << endl; }
};

