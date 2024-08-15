/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 10 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include<string>
#include<list>
#include<vector>

namespace sdds
{
	struct Crime
	{
		std::string m_province{};
		std::string m_district{};
		std::string m_crime{};
		int m_cases{};
		int m_year{};
		int m_resolved{};
	};

	class CrimeStatistics
	{
		std::vector<Crime> m_crimeList;
	public:
		CrimeStatistics(std::string);
		void display(std::ostream&) const;
		void sort(std::string);
		void cleanList();
		bool inCollection(std::string) const;
		std::list<Crime> getListForProvince(std::string) const;
	};

	std::ostream& operator<<(std::ostream&, const Crime&);
}
#endif // !SDDS_CRIMESTATISTICS_H
