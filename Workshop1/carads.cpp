/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 16 / 09 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include"carads.h"

using namespace std;

double g_taxrate;
double g_discount;

namespace sdds
{
	
	void listArgs(int argc, char** argv)
	{
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		for (int i = 0; i < argc; i++)
			cout << "  " << i + 1 << ": " << argv[i] << endl;
		cout << "--------------------------\n" << endl;
	}

	istream& operator>>(istream& is, Cars& car)
	{
		return car.read(is);
	}

	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}

	Cars::Cars()
	{
		cBrand = nullptr;
		cModel = nullptr;
		manuYear = 0;
		cPrice = 0;
		cStatus = '\0';
		isPromotion = false;
	}

	Cars::Cars(const Cars& src)
	{
		*this = src;
	}

	Cars& Cars::operator=(const Cars& src)
	{
		if (this != &src)
		{
			manuYear = src.manuYear;
			cPrice = src.cPrice;
			cStatus = src.cStatus;
			isPromotion = src.isPromotion;
			alocpy(cBrand, src.cBrand);
			alocpy(cModel, src.cModel);
		}

		return *this;
	}

	Cars::~Cars()
	{
		delete[] cBrand;
		delete[] cModel;
	}

	void Cars::alocpy(char*& des, const char* src)
	{
		delete[] des;
		des = nullptr;

		if (src != nullptr)
		{
			des = new char[strlen(src) + 1];
			strcpy(des, src);
		}
	
	}

	Cars::operator bool() const
	{ 
		bool toReturn = false;
		if (cStatus == 'N')
			toReturn = true;

		return toReturn;
	}

	char Cars::getStatus()
	{
		return cStatus;
	}

	istream& Cars::read(istream& is)
	{
		if (is.good() == true)
		{
			char dis = 'Y';
			string tBrand, tModel;
			is >> cStatus;
			is.ignore();
			getline(is, tBrand, ',');
			alocpy(cBrand, tBrand.c_str());
			getline(is, tModel, ',');
			alocpy(cModel, tModel.c_str());
			is >> manuYear;
			is.ignore();
			is >> cPrice;
			is.ignore();
			is >> dis;
			if (dis == 'Y')
				isPromotion = true;
			else if (dis == 'N')
				isPromotion = false;
		}

		return is;
	}

	void Cars::display(bool reset)
	{
		if (cBrand[0] != '\0')
		{
			static int counter = 0;
			if (reset == true)
				counter = 1;
			else
				++counter;

			double withTax = cPrice + (cPrice * g_taxrate);
			double sPrice;

			cout << left;
			cout << setfill(' ') << setw(2) << counter;
			cout << ". ";
			cout << setfill(' ') << setw(10) << cBrand << "| ";
			cout << setfill(' ') << setw(15) << cModel << "| ";
			cout << manuYear << " |";
			cout << right;
			cout << setfill(' ') << setw(12) << fixed << setprecision(2) << withTax << "|";
			if (isPromotion)
			{
				sPrice = withTax - (withTax * g_discount);
				cout << setfill(' ') << setw(12) << fixed << setprecision(2) << sPrice << endl;
			}
			else
				cout << endl;
		}
	}
}