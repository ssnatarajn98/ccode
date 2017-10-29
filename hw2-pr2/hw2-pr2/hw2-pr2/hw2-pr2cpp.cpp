#include "std_lib_facilities_4.h"

int main() {
	
	bool ContinueGame = true;
	
		int seed;
		int BullCounter = 0;
		int CowCounter = 0;
		
		cout << "Do you want to play Bulls and Cows? "
			<< "If so, enter a random integer for me to use a seed; "
			<< "if not, enter q. ";
		cin >> seed;
		if (!cin) {
			system("pause"); // uncomment this for Windows
			return 0; // this will exit out of main() with no error
		}
		// Fill in vector with 4 distinct one-digit integers to be guessed;
		// use seed for getting new random numbers. While loop keeps going
		// until 4 distinct numbers are obtained; check for distinctness with
		// for loop that checks all numbers obtained so far.
		srand(seed);
		vector<int> numbers;
		int count = 0;
		while (numbers.size() < 4) {
			int new_num = randint(10);
			bool unique = true;
			for (int i = 0; i < numbers.size(); ++i) {
				if (new_num == numbers[i]) unique = false;
			}
			if (unique) numbers.push_back(new_num);
		}
		// takes each value in numbers and converts into a char from int
		// then it replaces the int type in numbers to char by replacing the new
		//tempChar in for numbers[z] position
		char TempChar;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "The number to guess is: ";
		for (int z = 0; z <= 3; ++z) {
			tempChar = numbers[z] + '0';
			numbers[z] = TempChar;
			//comment the line below if you don't want to see the number you need to guess
			printf("%c", TempChar);
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		//while loop continues until
		while (BullCounter != 4) {
			// BullCounter counts number of Bulls in each trial of the game
			BullCounter = 0;
			CowCounter = 0;
			string UserGuess = " ";
			//error checking if the user entered a four digit number
			bool ProperGuess = false;
			do {
				cout << "Please enter a positive 4 digit number as your guess" << endl;
				cin >> UserGuess;
			} while (UserGuess.length() != 4);
			// first checks if a number and its position is correct then checks
			// if the number appears in one of the 4 numbers the user needs to guess
			for (int k = 0; k <= 3; ++k) {
				if (UserGuess[k] == numbers[k]) {
					++BullCounter;
				}
				else {
					for (int m = 0; m <= 3; ++m) {
						if (numbers[k] == UserGuess[m]) {
							++CowCounter;
						}
					}
				}
			}
			cout << "Bull: " << BullCounter << endl;
			cout << "Cow:  " << CowCounter << endl;
		}
		cout << endl;
		cout << "You won, thanks for playing" << endl;
}
	
	


