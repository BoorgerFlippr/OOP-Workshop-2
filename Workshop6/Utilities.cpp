/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#include<string>
#include<sstream>
#include"Utilities.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(istream& in)
	{


		string str{};
		size_t idx = 0; //index to store address of tag e.g. 'c' or 'R'
		char ch ='c';
		Vehicle* instance = nullptr;
		getline(in, str);
		idx = str.find_first_not_of(' '); //just incase the first char of in is not a letter
		ch = str[0];
		if (ch == ' ')
			ch = str[idx];
		stringstream ss(str);
		

		if (str.empty() == false)
		{
			if (ch == 'c' || ch == 'C')
				instance = new Car(ss);
			else if (ch == 'v' || ch == 'V')
				instance = new Van(ss);
			else if (ch == 'r' || ch == 'R')
				instance = new Racecar(ss);
			else if (ch == 'l' || ch == 'L')
				instance = new Luxuryvan(ss);
			else
			{

				throw ch;
			}
		}

		return instance;
	}
}