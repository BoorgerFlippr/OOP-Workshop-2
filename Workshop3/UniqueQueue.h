/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 01 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include <cmath>
#include"Queue.h"
#include"Dictionary.h"

namespace sdds
{
	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
	public:
		virtual bool push(const T& item) override
		{
			int flag = 0;
			if (Queue<T, 100>::size() == 0)
			{
				return Queue<T, 100>::push(item);
			}
			else
			{
				for (size_t i = 0; i < Queue<T, 100>::size(); i++)
				{
					if ((*this)[i] == item)
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
					return Queue<T, 100>::push(item);
				else
					return false;
			}
		}
	};

	template<>
	bool UniqueQueue<double>::push(const double& item)
	{
		int flag = 0;
		if (Queue<double, 100>::size() == 0)
		{
			return Queue<double, 100>::push(item);
		}
		else
		{
			for (size_t i = 0; i < Queue<double, 100>::size(); i++)
			{
				if (fabs((*this)[i] - item) < 0.005)
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0)
				return Queue<double, 100>::push(item);
			else
				return false;
		}
	}
}
#endif // !SDDS_UNIQUEQUEUE_H
