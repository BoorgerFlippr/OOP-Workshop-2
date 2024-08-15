/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 16 / 09 / 25
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <string>

using namespace std;
namespace sdds
{
	struct TennisMatch
	{
		string s_tournamentId = "";
		string s_tournamentName = "";
		unsigned int s_matchId = 0;
		string s_winner = "";
		string s_loser = "";
	};

	ostream& operator<<(ostream&, const TennisMatch&);

	class TennisLog
	{
		TennisMatch* m_tm = nullptr;
		int m_arrSize = 0;
		int countLines(string);
	public:
		TennisLog();
		TennisLog(string);
		TennisLog(const TennisLog&);
		TennisLog(TennisLog&&);
		TennisLog& operator=(const TennisLog&);
		TennisLog& operator=(TennisLog&&);
		~TennisLog();
		void addMatch(TennisMatch);
		TennisLog findMatches(string);
		TennisMatch operator[](size_t);
		operator size_t() const;
	};
}

#endif // !SDDS_TENNISLOG_H

