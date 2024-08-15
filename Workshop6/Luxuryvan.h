/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include "Van.h"

namespace sdds
{
	class Luxuryvan : public Van
	{
		std::string m_consumption{};
		void rmSpace(std::string&);
	public:
		Luxuryvan(std::istream&);
		void display(std::ostream&) const;
		std::string consumption() const;
	};
}

#endif // !SDDS_LUXURYVAN_H
