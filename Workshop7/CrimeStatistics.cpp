/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 10 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include "CrimeStatistics.h"

using namespace std;
namespace sdds
{
	CrimeStatistics::CrimeStatistics(string fileName)
	{
		string line{};
		string prov{}, dist{}, crime{}, numC{}, yr{}, numR{};
		ifstream file(fileName);

		

		do
		{
			getline(file, line);
			if (file)
			{
				stringstream ss(line);
				Crime cr{};

				ss >> prov >> dist >> crime >> yr >> numC >> numR;
				cr.m_province = prov;
				cr.m_district = dist;
				cr.m_crime = crime;
				cr.m_cases = stoi(numC);
				cr.m_year = stoi(yr);
				cr.m_resolved = stoi(numR);

				m_crimeList.push_back(cr);
			}

		} while (file);
		file.close();
	}

	void CrimeStatistics::display(ostream& out) const
	{
		//accumulate  + for each
		int totalC = std::accumulate(m_crimeList.begin(), m_crimeList.end(), 0, [](int num, const Crime c) {return c.m_cases + num;});
		int totalR = std::accumulate(m_crimeList.begin(), m_crimeList.end(), 0, [](int num, const Crime c) {return c.m_resolved + num;});

		std::for_each(m_crimeList.begin(), m_crimeList.end(), [](const Crime c) {cout << c << endl;});

		out << setw(89) << setfill('-') << '\n' << setfill(' ');
		out << "| ";
		out << right << setw(78) << "Total Crimes: ";
		out << right << setw(6) << totalC << " |" << endl;
		out << "| ";
		out << right << setw(78) << "Total Resolved Cases: ";
		out << right << setw(6) << totalR << " |" << endl;
	}

	void CrimeStatistics::sort(string field)
	{
		if (field == "Province")
		{
			std::sort(m_crimeList.begin(), m_crimeList.end(), [](Crime a, Crime b) {return a.m_province < b.m_province;});
		}
		else if (field == "Crime")
		{
			std::sort(m_crimeList.begin(), m_crimeList.end(), [](Crime a, Crime b) {return a.m_crime < b.m_crime;});
		}
		else if (field == "Cases")
		{
			std::sort(m_crimeList.begin(), m_crimeList.end(), [](Crime a, Crime b) {return a.m_cases < b.m_cases;});
		}
		else if (field == "Resolved")
		{
			std::sort(m_crimeList.begin(), m_crimeList.end(), [](Crime a, Crime b) {return a.m_resolved < b.m_resolved;});
		}
	}

	void CrimeStatistics::cleanList()
	{
		//for each
		std::for_each(m_crimeList.begin(), m_crimeList.end(), [](Crime& c) 
			{
				if (c.m_crime == "[None]")
					c.m_crime = "";
			});
	}

	bool CrimeStatistics::inCollection(string crime) const
	{
		
		//any of
		bool found = std::any_of(m_crimeList.begin(), m_crimeList.end(), [crime](Crime c)->bool {return c.m_crime == crime;});

		return found;
	}

	list<Crime> CrimeStatistics::getListForProvince(string province) const
	{
		auto cnt = std::count_if(m_crimeList.begin(), m_crimeList.end(), [province](const Crime c)->bool {return c.m_province == province;});
		list<Crime> cr_province(cnt);

		std::copy_if(m_crimeList.begin(), m_crimeList.end(), cr_province.begin(), [province](const Crime c)->bool {return c.m_province == province;});

		return cr_province;
	}

	ostream& operator<<(ostream& out, const Crime& theCrime)
	{
		out << "| ";
		out << left << setw(21) << theCrime.m_province << " | ";
		out << left << setw(15) << theCrime.m_district << " | ";
		out << left << setw(20) << theCrime.m_crime << " | ";
		out << right << setw(6) << theCrime.m_year << " | ";
		out << right << setw(4) << theCrime.m_cases << " | ";
		out << right << setw(3) << theCrime.m_resolved << " |";
		
		return out;
	}
}