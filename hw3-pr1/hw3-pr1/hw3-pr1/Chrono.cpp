
//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Chrono.h"

namespace Chrono {

// member function definitions:

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_date(yy,mm,dd)) throw Invalid();
}
Date::Date(Month mm, int dd, int yy)
	: m(mm) , d(dd), y(yy)
{
	if (!is_date(yy, mm, dd)) throw Invalid();
}
//Time Constructors to call time class two ways
Time::Time(int hh, int mmn, int ss, AmPm xx)
	: h(hh), n(mmn), s(ss), x(xx)
{
	if (!is_timea(hh, mmn, ss,xx)) throw Invalid();
}
Time::Time(int hh, int mmn, int ss)
	: h(hh), n(mmn), s(ss),x(Am)
{
	if (!is_time(hh, mmn, ss)) throw Invalid();
}


//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1); // start of 21st century
    return dd;
} 
//default time class
const Time& default_time()
{
	static const Time tt(0, 0, 0, Time::Am);
	return tt;
}

//------------------------------------------------------------------------------
// Default Time class
Time::Time()
	:h(default_time().hour()),
	 n(default_time().minute()),
	 s(default_time().second()),
	 x(default_time().am())

	 {
	}
Date::Date()
    :y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------

void Date:: add_day(int n)
{
    // ...
}

//------------------------------------------------------------------------------

void Date::add_month(int n)
{
    // ...
}

//------------------------------------------------------------------------------

void Date::add_year(int n)
{
    if (m==feb && d==29 && !leapyear(y+n)) { // beware of leap years!
        m = mar;        // use March 1 instead of February 29
        d = 1;
    }
    y+=n;
}

//------------------------------------------------------------------------------

// helper functions:

bool is_date(int y, Date::Month  m, int d)
{
    // check that y is valid
    if (y<0) return false;             // y must be positive

    // check that m is valid
    int mint = m;                      // mint must be 1 to 12
    if ((mint<1) || (mint>12)) return false;

    if (d<=0) return false;            // d must be positive

    int days_in_month = 31;            // most months have 31 days

    switch (m) {
case Date::feb:                        // the length of February varies
    days_in_month = (leapyear(y))?29:28;
    break;
case Date::apr: case Date::jun: case Date::sep: case Date::nov:
    days_in_month = 30;                // the rest have 30 days
    break;
    }

    if (days_in_month<d) return false;

    return true;
} 
//Checks that time format with Am or Pm is valid
bool is_timea(int h, int  mmn, int s, Time::AmPm xx)
{
	// check that y is valid
	if (h<0||mmn<0||s<0||h>12||s>59||mmn>59) return false;             // valid number check

									   // check that m is valid

	return true;
}
//Checks if time format without Am/Pm is valid
bool is_time(int h, int  mmn, int s) 
{
	// check that y is valid
	if (h < 0 || mmn < 0 || s < 0 || h>24 || s>59 || mmn>59)
	{
		return false;
	}
	else {

	}

	return true;
}
//------------------------------------------------------------------------------

bool leapyear(int y)
{
    // See exercise ???
    return false;
}

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}
// == operator to compare two times
bool operator==(const Time& o, const Time& z)
{
	return o.hour() == z.hour()
		&& o.minute() == z.minute()
		&& o.second() == z.second()
		&& o.am() == z.am();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}
// creating != operator to determine if two times aren't equal
bool operator!=(const Time& a, const Time& b)
{
	return !(a == b);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os  << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
	
}
//For Printing Time variables
ostream& operator<<(ostream& os, const Time& d)
{
	return os << d.hour() << ": "
		<< d.minute() << ": "
		<< d.second();

}
//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    dd = Date(y,Date::Month(m),d);     // update dd
    return is;
}

//------------------------------------------------------------------------------

enum Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};

//------------------------------------------------------------------------------

Day day_of_week(const Date& d)
{
    // ...
    return sunday;
}

//------------------------------------------------------------------------------

Date next_Sunday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------
