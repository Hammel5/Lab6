/*
	Dalton Hammel
	C++ Fall 2021
	Due: 11/10/2021
	Lab 6 Binary to Decimal Conversion

	Write a C++ program that reads characters representing binary (base 2) 
	numbers from a data file called BinaryIn.dat and translates them to decimal (base 10) 
	numbers. The binary and decimal numbers should be output in two columns with appropriate headings. 
	There is only one binary number per input line, but an arbitrary number of blanks can
	precede the number.  The program must read the binary numbers one character at a
	time.  As each character is read, the program multiplies the total decimal value by 2 and
	adds either a 1 or 0, depending on the input character.  The program should check for
	bad data; if it encounters anything except a 1 or 0, it should output the message “Bad
	digit on input.”  The maximum number of spaces that could exist between any two digits
	of a binary number in the input file will be one, in which case, the binary digit would be
	considered bad.  The output for this program should be to the screen and not an output
	file.  In order to read in one character at a time, you will need to use the cin.get
	command.
*/

#include <iostream> // Allows the ability to input and output 
#include <iomanip> // Allows to use the setw() function
#include <cmath>
#include <stdlib.h>
#include <fstream> // Allows for File Read and Write

using namespace std;

void binaryToDecimal(string n);

int main()
{
	ifstream inFile;
	inFile.open("BinaryIn.dat");

	bool isGood = true;
	string temp;

	char c;
	do
	{
		inFile >> temp;
		inFile.get(c);

		cout << c << endl;
		int s = c - '0';
		if (s == 1 || s == 0 || isspace(c))
		{
			binaryToDecimal(temp);
			cout << endl;
			isGood = true;
		}
		else 
		{
			cout << "bad" << endl;
			isGood = false;
		}
	} while (isGood && inFile);

	inFile.close();

	return 0;

}

void binaryToDecimal(string n)
{
	string num = n;
	int dec_value = 0;
	int base = 1;

	int len = num.length();
	for (int i = len - 1; i >= 0; i--) 
	{
		if (num[i] == '1')
			dec_value += base;
		base = base * 2;
	}
	cout << dec_value;
}