/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 01 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include<iostream>
#include"Dictionary.h"

namespace sdds
{
	template<typename T, unsigned int CAPACITY>
	class Queue
	{
		static T dummy;
		unsigned int m_numObj = 0u;
		T m_queue[CAPACITY];
	public:
		Queue()
		{
			m_numObj = 0u;
		}

		virtual bool push(const T& item) 
		{
			if (m_numObj < CAPACITY)
			{
				m_queue[m_numObj] = item;
				m_numObj++;

				return true;
			}
			else
				return false;
		}

		T pop()
		{
			T toRemove = m_queue[0];
			m_numObj--;
			for (size_t i = 0; i < m_numObj; i++)
			{
				m_queue[i] = m_queue[i + 1];
			}

			return toRemove;
		}

		unsigned int size() const
		{
			return m_numObj;
		}

		void display() const
		{
			std::cout << "----------------------" << std::endl;
			std::cout << "| Dictionary Content |" << std::endl;
			std::cout << "----------------------" << std::endl;
			for (size_t i = 0; i < m_numObj; i++)
			{
				std::cout << m_queue[i] << std::endl;
			}
			std::cout << "----------------------" << std::endl;
		}

		T operator[](unsigned int index) const
		{
			if (index < m_numObj)
				return m_queue[index];
			else
				return dummy;
		}

		virtual ~Queue()
		{

		}
	};


	template<typename T, unsigned int CAPACITY>
	T Queue<T, CAPACITY>::dummy = {};

	template<>
	Dictionary Queue<Dictionary, 100u>::dummy = { "Empty Term", "Empty Substitute" };

}

#endif // !SDDS_QUEUE_H
