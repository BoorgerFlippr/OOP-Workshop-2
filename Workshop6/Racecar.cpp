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
#include"Racecar.h"

using namespace std;
namespace sdds
{
	void Racecar::rmSpace(std::string& str)
	{
		//removes trailing/leading spaces
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
	}

	Racecar::Racecar(istream& is) : Car(is)
	{
		string boost{};
		getline(is, boost);

		rmSpace(boost);
		m_booster = stod(boost);

		Car::setSpeed(m_booster);

	}

	void Racecar::display(ostream& out) const
	{
		Car::display(out);
		out << '*';
	}

	double Racecar::topSpeed() const
	{
		return Car::topSpeed();
	}
}