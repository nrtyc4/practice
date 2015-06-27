#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	int number = rand() % 100;
	int guess = -1;
	int trycount = 0;
	while(guess != number && trycount < 8) {
		cout << "Please enter a guess: ";
		cin >> guess;

		if(guess < number)
			cout << "Too low" << endl;

		if(guess > number)
			cout << "Too high" << endl;

		trycount++;
	}

	if(guess==number)
		cout << "You got it!" << endl;
	else
		cout << "Sorry the number was: " << number << endl;

	return 0;
}