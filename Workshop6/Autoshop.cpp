/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include "Autoshop.h"

using namespace std;
namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);

		return *this;
	}

	void Autoshop::display(ostream& out) const
	{
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
		{
			(*it)->display(out);
			out << endl;
		}
	}

	Autoshop::~Autoshop()
	{
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
		{
			delete* it;
		}
	}
}