/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 05 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/

#include <iostream>
#include <list>
#include <iomanip>
#include <fstream>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"
#include "Luxuryvan.h"



void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		// TODO: This code can throw errors to signal that something 
		//         went wrong while extracting data. Write code to catch
		//         and handle the following errors:
		//       - the record is not recognized: the first non-empty character
		//           on the line is not 'c', 'C', 'r', 'R', 'v', 'V', 'l', or 'L'
		//       - one of the fields in the record contains invalid data.

		try
		{
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		}
		catch (char err)
		{
			std::cerr << "Unrecognized record type: [" << err << "]" << std::endl;
		}
		catch (const char* err)
		{
			std::cerr << err << std::endl;
		}
	}
}

int cout{};

//ws dataCleanCar.txt, dataMessyCar.txt, dataCleanVan.txt, dataMessyVan.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as, av;
	loadData(argv[1], as);
	std::cout << "--------------------------------\n";
	std::cout << "|  Car in the autoshop!        |\n";
	std::cout << "--------------------------------\n";
	as.display(std::cout);
	std::cout << "--------------------------------\n";

	loadData(argv[2], as);
	std::cout << "--------------------------------\n";
	std::cout << "|  Car in the autoshop!        |\n";
	std::cout << "--------------------------------\n";
	as.display(std::cout);
	std::cout << "--------------------------------\n";

	loadData(argv[3], av);
	std::cout << "------------------------------------------------------------\n";
	std::cout << "|  Van in the autoshop!                                    |\n";
	std::cout << "------------------------------------------------------------\n";
	av.display(std::cout);
	std::cout << "------------------------------------------------------------\n";

	loadData(argv[4], av);
	std::cout << "------------------------------------------------------------\n";
	std::cout << "|  Van in the autoshop!                                    |\n";
	std::cout << "------------------------------------------------------------\n";
	av.display(std::cout);
	std::cout << "------------------------------------------------------------\n";

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle has a top speed >300km/h
		auto fastVehicles = [](const sdds::Vehicle* vh) -> bool
		{
			if (vh->topSpeed() > 300)
			{
				//std::cout << vh->topSpeed();
				return true;
			}
			else
			{
				//std::cout << "here\n";
				return false;
			}
		};
			as.select(fastVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle is broken and needs repairs.
		auto brokenVehicles = [](const sdds::Vehicle* vh) -> bool
		{
			if (vh->condition() == "broken")
				return true;
			else
				return false;
		};
			as.select(brokenVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "| Cars in need of repair       |\n";
		std::cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle is broken and needs repairs.
		auto brokenVehicles = [](const sdds::Vehicle* vh) -> bool
		{
			if (vh->condition() == "broken")
				return true;
			else
				return false;
		};
			av.select(brokenVehicles, vehicles);
		std::cout << "------------------------------------------------------------\n";
		std::cout << "|  Vans in need of repair                                  |\n";
		std::cout << "------------------------------------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "------------------------------------------------------------\n";
	}

	std::cout << std::endl;

	std::cout << std::endl;

	return cout;
}