//Name: Ethan Thomas
//
//Class: CS & 131 Section: A
//
//Description: This program will open a valid file assuming 
//the user enters the correct file name followed with the file extension. 
//If these requirements are met, then the program will read the file and
//total the number of words by their lengths. Then it will output the 
//results to the user and also tell the user the total amount
//of words.



#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int total_words = 0;
	int length[9] = {};
	ifstream fin;
	string user_input = " ";
	string read_file = " ";
	
	
	cout << "Please enter the file you would like a report on"
		 << " (or type exit to quit):";
	cin >> user_input;
	fin.open(user_input);
	
	while (fin.fail())
	{
		cout << "Unable to find the input file." << endl;
		cout << "Please enter the file you would like a report on" 
			 <<" (or type exit to quit): " << endl;
		cin >> user_input;
		fin.open(user_input);

		if (user_input == "exit")
		{
			exit(0);
		}


	}

		do
		{
			if (fin >> read_file)
			{
				++total_words;
				int i;
				
				for (i = 0; read_file[i] != '\0'; ++i);
				
				if (i > 8)
				{
					length[8] += 1;
				}
				
				else
				{
					length[i - 1] += 1;
				}

			}

		} while (!fin.eof());
		
		system("CLS");

		cout << "~Word Report for " << user_input << ":" << endl;
		cout << "Length:\t" << "\tCount:" << endl;
		
		int i;
		for (i = 0; i < 8; ++i)
		{
			cout << setw(2) << i + 1 << "\t\t" << setw(3) << length[i] << endl;
		}

		cout << setw(1) <<  ">" << i << "\t\t" << setw(3) << length[i] << endl;
		cout << "Total words in the file: " << total_words << endl;
		system("pause");
		return 0;
	
}

//Output:
//Please enter the file you would like a report on (or type exit to quit) :infile.txt
//~Word Report for infile.txt :
//	Length : Count :
//	1               42
//	2               91
//	3              103
//	4              115
//	5               57
//	6               47
//	7               25
//	8               27
// >8               17
//   Total words in the file : 524
