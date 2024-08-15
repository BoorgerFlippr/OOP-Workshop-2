/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 08 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include"Reservation.h"

using namespace std;

namespace sdds
{
	Reservation::Reservation() : m_reservationId{}, m_name{}, m_email{}
	{
		m_numPeople = 0;
		m_hour = 0;
		m_day = 0;
	}

	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}

	Reservation::Reservation(const string& res)
	{
		//temp string to store tokens
		string tId, tName, tEmail, tNumP, tDay, tTime;
		string temp = res;

		//extract tokens
		tId = temp.substr(0, temp.find(':'));
		temp.erase(0, tId.size() + 1);
		tName = temp.substr(0, temp.find(','));
		temp.erase(0, tName.size() + 1);
		tEmail = temp.substr(0, temp.find(','));
		temp.erase(0, tEmail.size() + 1);
		tNumP = temp.substr(0, temp.find(','));
		temp.erase(0, tNumP.size() + 1);
		tDay = temp.substr(0, temp.find(','));
		temp.erase(0, tDay.size() + 1);
		tTime = temp.substr(0, temp.find('\n'));
		temp.erase(0, tTime.size() + 1);

		//remove trailing/leading white spaces
		tId.erase(tId.find_last_not_of(' ') + 1);
		tId.erase(0, tId.find_first_not_of(' '));
		tName.erase(tName.find_last_not_of(' ') + 1);
		tName.erase(0, tName.find_first_not_of(' '));
		tEmail.erase(tEmail.find_last_not_of(' ') + 1);
		tEmail.erase(0, tEmail.find_first_not_of(' '));
		tNumP.erase(tNumP.find_last_not_of(' ') + 1);
		tNumP.erase(0, tNumP.find_first_not_of(' '));
		tDay.erase(tDay.find_last_not_of(' ') + 1);
		tDay.erase(0, tDay.find_first_not_of(' '));
		tTime.erase(tTime.find_last_not_of(' ') + 1);
		tTime.erase(0, tTime.find_first_not_of(' '));

		m_reservationId = tId;
		m_name = tName;
		m_email = tEmail;
		m_numPeople = stoi(tNumP);
		m_day = stoi(tDay);
		m_hour = stoi(tTime);


	}

	ostream& operator<<(ostream& os, const Reservation& rs)
	{
		string howMany = " people";
		if (rs.m_numPeople == 1)
			howMany = " person";

		char* tEmail = nullptr;
		tEmail = new char[rs.m_email.size() + 3];
		tEmail[0] = '<';
		for (size_t i = 1; i < rs.m_email.size() + 1; i++)
			tEmail[i] = rs.m_email.c_str()[i - 1];
		tEmail[rs.m_email.size() + 1] = '>';
		tEmail[rs.m_email.size() + 2] = '\0';

		os << "Reservation ";
		os << setw(10) << right << rs.m_reservationId << ": ";
		os << setw(20) << right << rs.m_name << "  ";
		os << setw(20) << left << tEmail << " ";

		if (rs.m_hour >= 6 && rs.m_hour <= 9)
			os << "   Breakfast on day " << rs.m_day << " @ " << rs.m_hour << ":00 for " << rs.m_numPeople << howMany << '.';
		else if (rs.m_hour >= 11 && rs.m_hour <= 15)
			os << "   Lunch on day " << rs.m_day << " @ " << rs.m_hour << ":00 for " << rs.m_numPeople << howMany << '.';
		else if (rs.m_hour >= 17 && rs.m_hour <= 21)
			os << "   Dinner on day " << rs.m_day << " @ " << rs.m_hour << ":00 for " << rs.m_numPeople << howMany << '.';
		else
			os << "   Drinks on day " << rs.m_day << " @ " << rs.m_hour << ":00 for " << rs.m_numPeople << howMany << '.';
		os << endl;
		delete[] tEmail;
		tEmail = nullptr;
		return os;
	}
}