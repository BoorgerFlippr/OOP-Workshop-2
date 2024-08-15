/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 16 / 09 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H

extern double g_taxrate;
extern double g_discount;

using namespace std;
namespace sdds
{

	class Cars
	{
		char* cBrand;
		char* cModel;
		int manuYear;
		double cPrice;
		char cStatus;
		bool isPromotion;
	public:
		Cars();
		//rule of 3
		Cars(const Cars&);
		Cars& operator=(const Cars&);
		~Cars();
		std::istream& read(std::istream&);
		void display(bool);
		char getStatus();
		operator bool() const;
		//to help allocating memory for the cstring
		void alocpy(char*&, const char*);
	};

	void listArgs(int, char**);
	std::istream& operator>>(std::istream&, Cars&);
	void operator>>(const Cars&, Cars&);
}
#endif // !SDDS_CARADS_H


