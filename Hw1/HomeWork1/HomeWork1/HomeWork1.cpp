
/* 
   Sriram Natarajan Programmer 
   Fall Semester 2017 (September 5th)
   Solution for  HW1 Exercise 13 Chapter 4
   Used nested for loops and boolean array to
   find all primes from 1 to 100 using the Sieve 
   of Eratosthenes method
   
 */
#include "std_lib_facilities_4.h"

int main() {
	bool allnumbers [100] = { false };
	int i = 0;
	int j = 0;
	int prime_location = 0;
	int not_prime_location = 0;
	for ( i = 2; i <= 10; ++i) {
		for (j = 2; j <= 100 / i; ++j) {
			not_prime_location = i*j;
			allnumbers[not_prime_location] = true;
		};
	};
	cout << " The primes from 1 to 100 are:" << endl;
	for ( prime_location = 0; prime_location < 100; ++prime_location) {
		if (prime_location > 1 && allnumbers[prime_location] == 0) {
			cout << prime_location << endl;
		};
	};
	//system("pause");
	return 0;

}
