// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

int Linear(std::vector<int> searchVector, int searchTerm)
{
    int index = -1;

    for (size_t i = 0; i < searchVector.size(); i++)
    {
        if (searchTerm == searchVector[i])
        {
            index = i;
            break;
        }
    }

    return index;
}

void PrintGrades(const std::map<std::string, double>& course)
{
    std::cout << "\n*-*-*-*-PG2 2311*-*-*-*-\n";
    for (auto& [student, grade] : course)
    {
        std::cout << std::setw(10) << std::left << student << std::setw(7) << std::right << grade << "\n";
    }
    std::cout << "\n\n";
}


int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int foundIndex = Linear(numbers, searchNumber);
    if (foundIndex >= 0)
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";
    else
        std::cout << searchNumber << " was NOT found!\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionary:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    //type of key: string
    //type of value: float
    std::map<std::string, float> menu;
    //[key] = value
    menu["Parmesan Chicken"] = 24.99F;
    menu["Spaghetti"] = 14.99F;
    menu["Spaghetti"] = 16.99F;//overwrite

    std::pair<std::string, float> item("Garlic Bread", 8.99F);
    auto wasInserted = menu.insert(item);
    std::pair<std::string, float> item2("Garlic Bread", 12.99F);
    wasInserted = menu.insert(item2);//will NOT overwrite
    if (wasInserted.second == false)
        std::cout << "Are you sure you want to overwrite?\n";

    /*
        CHALLENGE 2:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */
    std::vector<std::string> pg2_2311{ "Ryan", "Bryan", "Aidan", "Anthony", "James", "Ana", "Niko", "Samuel", "Meikel", "Matthew", "Greyson" };

    srand(time(NULL));
    std::map<std::string, double> grades;
    for (auto& student : pg2_2311)
    {
        grades[student] = (rand() % 10001) / 100.0;
    }





    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }

    std::cout << "*-*-*-*-Chez Bryan*-*-*-*-\n";
    for (auto it = menu.begin(); it != menu.end(); it++)
    {
        std::cout << std::setw(20) << it->first << std::setw(7) << it->second << "\n";
    }

    std::cout << "\n*-*-*-*-Chez Bryan*-*-*-*-\n";
    for (auto& [menuItem,menuPrice] : menu)
    {
        std::cout << std::setw(20) << std::left << menuItem << std::setw(7) << menuPrice << "\n";
    }
    std::cout << "\n\n";


    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */
    PrintGrades(grades);



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }

    std::string itemToFind = "Garlic Bread";
    auto foundMenuItem = menu.find(itemToFind);
    if (foundMenuItem == menu.end())
    {
        std::cout << itemToFind << " was not found.\n";
    }
    else
    {
        std::cout << itemToFind << " costs " << foundMenuItem->second << "\n";
    }
    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */
    std::string studentToFind = "Bryan";
    auto foundStudent = grades.find(studentToFind);
    if (foundStudent != grades.end())
        std::cout << foundStudent->first << " has a grade of " << foundStudent->second << "\n";
    else
        std::cout << studentToFind << " is not in the course.\n";




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe

    if (foundMenuItem != menu.end())
    {
        float garlic = foundMenuItem->second;

        //update the value for the key
        menu[foundMenuItem->first] = garlic + 4;
        //OR
        //foundMenuItem->second = garlic + 4;


        std::cout << foundMenuItem->first << " used to costs " << garlic;
        std::cout << ". Now it costs " << menu[foundMenuItem->first] << "!! Thanks Putin.\n";
    }


    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */


    if (foundStudent != grades.end())
    {
        double oldGrade = foundStudent->second;
        grades[(*foundStudent).first] = std::min<double>(100, oldGrade + 5);
        std::cout << foundStudent->first << " had a grade of " << oldGrade << ". Now the grade is " << foundStudent->second << ".\n";
    }
}