/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 01 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include "Dictionary.h"

using namespace std;
namespace sdds
{
	const string& Dictionary::getTerm() const 
	{
		return m_term;
	}

	const string& Dictionary::getDefinition() const
	{
		return m_definition;
	}

	Dictionary::Dictionary(const string& term, const string& definition) 
		: m_term{ term }, m_definition{ definition }{}

	Dictionary::Dictionary() : m_term{}, m_definition{} {}

	ostream& Dictionary::display(ostream& os) const
	{
		os << setw(20) << m_term << ": " << m_definition;
		return os;
	}

	bool Dictionary::operator==(const Dictionary& dc)
	{
		if (m_term == dc.getTerm() && m_definition == dc.getDefinition())
			return true;
		else
			return false;

	}

	ostream& operator<<(ostream& os, const Dictionary& dc)
	{
		return dc.display(os);
	}
}