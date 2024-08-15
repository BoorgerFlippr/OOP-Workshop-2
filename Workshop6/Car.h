/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include"Vehicle.h"
#include<string>

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed = 0;
		void rmSpace(std::string&);
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
	protected:
		void setSpeed(double); //for racecar only

	};
}
#endif // !SDDS_CAR_H
