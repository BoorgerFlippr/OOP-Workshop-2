/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 08 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

namespace sdds
{
	class Reservation
	{
		std::string m_reservationId{};
		std::string m_name{};
		std::string m_email{};
		int m_numPeople = 0;
		int m_day = 0;
		int m_hour = 0;
	public:
		Reservation();
		void update(int, int);
		Reservation(const std::string&);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}

#endif // !SDDS_RESERVATION_H
