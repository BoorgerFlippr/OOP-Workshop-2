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
#include"Movie.h"

using namespace std;
namespace sdds
{
	Movie::Movie() : m_title{}, m_desc{}
	{
		m_year = 0u;
	}

	const string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		string tTitle, tYear, tDesc;
		string tMovie = strMovie;

		tTitle = tMovie.substr(0, tMovie.find(','));
		tMovie.erase(0, tTitle.size() + 1);
		tYear = tMovie.substr(0, tMovie.find(','));
		tMovie.erase(0, tYear.size() + 1);
		tDesc = tMovie.substr(0, tMovie.find('\n'));
		tMovie.erase(0, tDesc.size() + 1);

		tTitle.erase(tTitle.find_last_not_of(' ') + 1);
		tTitle.erase(0, tTitle.find_first_not_of(' '));
		tYear.erase(tYear.find_last_not_of(' ') + 1);
		tYear.erase(0, tYear.find_first_not_of(' '));
		tDesc.erase(tDesc.find_last_not_of(' ') + 1);
		tDesc.erase(0, tDesc.find_first_not_of(' '));

		m_title = tTitle;
		m_year = stoi(tYear);
		m_desc = tDesc;
	}

	ostream& operator<<(ostream& os, const Movie& mv)
	{
		os << right << setw(40) << mv.m_title << " | ";
		os << setw(4) << mv.m_year << " | ";
		os << mv.m_desc << endl;

		return os;
	}
}