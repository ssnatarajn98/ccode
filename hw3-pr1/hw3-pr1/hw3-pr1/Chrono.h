
//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------
	class Time {
	public:

		enum AmPm { Am=1,
			        Pm=2 };

		class Invalid { };                 // to throw as exception
		//Time Constructors intialization
		Time(int h, int n, int s, AmPm x);
		Time(int h, int n, int s);
		Time();   
		// functions to return current value of Time
		int hour()   const { return h; }
		AmPm am() const { return x; }
		int  minute()  const { return n; }
		int second() const { return s; }

	private:
		int   h;
		AmPm x;
		int   n;
		int s;
	};
class Date {
public:

    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Invalid { };                 // to throw as exception

    Date(int y, Month m, int d);  
	Date(Month month, int day, int year);
	// check for valid date and initialize
    Date();                            // default constructor
    // the default copy operations are fine

    // non-modifying operations:
    int   day()   const { return d; }
    Month month() const { return m; }
    int   year()  const { return y; }

    // modifying operations:
    void add_day(int p);        
    void add_month(int p);
    void add_year(int p);
private:
    int   y;
    Month m;
    int   d;
};
//


//------------------------------------------------------------------------------

bool is_date(int y, Date::Month m, int d); // true for valid date
// true for valid time
bool is_timea(int h, int  mmn, int s, Time::AmPm xx);
bool is_time(int h, int  mmn, int s);
//------------------------------------------------------------------------------
bool leapyear(int y);                  // true if y is a leap year
//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
bool operator==(const Time& a, const Time& b);
bool operator!=(const Time& a, const Time& b);
//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);
ostream& operator<<(ostream& os, const Time& d);

//------------------------------------------------------------------------------

} // Chrono
