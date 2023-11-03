// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

void Print(const std::map<std::string, double>& grades)
{
    std::cout << "\n    DC University    \n";
    for (auto& student : grades)
    {
        std::cout << std::setw(10) << std::left << student.first;
        std::cout << std::setw(7) << std::right << student.second << "\n";
    }
}


int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasbackpack;
    auto inserted = dorasbackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasbackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasbackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasbackpack.find(Weapon::Axe);
    if (found != dorasbackpack.end())
    {
        dorasbackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                    if not found print an error message
                    else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = (rand() % 10001)/100.0;
    grades["Dick"] = (rand() % 10001) / 100.0;
    grades["Diana"] = (rand() % 10001) / 100.0;
    grades["Alfred"] = (rand() % 10001) / 100.0;
    grades["Clark"] = (rand() % 10001) / 100.0;
    grades["Arthur"] = (rand() % 10001) / 100.0;
    grades["Barry"] = (rand() % 10001) / 100.0;
    Print(grades);

    std::cout << "Name of student to drop: ";
    std::string drop;
    std::getline(std::cin, drop);

    int DroppedNumber = grades.erase(drop);
    if (DroppedNumber > 0)
    {
        std::cout << drop << " was removed from the course.\n";
        Print(grades);
    }
    else
        std::cout << drop << " is not in the course!\n";


}