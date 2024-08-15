/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 17 / 10 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string m_cName{};
		T* m_items = nullptr;
		size_t m_size = 0u;
		void (*m_observer)(const Collection<T>&, const T&) = nullptr;
	public:
		Collection(const std::string& name)
		{
			m_cName = name;
			m_items = nullptr;
			m_size = 0u;
			m_observer = nullptr;
		}

		~Collection()
		{
			delete[] m_items;
			m_items = nullptr;
		}

		const std::string& name() const
		{
			return m_cName;
		}

		size_t size() const
		{
			return m_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			m_observer = observer;
		}

		Collection<T>& operator+=(const  T& item)
		{
			//searches array for matches
			int index = -1;
			for (size_t i = 0u; i < m_size; i++)
			{
				if (m_items[i].title() == item.title())
				{
					index = i;
					break;
				}
			}

			if (index == -1)
			{
				if (m_size == 0)
				{
					m_size++;
					m_items = new T[m_size];
					m_items[0] = item;
				}
				else
				{
					int tempSize = m_size + 1;
					size_t i;

					T* tempArr = nullptr;
					tempArr = new T[tempSize];

					for (i = 0u; i < m_size; i++)
						tempArr[i] = m_items[i];

					//copy param into temp array
					tempArr[i] = item;

					delete[] m_items;
					m_items = nullptr;
					m_size = tempSize;
					m_items = new T[tempSize];

					for (size_t j = 0; j < m_size; j++)
						m_items[j] = tempArr[j];

					delete[] tempArr;
					tempArr = nullptr;
				}

				if (m_observer != nullptr)
					m_observer(*this, item);
			}

			return *this;
		}

		T& operator[](size_t idx) const
		{
			std::string errMsg;
			errMsg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";

			if (idx > (m_size -1))
				throw std::out_of_range(errMsg);

			return m_items[idx];
		}

		T* operator[](const std::string& title) const
		{
			int index = -1;
			for (size_t i = 0u; i < m_size; i++)
			{
				if (m_items[i].title() == title)
				{
					index = i;
					break;
				}
			}

			T* temp = nullptr;

			if (index == -1)
				return temp;
			else
				return &m_items[index];
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& cl)
		{
			for (size_t i = 0; i < cl.m_size; i++)
			{
				os << cl.m_items[i];
			}

			return os;
		}

	};
}
#endif // !SDDS_COLLECTION_H
