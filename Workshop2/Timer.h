/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 16 / 09 / 25
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include<chrono>

using namespace std;
namespace sdds
{
	class Timer
	{
		chrono::high_resolution_clock::time_point m_start;
		//long long m_finish;
	public:
		void start();
		long long stop();
	};
}
#endif // !SDDS_TIMER_H
