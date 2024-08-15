/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 08 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include<iostream>
#include"Reservation.h"

namespace sdds
{
	//ConfirmationSender
	class ConfirmationSender
	{
		const sdds::Reservation** m_arrRes;
		size_t m_cnt = 0;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender(ConfirmationSender&&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation&);
		ConfirmationSender& operator-=(const Reservation&);
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H
