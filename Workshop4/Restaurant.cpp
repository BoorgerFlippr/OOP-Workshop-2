/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 08 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include<iostream>
#include"Restaurant.h"

using namespace std;
namespace sdds
{
	Restaurant::Restaurant(const Reservation* res[], size_t cnt)
	{
		m_arrRes = new Reservation * [cnt];
		for (size_t i = 0; i < cnt; i++)
		{
			m_arrRes[i] = new Reservation(*res[i]);
		}
		m_cnt = cnt;

	}

	Restaurant::~Restaurant()
	{
		if (m_arrRes != nullptr)
		{
			for (size_t i = 0; i < m_cnt; i++)
			{
				delete m_arrRes[i];
				m_arrRes[i] = nullptr;
			}
		}

		delete[] m_arrRes;
		m_arrRes = nullptr;
	}

	Restaurant::Restaurant(const Restaurant& src)
	{
		m_arrRes = nullptr;
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src)
		{
			if (m_arrRes != nullptr)
			{
				for (size_t i = 0; i < m_cnt; i++)
				{
					delete m_arrRes[i];
					m_arrRes[i] = nullptr;
				}
			}
			delete[] m_arrRes;
			m_cnt = src.m_cnt;

			if (src.m_arrRes != nullptr)
			{
				m_arrRes = new Reservation * [m_cnt];
				for (size_t i = 0; i < m_cnt; i++)
				{
					m_arrRes[i] = new Reservation(*src.m_arrRes[i]);
				}
			}
		}

		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src)
	{
		m_arrRes = nullptr;
		*this = move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src)
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

	size_t Restaurant::size() const
	{
		return m_cnt;
	}

	ostream& operator<<(ostream& os, const Restaurant& r)
	{
		static int call_cnt = 0;
		call_cnt++;

		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << call_cnt << ")" << endl;
		os << "--------------------------" << endl;
		if (r.m_arrRes != nullptr)
		{
			for (size_t i = 0; i < r.m_cnt; i++)
				os << *r.m_arrRes[i];
		}
		else
			os << "This restaurant is empty!" << endl;
		os << "--------------------------" << endl;

		return os;
	}

}