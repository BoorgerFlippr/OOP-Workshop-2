/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 16 / 09 / 25
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include"Timer.h"
namespace sdds
{
	void Timer::start()
	{
		m_start = chrono::high_resolution_clock::now();
	}

	long long Timer::stop()
	{
		auto end = chrono::high_resolution_clock::now();

		auto t1 = chrono::duration_cast<chrono::nanoseconds>(end-m_start).count();

		return t1;
	}
}