/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include<iostream>
#include<iomanip>
#include<string>
#include"Luxuryvan.h"

using namespace std;
namespace sdds
{
	void Luxuryvan::rmSpace(string& str)
	{
		//removes trailing/leading spaces
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
	}

	Luxuryvan::Luxuryvan(istream& in) : Van(in)
	{
		string consump{};
		getline(in, consump);

		rmSpace(consump);
		
		if (consump == "E" || consump == "e")
			m_consumption = "electric van";
		else if (consump == "G" || consump == "g")
		{
			m_consumption = consump;
			throw "Invalid record!";
		}

	}

	void Luxuryvan::display(ostream& out) const
	{
		if (m_consumption == "electric van")
		{
			Van::display(out);
			out << " " << m_consumption << "  *";
		}
	}

	string Luxuryvan::consumption() const
	{
		return m_consumption;
	}


}