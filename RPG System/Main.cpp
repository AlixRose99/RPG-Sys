#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int i = 0;
int AtkVal;
int eAtkVal;
bool quit = false;
int turn = 0;

class Enemy
{
public:

	int hp, mp, exp, lootPointer, pAtk, pDef, mAtk, mDef = 0;
	std::string status = "alive";
	std::string name = "Debug";//c_str()

	void takeDamage() {
		hp -= AtkVal;
	}
};

class player : public Enemy
{
public:
	player(std::string name) {
		hp = 20;
		pAtk = 5;
		this->name = name;
	}

	void pAttack(Enemy *enemy) { 
		AtkVal = rand() % ((pAtk + 5) - 1 + 1) + 1;
		cout << name << " attacks for " << AtkVal << " damage" << endl;
		enemy->takeDamage();
		Sleep(1000);
	}

	void defend() { 
		cout << "You stand ready to defend against an attack" << endl; 
		
	}

	void defeat() {
		cout << "You died. Quitting." << endl;
		Sleep(2000);
		quit = true;
	}
};

class Goblin : public Enemy
{
public:
	Goblin(std::string name) {
		hp = 10;
		pAtk = 2;
		exp = ((pAtk + 5) - 1 + 1) + 1;
		this->name = name;
	}

	void newGoblin() {
		hp = 10;
		pAtk = 2;
		exp = ((pAtk + 5) - 1 + 1) + 1;
	}

	void eAttack(Enemy *enemy) { 
		AtkVal = rand() % ((pAtk + 5) - 1 + 1) + 1;
		cout << name << " attacks for " << AtkVal << " damage" << endl; 
		enemy->takeDamage();
		Sleep(1000);
		cout << endl;
		turn = 0;
	}

	void eDefend() { 
		cout << "The " << name << " stands ready to defend against an attack" << endl; 
	}

	void defeat() {
		cout << "You killed " << name << ". You get " << exp << " experience" << endl;
		Sleep(2000);
		newGoblin();
		turn = 0;
		//quit = true;
	}
};

int main(int argc, char* args[]) {
	srand(time(NULL));

	Goblin gob = Goblin("Goblin");
	player Char = player("Player");

	string input;
	cout << "You awaken in a dark forest, rising to your feet, you pick up your sword as a Goblin attacks you" << endl;
	cout << endl;
	Sleep(1000);

	while (quit != true) {
		if (turn == 0) {
			cout << "Enemy HP: " << gob.hp << endl;
			cout << "Your HP: " << Char.hp << endl;
			cout << endl;
			Sleep(500);
			cout << "What will you do?" << endl;
			getline(cin, input);
			if ((input == "Attack") || (input == "attack")) {
				Char.pAttack(&gob);
			}
			if ((input == "Defend") || (input == "defend")) {
				Char.defend();
			}
			if (input == "Enemy Attack") {
				gob.eAttack(&Char);
			}
			if ((input == "Quit") || (input == "quit")) {
				quit = true;
			}
			if (Char.hp <= 0) {
				Char.defeat();
			}
			if (gob.hp <= 0) {
				gob.defeat();
			}
			cout << endl;
		}
		if (turn = 1) {
			cout << "Enemy HP: " << gob.hp << endl;
			cout << "Your HP: " << Char.hp << endl;
			cout << endl;
			gob.eAttack(&Char);
		}
		continue;
	}
	return 0;
}