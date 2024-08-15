/*
* Glenn Parreno
* geparreno@myseneca.ca
* 115814196
* 25 / 11 / 22
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <thread>
#include <future>
#include "TreasureMap.h"

namespace sdds {

    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.

            // END TODO

            std::ofstream file(filename, std::ios::out | std::ios::binary);
            if (file.good())
            {
                file.write((char*)&rows, 8);
                file.write((char*)&colSize, 8);
                
                for (size_t i = 0; i < rows; ++i)
                {
                    file.write(map[i].c_str(), colSize);
                }
            }
            else
                throw std::string("Cannot open file");

            file.close();
        }
        else {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.

        // END TODO

        std::ifstream file(filename, std::ios::in | std::ios::binary);
        if (file.good())
        {
            file.read((char*)&rows, 8);
            file.read((char*)&colSize, 8);

            map = new std::string[rows];
           
            for (size_t i = 0; i < rows; ++i)
            {
                //map[i].resize(colSize);
                char* temp = new char[colSize+1];
                file.read(temp, colSize);
                temp[colSize] = '\0';
                map[i] = temp;
                delete[] temp;
            }
        }
        else
            throw std::string("aaa");

        file.close();

    }

    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark) {
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        /*for (size_t i = 0; i < rows; ++i) {
            count += digForTreasure(map[i], mark);
        }*/

        const std::string str1 = map[0] + map[1] + map[2];
        const std::string str2 = map[3] + map[4] + map[5];
        const std::string str3 = map[6] + map[7] + map[8];
        const std::string str4 = map[9] + map[10] + map[11];

        auto b1 = std::bind(digForTreasure, str1, mark);
        auto b2 = std::bind(digForTreasure, str2, mark);
        auto b3 = std::bind(digForTreasure, str3, mark);
        auto b4 = std::bind(digForTreasure, str4, mark);
        
        std::packaged_task<size_t()> t1(b1);
        std::future<size_t> cnt1 = t1.get_future();
        
        std::packaged_task<size_t()> t2(b2);
        std::future<size_t> cnt2 = t2.get_future();

        std::packaged_task<size_t()> t3(b3);
        std::future<size_t> cnt3 = t3.get_future();

        std::packaged_task<size_t()> t4(b4);
        std::future<size_t> cnt4 = t4.get_future();

        std::thread th1(std::move(t1));
        std::thread th2(std::move(t2));
        std::thread th3(std::move(t3));
        std::thread th4(std::move(t4));

        th1.join();
        th2.join();
        th3.join();
        th4.join();

        count += cnt1.get();
        count += cnt2.get();
        count += cnt3.get();
        count += cnt4.get();

        return count;
    }
}