/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include"Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster = 0;
		void rmSpace(std::string&);
	public:
		Racecar(std::istream&);
		void display(std::ostream&) const;
		double topSpeed() const;
	};
}

#endif // !SDDS_RACECAR_H



