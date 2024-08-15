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
#include"Car.h"

using namespace std;
namespace sdds
{
	void Car::rmSpace(string& str)
	{
		//removes trailing/leading spaces
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
	}

	void Car::setSpeed(double bt)
	{
		//for racecar module
		m_topSpeed = m_topSpeed + (m_topSpeed * bt);
	}

	Car::Car(istream& is)
	{
		string maker{}, condition{}, speed{}, tag{};
		size_t numFound; // flag for when num is found
		getline(is, tag, ',');
		getline(is, maker, ',');
		getline(is, condition, ',');
		//getline(is, speed, '\n');
		rmSpace(tag);
		if (tag == "c" || tag == "C")
		{
			//getline(is, speed);
			is >> speed;
		}
		else if (tag == "r" || tag == "R")
		{
			getline(is, speed, ',');
		}

		rmSpace(maker);
		rmSpace(condition);
		rmSpace(speed);

		m_maker = maker;
		
		//token representing condition of car
		//token representing condition is wrong
		if (condition == "n")
			m_condition = "new";
		else if (condition == "u")
			m_condition = "used";
		else if (condition == "b")
			m_condition = "broken";
		else if(condition.size() == 0)
			m_condition = "new";
		else
			throw "Invalid record!";

		// token for speed is not  a number
		numFound = speed.find_first_not_of("1234567890");
		if (numFound)
			m_topSpeed = stod(speed);
		else
			throw "Invalid record!";


	}

	string Car::condition() const
	{
		return m_condition;
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(ostream& out) const
	{
		out << "| ";
		out << right << setw(10) << m_maker;
		out << " | ";
		out << left << setw(6) << m_condition;
		out << " | ";
		out << fixed;
		out << left << setw(6) << setprecision(2) << m_topSpeed;
		out << " |";
	}
}