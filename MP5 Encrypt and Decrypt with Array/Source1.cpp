//Justin Ritchey -- 6/30/2020 -- Machine problem 5 - Arrays
//I am deisgning a program that should accept a "keyword" and apply this to an array. Then make the array be able to encode and decode certain phrases such that uppercase words will decode and lowercase will encode

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <istream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	int row = 0;                                                    //row of the array
	int column = 0;                                                 //column of the array
	string keyword = "";                                            //keyword being used
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";                  //constant of the alphabet being used
    string newWord = "";                                            //combining the keyword and the alphabet
    char codeArray[5][5] = { "" };                                  //creating the array and wil assign the newWord string to it only allowing 25 variables of that string
    int counter = 0;                                                //to be used in the loop to assign all 25 characters of the newword string
    ifstream file("EncyrptAndDecryptCode.txt");                     //file to be used
    char encodeOrDecode = '\0';                                     //getting the char value from the text to either encode or decode
    string code = "";                                               //will hold the string from the text that is either decoded or encoded
    string codeWord = "";                                           //holds the individual words from the code word                                        
    char codeArrayLower[5][5] = { "" };                             //Same array as above but in lower case 
   


    if (file.good()) getline(file, keyword);                        //getting the keyword from the first line of the text


    cout << "The keyword is: " << keyword << "\n\n";                 //printing out the keyword being used

    newWord = keyword + alphabet;                                    //adding keyword string and the alphabet string

    for (string::size_type i = 0; i < newWord.size(); i++)           //removes duplicates from string
    {
        string::size_type j = i + 1;
        while (j < newWord.size())
        {
            if (newWord[i] == newWord[j])
            {
                newWord.erase(j, 1);
            }
            else
            {
                ++j;
            }
        }
    }

    

    cout << "  0 1 2 3 4" << endl;                                   //formatting for the array
    cout << "-----------" << endl;


	for (row = 0;row < 5;row++)                                      //loop for the array to assign the newWord string to all 25 spots
	{
        cout << row << " ";
		for (column = 0;column < 5;column++)
		{
           
            codeArray[row][column] = newWord[counter];
            cout << codeArray[row][column]<< " ";
            counter++;
            

		}
		cout << endl << "-----------" << endl;
	}

    for(int i=0;i<5;i++)                                           //Making both arrays equal to each other
        for (int j = 0; j < 5; j++)
        {
            codeArrayLower[i][j] = codeArray[i][j];
        }

    for (int i = 0;i < 5;i++)                                      //making codeArrayLower into lower case letters
        for (int j = 0; j < 5; j++)
        {
            codeArrayLower[i][j] = tolower(codeArrayLower[i][j]);
        }
     
    cout << "\n\n";                                                //formatting
    cout << "****************************";
    cout << "\n\n";

    file.clear();
    file.seekg(0, ios::beg);

    while (getline(file, code))                                    //starting loop to decode and encode
    {
       
        
        if (code[0] == 'E')                                       //loop for encoding
        {
            code.erase(0, 2);                                     //erasing the first letter and the space after so that only the sentacne that needs to be encoded is left
            
            cout << code << endl;              

            for_each(code.begin(), code.end(), [](char& c) { c = toupper(c); });

            cout << "Dycrpts to: " << endl;       
            
            
            string test2 = "";
            
            for (char c: code)                                    //going word by word to encode
            {
                string test;
                cout << test << test;
                istringstream iss(code);
                iss >> codeWord;
                
                
                

                for (int i = 0;i < 5;i++)
                {

                    for (int j = 0;j < 5;j++)
                    {

                        if (codeArray[i][j] == c)
                        {
                            test += codeArray[j][i];


                        }

                    }


                }

            

                
                

                if (c == ',')                                     //all of the possible variables that are not letters
                    cout << ",";
                else if (c == '-')
                    cout << "-";
                else if (c == '(')
                    cout << "(";
                else if (c == ')')
                    cout << ")";
                else if (c == '1')
                    cout << "1";
                else if (c == '2')
                    cout << "2";
                else if (c == '3')
                    cout << "3";
                else if (c == '4')
                    cout << "4";
                else if (c == '5')
                    cout << "5";
                else if (c == '6')
                    cout << "6";
                else if (c == '7')
                    cout << "7";
                else if (c == '8')
                    cout << "8";
                else if (c == '9')
                    cout << "9";
                else if (c == '0')
                    cout << "0";
                else if (c == '0')
                    cout << "0";
                else if (c == '"')
                    cout << "\"";
                else if (c == '$')
                    cout << "s";
                else if (c == '\'')
                    cout << "'";

                test2 += test;
              
            }

            int num = 0;
            for (int i = 0; test2[i]; i++)
                if (test2[i] != ' ')
                    test2[num++] = test2[i];
           
            cout << test2 << " ";
            test == "";
            num == 0;
            cout << "\n\n" << "******************************************************" << "\n\n";

        }

        else if(code[0] == 'D')                                                              //loops for decoding the sentences
        {
            code.erase(0, 2);                                                                //erasing the first 2 spots in each line so that only the sentence to decode is left

            cout << code << endl;

            for_each(code.begin(), code.end(), [](char& c) { c = tolower(c); });             //changing entered code to lower case to match the array

           cout << "Dycrpts to: " << endl;

            for (char c: code)                                                              //going word by word to deocde the sentence
            { 
                istringstream iss(code);
                iss >> codeWord;
                

                for (int i = 0;i < 5;i++)
                {
                    for (int j = 0;j < 5;j++)
                    {
                       
                        if (codeArrayLower[i][j] == c)
                        {
                            
                            cout  <<  codeArrayLower[j][i];
                            
                        }
                       

                    }
                    

                }
                if (c == ',')                                                                //all other vraibles that are not letters and will not be in the array
                    cout << ",";
                else if (c == '-')
                    cout << "-";
                else if (c == '(')
                    cout << "(";
                else if (c == ')')
                    cout << ")";
                else if (c == '1')
                    cout << "1";
                else if (c == '2')
                    cout << "2";
                else if (c == '3')
                    cout << "3";
                else if (c == '4')
                    cout << "4";
                else if (c == '5')
                    cout << "5";
                else if (c == '6')
                    cout << "6";
                else if (c == '7')
                    cout << "7";
                else if (c == '8')
                    cout << "8";
                else if (c == '9')
                    cout << "9";
                else if (c == '0')
                    cout << "0";
                else if (c == '0')
                    cout << "0";
                else if (c == '"')
                    cout << "\"";
                else if (c == '$')
                    cout << "s";
                else if (c == '\'')
                    cout << "'";


                cout << " ";
            }
            cout << "\n\n" << "******************************************************" << "\n\n";
        }
    }

    return 0;
}