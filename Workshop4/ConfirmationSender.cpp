/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 08 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include "ConfirmationSender.h"
#include <iostream>

using namespace std;
namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
		m_arrRes = nullptr;
		m_cnt = 0;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		m_arrRes = nullptr;
		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		m_arrRes = nullptr;
		*this = move(src);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src)
		{
			delete[] m_arrRes;
			m_cnt = src.m_cnt;

			if (src.m_arrRes != nullptr)
			{
				m_arrRes = new const Reservation * [m_cnt];
				for (size_t i = 0; i < m_cnt; i++)
					m_arrRes[i] = src.m_arrRes[i];
			}
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src)
		{
			delete[] m_arrRes;
			m_cnt = src.m_cnt;
			
			m_arrRes = src.m_arrRes;
			src.m_arrRes = nullptr;
			src.m_cnt = 0;
		}

		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_arrRes;
		m_arrRes = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& r)
	{
		int found = 0;
		for (size_t i = 0; i < m_cnt; i++)
		{
			if (m_arrRes[i] == &r)
			{
				found = 1;
				break;
			}
		}

		if (found == 0)
		{

			const Reservation** temp = new const Reservation * [m_cnt + 1];
			for (size_t i = 0; i < m_cnt; i++)
				temp[i] = m_arrRes[i];
			temp[m_cnt] = &r;

			delete[] m_arrRes;
			m_arrRes = temp;
			m_cnt++;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& r)
	{
		int found = 1;
		size_t i = 0;
		for (i = 0; i < m_cnt; i++)
		{
			if (m_arrRes[i] == &r)
			{
				found = 0;
				break;
			}
		}

		if (found == 0)
		{
			m_arrRes[i] = nullptr;
		}

		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& cs)
	{

		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (cs.m_arrRes != nullptr)
		{
			for (size_t i = 0; i < cs.m_cnt; i++)
			{
				//os << *cs.m_arrRes[i];

				if (cs.m_arrRes[i] != nullptr)
				{
					os << *cs.m_arrRes[i];
				}

			
			}
		}
		else
			os << "There are no confirmations to send!" << endl;
		os << "--------------------------" << endl;

		return os;
	}

}