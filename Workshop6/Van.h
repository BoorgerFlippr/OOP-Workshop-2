/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include"Vehicle.h"
#include<string>

namespace sdds
{
	class Van : public Vehicle
	{
		std::string m_maker{};
		std::string m_type{};
		std::string m_condition{};
		std::string m_purpose{};
		double m_topSpeed = 0;
		void rmSpace(std::string&);
	public:
		Van(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream&) const;
	};
}
#endif // !SDDS_VAN_H
