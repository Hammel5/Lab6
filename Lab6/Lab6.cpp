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
string binaryChecking(string line);

int main()
{
	ifstream inFile;
	inFile.open("BinaryIn.dat");

	string input;
	vector<string> binaryNumber;
	int numOutput;

	while (getline(inFile, input))
	{
		binaryNumber.push_back(binaryChecking(input));
	}

	for (int i = 0; i < binaryNumber.size(); i++) 
	{
		numOutput = binaryToDecimal(binaryNumber[i]);
		if (numOutput == 0) 
		{
			cout << "Bad digit on input" << endl;
		}
		else 
		{
			cout << numOutput << endl;
		}
	}

	inFile.close();

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

string binaryChecking(string line)
{
	//declare variables
	bool numberPassed = false;
	string newLine;
	char lineChar;

	//loop through all the inputs and look for errors
	for (int i = 0; i < line.length(); i++) {
		lineChar = line.at(i);

		//check if the number 1 has passed yet
		if (lineChar == '1') {
			newLine.push_back(lineChar);
			numberPassed = true;
		}
		//if 1 has passed then 0 can too
		else if (lineChar == '0' && numberPassed) {
			newLine.push_back(lineChar);
		}
		//do nothin if this comes up (aka it wont be added to newLine)
		else if (lineChar == '_' && !numberPassed) {

		}
		//if there is a char that is not 0, 1, or _, then the number will be void
		else if (lineChar != '0') {
			return "Bad digit on input";
		}
	}
	return newLine;
}