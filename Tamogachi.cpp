#include <time.h>
#include <random>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <string>

using namespace std;

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else __unix__
		system("clear");
	#endif
}

class Animal {
public:	
	string name;
	string type;

	Animal(string AnimalName, string AnimalType) {
		name = AnimalName;
		type = AnimalType;
	}

	void MainLoop() {
		while (true == true) {
			clearScreen();
			if (dead == true) return;
			Options();
			if (boredom >= 100) {
				Bored();
			}
			if (hunger >= 100) {
				Hungry();
			}
			if (tiredness >= 100) {
				Tired();
			}
			boredom += 5;
			hunger += 9;
			tiredness += 5;

			if (tiredness >= 110) {
				Death("tired");
			}
			if (hunger >= 110) {
				Death("hungry");
			}
			if (boredom >= 110) {
				Death("bored");
			}
			
			this_thread::sleep_for(chrono::seconds(1));
		}
	}

private:
	int boredom = 0;
	int tiredness = 0;
	int hunger = 0;
	bool dead = false;
	string moods[4] = { "Sad", "Happy", "Angry", "Tired" };

	void Bored() {
		cout << "I am bored >:( \nPlz play with me >:(" << endl;
	}

	void Hungry() {
		cout << "I am hungry >:( \nPlz feed me >:(" << endl;
	}

	void Tired() {
		cout << "I am tired... le.. m.. sleep.." << endl;
	}

	void Death(string type) {
		if (type == "bored") {
			cout << "Your pet died from boredom.\n";
		}
		if (type == "tired") {
			cout << "Your pet is now resting.\n";
		}
		if (type == "hungry") {
			cout << "Your pet died from starvation.\n";
		}
		dead = true;
	}
	void Options() {
		clearScreen();
		cout << "Options for " + name << endl;
		cout << "Press 1 to play" << endl;
		cout << "Press 2 to feed" << endl;
		cout << "Press 3 to nap" << endl;
		cout << "Press 4 to check the stats" << endl;
		cout << "> ";
		int option;
		cin >> option;

		if (option == 1) {
			return Play();
		}
		if (option == 2) {
			return Feed();
		}
		if (option == 3) {
			return Nap();
		}
		if (option == 4) {
			return Stats();
		}
		Options();
	}
	
	void Play() {
		cout << "You are playing with your pet" << endl;;
		this_thread::sleep_for(chrono::seconds(5));
		boredom -= 10;
		cout << "You finished playing..." << endl;
		this_thread::sleep_for(chrono::seconds(2));
	}

	void Feed() {
		cout << "You are feeding your pet" << endl;;
		this_thread::sleep_for(chrono::seconds(7));
		hunger -= 10;
		cout << "You finished eating..." << endl;
		this_thread::sleep_for(chrono::seconds(2));
	}

	void Nap() {
		cout << "You are napping with your pet" << endl;;
		this_thread::sleep_for(chrono::seconds(10));
		tiredness -= 10;
		cout << "You finished napping..." << endl;
		this_thread::sleep_for(chrono::seconds(2));
	}

	void Stats() {
		cout << "Name: " + name << endl;
		cout << "Species: " + type << endl;
		cout << "Hunger: " + to_string(hunger) << endl;
		cout << "Tiredness: " + to_string(tiredness) << endl;
		cout << "Boredom: " + to_string(boredom) << endl;
		system("pause");
	}	
};

int main() {
	Animal animal("Jim", "Bunny");
	animal.MainLoop();
	while (true == true) {
		//When the pet dies do nothing
	}
	return 0;
}