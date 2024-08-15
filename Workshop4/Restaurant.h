/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 08 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include<iostream>
#include"Reservation.h"

namespace sdds
{
	class Restaurant
	{
		sdds::Reservation** m_arrRes = nullptr;
		size_t m_cnt = 0;
	public:
		Restaurant(const sdds::Reservation*[], size_t);
		Restaurant(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant& operator=(const Restaurant&);
		Restaurant& operator=(Restaurant&&);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};

	//std::ostream& operator<<(std::ostream&, const Restaurant&);
}

#endif // !SDDS_RESTAURANT_H
