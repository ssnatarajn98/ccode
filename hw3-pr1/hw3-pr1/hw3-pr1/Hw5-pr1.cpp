//Sriram Natarajan
//9-20-17
//HW3-pr1
//csce121
//The program uses constructors in Chrono.cpp to verify that a date is actually a valid date.
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
int input_value(string prompt, int lower_bound, int upper_bound) {
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
	struct Appointment {
		Chrono::Date* Date;
		Chrono::Time* Time;
		string name;
	};
	vector<Appointment> DateBook(3);
	for (i = 0; i <= 2; i++) {
		Appointment * newAppointment = new Appointment;
		string tempName = 'sriram';
		cout << "Please enter a name for the appointment" << endl;
		cin >> tempName;
		int Year = 0;
		int Day = 0;
		int Month = 0;
		int hour = 0;
		int minute = 0;
		int second = 0;
		int AmOrPm = 0;
		string DateMenuOption = '0';
		string TimeMenuOption = '0';
		bool ProperDate = true;
		while (ProperDate) {
					monthOptions();
					Month = input_value("Please enter a month", 1, 12);
					Day = input_value("Please enter a day", 1, 31);
					Year = input_value("Please enter a Year", 1000, 9999);
					// The try catch takes care of any error that occurs and calls standardError Function
					try {
						Chrono::Date MonDayYearInst(Chrono::Date::Month(Month), Day, Year);
					}
					catch (...) { standardErrorDate(); }
					bool ProperDate = false;
		}
		bool ProperTime = true;
		while (properTime) {
						hour = input_value("Please enter a hour", 0, 23);
						minute = input_value("Please enter a minute", 0, 59);
						second = input_value("Please enter a second", 0, 59);
						// calling the third year-month-day constructor
						try {
							Chrono::Time HMSInst(hour, minute, second);
						}
						catch (...) { standardErrorTime(); }
						bool ProperTime =false;
					}
		newAppointment->name = tempName;
		newAppointment->Date = Chrono::Date date(Chrono::Date::Month(Month), Day, Year);
		newAppointment->Time = Chrono::Time time(hour, minute, second);
		DateBook[i] = newAppointment;
		}
	}











