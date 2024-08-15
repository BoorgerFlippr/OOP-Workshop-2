/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 17 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include<string>

namespace sdds
{
	class Movie
	{
		std::string m_title{};
		size_t m_year = 0u;
		std::string m_desc{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string&);

		//template function
		template<typename T>
		void fixSpelling(T& spellchecker)
		{
			//spellchecker(m_title);
			spellchecker(m_desc);
		}

		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}
#endif // !SDDS_MOVIE_H
