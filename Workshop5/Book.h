/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 17 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds
{
	class Book 
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		double m_price = 0;
		size_t m_year = 0;
		std::string m_desc{};
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string&);

		//template function
		template<typename T>
		void fixSpelling(T& spellchecker)
		{
			//spellchecker(m_title);
			spellchecker(m_desc);
		}

		friend std::ostream& operator<<(std::ostream&, const Book&);

	};
}
#endif // !SDDS_BOOK_H
