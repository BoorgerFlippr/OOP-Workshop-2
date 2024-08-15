/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 16 / 09 / 25
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iomanip>
#include <iostream>
#include<fstream>
#include"TennisLog.h"

namespace sdds
{
	ostream& operator<<(ostream& os, const TennisMatch& tm)
	{
		if (tm.s_tournamentId.empty())
			os << "Empty Match";
		else
		{
			os << right << setfill('.') << setw(23) << "Tourney ID : "
				<< left << setfill('.') << setw(30) << tm.s_tournamentId << endl;
			os << right << setfill('.') << setw(23) << "Match ID : "
				<< left << setfill('.') << setw(30) << tm.s_matchId << endl;
			os << right << setfill('.') << setw(23) << "Tourney : "
				<< left << setfill('.') << setw(30) << tm.s_tournamentName << endl;
			os << right << setfill('.') << setw(23) << "Winner : "
				<< left << setfill('.') << setw(30) << tm.s_winner << endl;
			os << right << setfill('.') << setw(23) << "Loser : "
				<< left << setfill('.') << setw(30) << tm.s_loser << endl;
		}
		return os;
	}

	int TennisLog::countLines(string fileName)
	{
		//This counts the number of lines in the csv file.
		string line;
		int count = 0;

		ifstream file (fileName);
		if (file.is_open())
		{
			while (file.peek() != EOF)
			{
				getline(file, line);
				count++;
			}
		}
		else
			cout << "Error opening file" << endl;
		file.close();

		count--; //Because the header does not count
		return count;
	}

	TennisLog::TennisLog()
	{
		m_arrSize = 0;
		m_tm = nullptr;
	}

	TennisLog::~TennisLog()
	{
		delete[] m_tm;
	}

	TennisLog::TennisLog(string file)
	{
		string header;
		m_arrSize = countLines(file);
		m_tm = new TennisMatch[m_arrSize];

		ifstream myFile(file);
		getline(myFile, header); //extract the header

		for (int i = 0; i < m_arrSize; i++)
		{
			getline(myFile, m_tm[i].s_tournamentId, ',');
			getline(myFile, m_tm[i].s_tournamentName, ',');
			myFile >> m_tm[i].s_matchId;
			myFile.ignore();
			getline(myFile, m_tm[i].s_winner, ',');
			getline(myFile, m_tm[i].s_loser, '\n');
		}

		myFile.close();
		
	}

	TennisLog::TennisLog(const TennisLog& src)
	{
		m_tm = nullptr;
		*this = src;
	}

	TennisLog::TennisLog(TennisLog&& src)
	{
		m_tm = nullptr;
		*this = move(src);
	}

	TennisLog& TennisLog::operator=(TennisLog&& src)
	{
		if (this != &src)
		{
			delete[] m_tm;
			m_arrSize = src.m_arrSize;

			m_tm = src.m_tm;
			src.m_tm = nullptr;
			src.m_arrSize = 0;
		}

		return *this;
	}

	TennisLog& TennisLog::operator=(const TennisLog& src)
	{
		if (this != &src)
		{
			delete[] m_tm;
			m_arrSize = src.m_arrSize;

			if (src.m_tm != nullptr)
			{
				m_tm = new TennisMatch[m_arrSize];
				for (int i = 0; i < m_arrSize; i++)
				{
					m_tm[i].s_tournamentId = src.m_tm[i].s_tournamentId;
					m_tm[i].s_tournamentName = src.m_tm[i].s_tournamentName;
					m_tm[i].s_matchId = src.m_tm[i].s_matchId;
					m_tm[i].s_winner = src.m_tm[i].s_winner;
					m_tm[i].s_loser = src.m_tm[i].s_loser;
				}
			}
		}

		return *this;
	}

	void TennisLog::addMatch(TennisMatch tm)
	{
		if (m_arrSize == 0)
		{
			m_arrSize++;
			m_tm = new TennisMatch[m_arrSize];
			/*m_tm[0].s_tournamentId = tm.s_tournamentId;
			m_tm[0].s_tournamentName = tm.s_tournamentName;
			m_tm[0].s_matchId = tm.s_matchId;
			m_tm[0].s_winner = tm.s_winner;
			m_tm[0].s_loser = tm.s_loser;*/

			m_tm[0] = tm;
		}
		else
		{
			int tempSize = m_arrSize + 1;
			int i;

			//create temporary array to store value
			TennisMatch* tempArr = nullptr;
			tempArr = new TennisMatch[tempSize];

			//copy elements from current object tennis match array into temparray
			for (i = 0; i < m_arrSize; i++)
			{
				tempArr[i].s_tournamentId = m_tm[i].s_tournamentId;
				tempArr[i].s_tournamentName = m_tm[i].s_tournamentName;
				tempArr[i].s_matchId = m_tm[i].s_matchId;
				tempArr[i].s_winner = m_tm[i].s_winner;
				tempArr[i].s_loser = m_tm[i].s_loser;
			}

			//copy parameter into temp array
			tempArr[i].s_tournamentId = tm.s_tournamentId;
			tempArr[i].s_tournamentName = tm.s_tournamentName;
			tempArr[i].s_matchId = tm.s_matchId;
			tempArr[i].s_winner = tm.s_winner;
			tempArr[i].s_loser = tm.s_loser;

			//delete old tennismatch array and allocate memory for new one
			delete[]m_tm;
			m_tm = nullptr;
			m_arrSize = tempSize; //updates array size
			m_tm = new TennisMatch[m_arrSize];

			//copy elements from temp array to new array
			for (int j = 0; j < m_arrSize; j++)
			{
				m_tm[j].s_tournamentId = tempArr[j].s_tournamentId;
				m_tm[j].s_tournamentName = tempArr[j].s_tournamentName;
				m_tm[j].s_matchId = tempArr[j].s_matchId;
				m_tm[j].s_winner = tempArr[j].s_winner;
				m_tm[j].s_loser = tempArr[j].s_loser;
			}

			delete[]tempArr;

		}
	}

	TennisLog TennisLog::findMatches(string name)
	{
		TennisLog foundMatches;

		for (int i = 0; i < m_arrSize; i++)
		{
			if (name == m_tm[i].s_winner || name == m_tm[i].s_loser)
			{
				foundMatches.addMatch(m_tm[i]);
			}
		}

		return foundMatches;
	}

	TennisMatch TennisLog::operator[](size_t index)
	{
		if (m_tm == nullptr)
		{
			return {};
		}
		else
		{
			return m_tm[index];
		}
	}

	TennisLog::operator size_t() const
	{
		return m_arrSize;
	}


}