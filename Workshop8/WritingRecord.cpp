/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 20 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		EmployeeWage* temp = nullptr;
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					if (activeEmp.checkSin(emp[i].id))
					{
						temp = new EmployeeWage(emp[i].name, sal[j].salary);
						try
						{
							temp->rangeValidator();
						}
						catch (...)
						{
							delete temp;
							throw std::string("*** Employees salaray range is not valid");
						}

						activeEmp += *temp;

						delete temp;
					}
				}
			}
		}

		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					if (activeEmp.checkSin(emp[i].id))
					{
						std::unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));

						temp->rangeValidator();

						activeEmp += std::move(temp);
					}
				}
			}
		}

		return activeEmp;
	}
}