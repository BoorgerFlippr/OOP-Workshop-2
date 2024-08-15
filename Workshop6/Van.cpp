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
#include"Van.h"

using namespace std;
namespace sdds
{
	void Van::rmSpace(string& str)
	{
		//removes trailing/leading spaces
		str.erase(str.find_last_not_of(' ') + 1);
		str.erase(0, str.find_first_not_of(' '));
	}

	Van::Van(istream& is)
	{
		string tag{}, maker{}, type{}, purpose{}, condition{}, speed{};
		getline(is, tag, ',');
		getline(is, maker, ',');
		getline(is, type, ','); //if
		getline(is, purpose, ','); //if
		getline(is, condition, ','); //if
		rmSpace(tag);
		if (tag == "v" || tag == "V")
		{
			getline(is, speed);
		}
		else if (tag == "l" || tag == "L")
		{
			getline(is, speed, ',');
		}

		rmSpace(maker);
		rmSpace(type);
		rmSpace(purpose);
		rmSpace(condition);
		rmSpace(speed);

		m_maker = maker;
		m_topSpeed = stod(speed);

		//the token representing the type of van is different
		if (type == "p")
			m_type = "pickup";
		else if (type == "m")
			m_type = "mini-bus";
		else if (type == "c")
			m_type = "camper";
		else
			throw "Invalid record!";

		//the token representing the purpose of van is different
		if (purpose == "d")
			m_purpose = "delivery";
		else if (purpose == "p")
			m_purpose = "passenger";
		else if (purpose == "c")
			m_purpose = "camping";
		else
			throw "Invalid record!";

		//the token representing the condition of van is different
		if (condition == "n")
			m_condition = "new";
		else if (condition.size() == 0)
			m_condition = "new";
		else if (condition == "u")
			m_condition = "used";
		else if (condition == "b")
			m_condition = "broken";
		else
			throw "Invalid record!";

	}

	string Van::condition() const
	{
		return m_condition;
	}

	double Van::topSpeed() const
	{
		return m_topSpeed;
	}

	string Van::type() const
	{
		return m_type;
	}

	string Van::usage() const
	{
		return m_purpose;
	}

	void Van::display(ostream& out) const
	{
		out << "| ";
		out << right << setw(8) << m_maker;
		out << " | ";
		out << left << setw(12) << m_type;
		out << " | ";
		out << left << setw(12) << m_purpose;
		out << " | ";
		out << left << setw(6) << m_condition;
		out << " | ";
		out << fixed;
		out << left << setw(6) << setprecision(2) << m_topSpeed;
		out << " |";
	}
}