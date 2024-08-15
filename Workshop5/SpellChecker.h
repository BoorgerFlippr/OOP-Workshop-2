/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 17 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include<string>

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[6] = {};
		std::string m_goodWords[6] = {};
		int m_occurances[6] = {0};
	public:
		SpellChecker(const char*);
		void operator()(std::string&);
		void showStatistics(std::ostream&) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
