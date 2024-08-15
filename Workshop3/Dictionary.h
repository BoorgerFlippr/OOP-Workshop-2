/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 01 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include <string>
#include<iostream>
#include<iomanip>

namespace sdds
{
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const;
		const std::string& getDefinition() const;
		Dictionary(const std::string&, const std::string&);
		//stuff i added
		Dictionary();
		std::ostream& display(std::ostream&) const;
		bool operator==(const Dictionary&);
	};

	std::ostream& operator<<(std::ostream&, const Dictionary&);
}

#endif // !SDDS_DICTIONARY_H
