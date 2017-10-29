//Sriram Natarajan
//Hw6_Pr2
//10-11-17
//This program finds the location of each lowercase upper case and number in the file hw6pr22017.txt
#include "std_lib_facilities_5.h"
const char FileName[] = "hw6Fall2017.txt";
int main()
{
	//using ifstream to load file
	ifstream InputFile;
	InputFile.open(FileName);
	//intializing arrays
	int UpperCase[26] = { 0 };
	int LowerCase[26] = { 0 } ;
	int Numbers[10] = { 0 };
	char tempChar;
	//temporary index number while going through the file the first time
	int UpperCasePosition = 1;
	// until reaching the end of the file
	while (!InputFile.eof())
	{
		// get the current charachter while going through the file
		InputFile.get(tempChar);
		if (tempChar >= 'A' && tempChar <= 'Z' && UpperCase[tempChar - 'A'] == 0)
		{
			UpperCase[tempChar - 'A'] = UpperCasePosition;
		}
		//Going through each Charahcter position including spaces
		UpperCasePosition = UpperCasePosition + 1;
	}
	//Now that we have reached the bottom of the file we need to reset and go start back at the top
	InputFile.clear();
	InputFile.seekg(0);
	int NumberPosition = 1;
	while (!InputFile.eof()) 
	{
		InputFile.get(tempChar);
		if (tempChar >= '0' && tempChar <= '9' && Numbers[tempChar - '0'] == 0)
		{
			Numbers[tempChar - '0'] = NumberPosition;
		}
		NumberPosition = NumberPosition + 1;
	}
	InputFile.clear();
	InputFile.seekg(0);
	int LowerPosition = 1;
	while (!InputFile.eof()) 
	{
		InputFile.get(tempChar);
		if (tempChar >= 'a' &&  tempChar <= 'z' && LowerCase[tempChar - 'a'] == 0) 
		{
				LowerCase[tempChar - 'a'] = LowerPosition;
		}
		LowerPosition = LowerPosition + 1;
	}
	//since cout doesn't give desired ouput had to use printf
	for (int i = 0; i<5; i++) {
		if (UpperCase[i] == 0) {
			//pulled this printf statement from stackoverflow
			printf("%c %6s ", ('A' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('A' + i), UpperCase[i]);
		}
	}
	cout << endl;
	for (int i = 5; i<10; i++) {
		if (UpperCase[i] == 0) {
			printf("%c %6s ", ('A' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('A' + i), UpperCase[i]);
		}
	}
	cout << endl;
	for (int i = 10; i<15; i++) {
		if (UpperCase[i] == 0) {
			printf("%c %6s ", ('A' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('A' + i), UpperCase[i]);
		}
	}
	cout << endl;
	for (int i = 15; i<20; i++) {
		if (UpperCase[i] == 0) {
			printf("%c %6s ", ('A' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('A' + i), UpperCase[i]);
		}
	}
	cout << endl;
	for (int i = 20; i<25; i++) {
		if (UpperCase[i] == 0) {
			printf("%c %6s ", ('A' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('A' + i), UpperCase[i]);
		}
	}
	cout << endl;
	printf("%c %6d ", ('A' + 25), UpperCase[25]);
	printf("%c %6d ", ('0'), Numbers[0]);
	printf("%c %6d ", ('1'), Numbers[1]);
	printf("%c %6d ", ('2'), Numbers[2]);
	printf("%c %6s ", ('3'), "NotFnd");
	cout << endl;
	printf("%c %6d ", ('4'), Numbers[4]);
	printf("%c %6d ", ('5'), Numbers[5]);
	for (int i = 6; i<9; i++) {
		if (i % 5 == 0) {
			printf("\n");
		}
		if (Numbers[i] == 0) {
			printf("%c %6s ", ('0' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('0' + i), Numbers[i]);
		}
	}
	cout << endl;
	printf("%c %6d ", ('9'), Numbers[9]);
	printf("%c %6d ", ('a'), UpperCase[0]);
	printf("%c %6d ", ('b'), UpperCase[1]);
	printf("%c %6d ", ('c'), UpperCase[2]);
	printf("%c %6d ", ('d'), UpperCase[3]);
	cout << endl;
	for (int i = 4; i<9; i++) {
		if (LowerCase[i] == 0) {
			printf("%c %6s ", ('a' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('a' + i), LowerCase[i]);
		}
	}
	cout << endl;
	for (int i = 9; i<14; i++) {
		if (LowerCase[i] == 0) {
			printf("%c %6s ", ('a' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('a' + i), LowerCase[i]);
		}
	}
	cout << endl;
	for (int i = 14; i<19; i++) {
		if (LowerCase[i] == 0) {
			printf("%c %6s ", ('a' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('a' + i), LowerCase[i]);
		}
	}
	cout << endl;
	for (int i = 19; i<24; i++) {
		if (LowerCase[i] == 0) {
			printf("%c %6s ", ('a' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('a' + i), LowerCase[i]);
		}
	}
	cout << endl;
	for (int i = 24; i<26; i++) {
		if (LowerCase[i] == 0) {
			printf("%c %6s ", ('a' + i), "NotFnd");
		}
		else {
			printf("%c %6d ", ('a' + i), LowerCase[i]);
		}
	}
	//system("pause");

}