/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include<iostream>
#include"Vehicle.h"
#include"Car.h"
#include"Van.h"
#include"Racecar.h"
#include"Luxuryvan.h"

namespace sdds
{
	Vehicle* createInstance(std::istream&);
}
#endif // !SDDS_UTILITIES_H
