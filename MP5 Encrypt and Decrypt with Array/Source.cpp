//Justin Ritchey -- 6/30/2020 -- Machine problem 5 - Arrays
//I am deisgning a program that should accept a "keyword" and apply this to an array. Then make the array be able to encode and decode certain phrases such that uppercase words will decode and lowercase will encode

#include <iostream>
#include <string>
#include <vector>
#include <ostream>

using namespace std;


int main()
{
	
	int row = 0;
	int column = 0;
	string keyword = "";
	string newAlphabet = "";
	string alaphabet = "abcdefghijklmnopqrstuvwxy";
	string newKeyword = "";
	int keywordLength = 0;




	cout << "Please enter the keyword: "<< endl;                         //asking for keyword
	cin >> keyword;

	for (int i = 0;keyword[i];i++)                                       //getting length of entered keyword
	{
		keywordLength = i+1;
	}
	
	vector<char> redundentChecker(keywordLength, 0);                     //creating vector with the length of the keyword
	
	copy(keyword.begin(), keyword.end(), redundentChecker.begin());      //copying input string keyword to the characater vector

	for (const char c : redundentChecker)                                //Checking if vector has the correct characters
	{
		cout << c << " ";
	}

	std::cout << removeDuplicate(redundentChecker, keywordLength)

	cout << endl;

	char codeArray[5][5] = { { 'A','B','C','D','E' }, { 'F', 'G', 'H', 'I', 'J' }, { 'K', 'L', 'M', 'M', 'O' }, { 'P', 'Q', 'R', 'S', 'T' }, { 'U', 'V', 'W', 'X', 'Y' } };

	for (row = 0;row < 5;row++) 
{
	for (column = 0;column < 5;column++)
	{
		cout << codeArray[row][column];
	}
	cout << endl;
}
//for (int i = 0; i < 5;i++) cout << codeArray[i];

		
}




char* removeDuplicate(char redundentChecker[], int keywordLength)
{
	int index = 0;

	for (int i = 0;i < keywordLength;i++)
	{
		for (int j = 0;j < i;j++)
		
			if (redundentChecker[i] == redundentChecker[j])
				break;
			if (j == i)
				redundentChecker[index++] = redundentChecker[i];
	}
	return redundentChecker;
}