/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 17 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include"SpellChecker.h"

using namespace std;

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);
		string temp{};

		if (!file)
			throw "Bad file name!";
		else
		{
			do
			{
				for (int i = 0; i < 6; i++)
				{
					getline(file, temp, ' ');
					m_badWords[i] = temp;
					getline(file, temp);
					temp.erase(0, temp.find_first_not_of(' '));
					m_goodWords[i] = temp;
					m_occurances[i] = 0;
				}
				if (file.eof())
					break;
			} while (file);
			file.close();
		}
	}

	void SpellChecker::operator()(string& text)
	{
	
		for (int i = 0;i < 6; i++)
		{
			while (text.find(m_badWords[i]) != string::npos)
			{
				size_t found = text.find(m_badWords[i]);
				text.replace(found, m_badWords[i].length(), m_goodWords[i]);
				m_occurances[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (int i = 0; i < 6; i++)
		{
			out << right << setw(15) << m_badWords[i];
			out << ": " << m_occurances[i] << " replacements" << endl;
		}
	}
}