/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 17 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include<iostream>
#include<iomanip>
#include<string>
#include"Book.h"

using namespace std;

namespace sdds
{
	Book::Book() : m_author{}, m_title{}, m_country{}, m_desc{}
	{
		m_price = 0;
		m_year = 0u;
	}

	const string& Book::title() const
	{
		return m_title;
	}

	const string& Book::country() const
	{
		return m_country;
	}

	const size_t& Book::year() const
	{
		return  m_year;
	}

	double& Book::price()
	{
		return m_price;
	}

	Book::Book(const string& strBook)
	{
		string tAuthor, tTitle, tCountry, tDesc, tPrice, tYear;
		string tBook = strBook;

		tAuthor = tBook.substr(0, tBook.find(','));
		tBook.erase(0, tAuthor.size() + 1);
		tTitle = tBook.substr(0, tBook.find(','));
		tBook.erase(0, tTitle.size() + 1);
		tCountry = tBook.substr(0, tBook.find(','));
		tBook.erase(0, tCountry.size() + 1);
		tPrice = tBook.substr(0, tBook.find(','));
		tBook.erase(0, tPrice.size() + 1);
		tYear = tBook.substr(0, tBook.find(','));
		tBook.erase(0, tYear.size() + 1);
		tDesc = tBook.substr(0, tBook.find('\n'));
		tBook.erase(0, tDesc.size() + 1);

		tAuthor.erase(tAuthor.find_last_not_of(' ') + 1);
		tAuthor.erase(0, tAuthor.find_first_not_of(' '));
		tTitle.erase(tTitle.find_last_not_of(' ') + 1);
		tTitle.erase(0, tTitle.find_first_not_of(' '));
		tCountry.erase(tCountry.find_last_not_of(' ') + 1);
		tCountry.erase(0, tCountry.find_first_not_of(' '));
		tPrice.erase(tPrice.find_last_not_of(' ') + 1);
		tPrice.erase(0, tPrice.find_first_not_of(' '));
		tYear.erase(tYear.find_last_not_of(' ') + 1);
		tYear.erase(0, tYear.find_first_not_of(' '));
		tDesc.erase(tDesc.find_last_not_of(' ') + 1);
		tDesc.erase(0, tDesc.find_first_not_of(' '));

		m_author = tAuthor;
		m_title = tTitle;
		m_country = tCountry;
		m_desc = tDesc;
		m_year = stoi(tYear);
		m_price = stod(tPrice);
	}

	ostream& operator<<(ostream& os, const Book& bk)
	{
		//author: right 20, title: right 22, country: right 5, year: 4, price: right 6 2decimal place, desc: left
		os << right << setw(20) << bk.m_author << " | ";
		os << right << setw(22) << bk.m_title << " | ";
		os << right << setw(5) << bk.m_country << " | ";
		os << setw(4) << bk.m_year << " | ";
		os << fixed;
		os << right << setw(6) << setprecision(2) << bk.m_price << " | ";
		os << bk.m_desc << endl;

		return os;
	}
}