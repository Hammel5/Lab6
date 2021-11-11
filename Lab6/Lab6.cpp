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
#include <string>
#include <vector>
#include <fstream> // Allows for File Read and Write

using namespace std;

int binaryToDecimal(string binary);
string check(string line);

int main()
{
	ifstream inFile; 
	inFile.open("BinaryIn.dat"); //opens the file

	string input;
	vector<string> binaryNumber;
	int numOutput;

	while (getline(inFile, input))
	{
		binaryNumber.push_back(check(input));
	}

	cout << "Binary Number\t\tDecimal Equivalent\n";

	for (int i = 0; i < binaryNumber.size(); i++) // loops through the binary numbers and runs the conversion and then outputs the results
	{
		numOutput = binaryToDecimal(binaryNumber[i]);
		if (numOutput == 0) 
		{
			cout << "Bad digit on input" << endl;
		}
		else // Prints out if the binary number is valid
		{
			cout << binaryNumber[i] << "\t\t\t" << numOutput << endl;
		}
	}

	inFile.close(); //closes the file

	return 0;

}

int binaryToDecimal(string binaryNum) // This function turns a binary number into a decimal number
{
	string binary = binaryNum;
	int decimal = 0;
	int base = 1;

	int len = binary.length();
	for (int i = len - 1; i >= 0; i--) //loops through the string backwards
	{
		if (binary[i] == '1') // looks for a 1 and will continue until found
			decimal += base;
		base = base * 2;
	}
	return decimal;
}

string check(string line)
{
	bool pass = false;
	string newLine;
	char c;

	for (int i = 0; i < line.length(); i++) 
	{
		c = line.at(i);

		if (c == '1') 
		{
			newLine.push_back(c);
			pass = true;
		}
		else if (c == '0' && pass) 
		{
			newLine.push_back(c);
		}
		else if (c == '_' && !pass) 
		{

		}
		else if (c != '0') 
		{
			return "Bad digit on input";
		}
	}
	return newLine;
}