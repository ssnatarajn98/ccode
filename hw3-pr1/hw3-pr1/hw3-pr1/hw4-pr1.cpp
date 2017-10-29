//Sriram Natarajan
//9-27-17
//HW4-pr1
//csce121
//The program uses constructors in Chrono.cpp to verify that a time is actually a valid a time.
#include "std_lib_facilities_5.h"
#include "Chrono.h"

// This function outputs All the possible month options
void monthOptions()
	{
	cout << "Month options:" << endl;
	cout << " 1) for january" << endl;
	cout << " 2) for febuary" << endl;
	cout << " 3) for march" << endl;
	cout << " 4) for april" << endl;
	cout << " 5) for may" << endl;
	cout << " 6) for june" << endl;
	cout << " 7) for july" << endl;
	cout << " 8) for august" << endl;
	cout << " 9) for september" << endl;
	cout << "10) for october" << endl;
	cout << "11) for november" << endl;
	cout << "12) for december" << endl;
	cout << endl;
	}
//This function is called each time a integer input is required by user to make sure their input is valid
int input_value(string prompt,int lower_bound, int upper_bound) {
	cout << prompt << endl;
	int value;
	cin.clear(); // clear any error flags of "cin"
	while (true) {
		cin >> value;
		// if user entered something wrong, e.g., "qwertyuio" for integer, "i" is not assigned and "cin" is marked as "fail"
		if (cin.fail()) {
			cin.clear();// "cin" is marked as "fail", clear the error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n');// drop any remainings, now "cin" is fresh and ready to roll
			cout << "please enter an integer" << endl;
			cout << prompt << endl;
		}
		else if (lower_bound <= value  && value <= upper_bound) {
			return value;
		}
		else {
			cout << "input " << value << " out of bound (range: "
				<< lower_bound << " - " << upper_bound << "), please try again" << endl;
		}
	}
}

// error regarding a false date. This function will output

void standardErrorDate()
{
	cout << "Invalid Date" << endl;
	cout << endl;
 }
void standardErrorTime()
{
	cout << "Invalid Time" << endl;
	cout << endl;
}
// The main function 
int main() {
	// This variable keeps the loop running until the user wants to exit
	bool continueProgram = true;
	while (continueProgram) {
		string MenuOption = "0";
		int Year = 0;
		int Day = 0;
		int Month = 0;
		int hour = 0;
		int minute = 0;
		int second = 0;
		int AmOrPm = 0;
		//menu option
		cout << "Please enter:" << endl;
		cout << "1) if you would like the date in the month-day-year format" << endl;
		cout << "2) if you would like the default date format" << endl;
		cout << "3) if you would like the date in the year-month-day format" << endl;
		cout << "4) if you would like to enter time in 24 hour format (hours,minutes,seconds)" << endl;
		cout << "5) if you would like to enter time in the 12 hours format(hours, minutes,seconds, AmPm" << endl;
		cout << "6) if you would like to enter time for the default way" << endl;
		cout << "7) if you would like to quit" << endl;
		cin >> MenuOption;
		if (MenuOption == "1")
		{
			// calling the function to get values for the 3 variables we need 
			monthOptions();
			Month = input_value("Please enter a month", 1, 12);
			Day = input_value("Please enter a day", 1, 31);
			Year = input_value("Please enter a Year", 1000, 9999);
			// The try catch takes care of any error that occurs and calls standardError Function
			try {
				Chrono::Date MonDayYearInst(Chrono::Date::Month(Month), Day, Year);
				cout << MonDayYearInst;
			}
			catch (...) { standardErrorDate(); }
			cout << endl;
		}
		else if (MenuOption == "2")
		{
			// This is try/catching the default constructor
			try {
				Chrono::Date DefaultConstructor = Chrono::Date();
				cout << DefaultConstructor;
				cout << endl;
			}
			catch (...) { standardErrorDate(); }
			cout << endl;
		}
		else if (MenuOption == "3")
		{
			Year = input_value("Please enter a Year", 1000, 9999);
			monthOptions();
			Month = input_value("Please enter a month", 1, 12);
			Day = input_value("Please enter a day", 1, 31);
			// calling the third year-month-day constructor
			try {
				Chrono::Date YearMonDayInst(Year, Chrono::Date::Month(Month), Day);
				cout << YearMonDayInst;
			}
			catch (...) { standardErrorDate(); }
			cout << endl;
		}
		else if (MenuOption == "4")
		{
			hour = input_value("Please enter a hour", 0, 23);
		
			minute = input_value("Please enter a minute", 0, 59);
			second = input_value("Please enter a second", 0, 59);
			// calling the third year-month-day constructor
			try {
				Chrono::Time HMSInst(hour, minute, second);
				cout << HMSInst;
				cout << endl;
				cout << endl;
			}
			catch (...) { standardErrorTime(); }
			cout << endl;
		}
		else if(MenuOption == "5")
		{
			hour = input_value("Please enter a hour", 0, 11);
			minute = input_value("Please enter a minute", 0, 59);
			second = input_value("Please enter a second", 0, 59);
			AmOrPm = input_value("Please enter 1 for Am or 2 for Pm", 1, 2);
			
				try {
				Chrono::Time HMSAxInst(hour , minute , second);
				cout << HMSAxInst;
				// If else to print Am or Pm
				if (AmOrPm == 1) {
					cout << " Am" << endl;
					}
				else{
					cout << " Pm" << endl;
				}
				cout << endl;
			}

			catch (...) { standardErrorTime(); }

		}
		else if (MenuOption == "6")
		{
				try {
				cout << "00:00:00 Am" << endl;
			}

			catch (...) { standardErrorTime(); }

		}
		//exit program
		else if (MenuOption == "7")
		{
			cout << "Thanks for using the program. Goodbye" << endl;
			continueProgram = false;
		}
		else
		{
			// if the user enters anything in the menu other than 1, 2, 3 or 4
			cout << " Please try again be sure to enter just a single number" << endl;
			cout << endl;
		}

	}
}





	
		
	


