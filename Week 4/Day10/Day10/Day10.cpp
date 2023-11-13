// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Hero.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string dirPath = "C:\\temp\\2311\\";
    std::string fileName = "2311.csv";
    std::string fullPath = dirPath + fileName;

    char delimiter = '%';
    std::ofstream outFile(fullPath);//1) open the file
    if (outFile.is_open())//check that the file is open before proceeding
    {
        //2) write to the file
        outFile << "Batman!!" << delimiter << 5 <<
            delimiter << true << delimiter << "NOT Aquaman";
        outFile << delimiter << 23 << delimiter << 420.1;
    }
    else
        std::cout << "That file or path does not exists.\n";

    outFile.close();//3) close the file


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */
    std::ifstream inFile(fullPath);

    std::string inLine;
    if (inFile.is_open())
    {
        std::getline(inFile, inLine);//assume \n
        std::cout << "\nReading from CSV...\n" << inLine << "\n";
    }
    else
        std::cout << "The file could not be opened.\n";

    inFile.close();


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */
    std::stringstream inStream(inLine);
    std::string data;
    while (std::getline(inStream, data, delimiter))
    {
        std::cout << data << "\n";
    }





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
    std::string heroString;
    std::stringstream multiStream(multi);
    std::vector<Hero> DC;
    while (std::getline(multiStream, heroString, collectionSeparator))
    {
        std::stringstream heroStream(heroString);
        std::string name, secret, ageString;
        std::getline(heroStream, name, objectSeparator);
        std::getline(heroStream, secret, objectSeparator);
        std::getline(heroStream, ageString, objectSeparator);
        Hero myHero(name, secret, std::stoi(ageString));
        DC.push_back(myHero);
    }

    std::cout << "\n\n*^*^*^ DC Universe *^*^*^\n";
    for (auto& hero : DC)
    {
        std::cout << "Hello citizen! I am " << hero.GetName() << " (aka " << hero.GetSecret();
        std::cout << "). I am " << hero.GetAge() << " years old!!\n";
    }

    std::string dcFileName = "DC.csv";
    fullPath = dirPath + dcFileName;
    std::ofstream dcFile(fullPath);
    if (dcFile.is_open())
    {
        for (auto& hero : DC)
        {
            hero.Serialize(dcFile, '^');
            dcFile << "\n";
        }
    }
    dcFile.close();

    std::cout << "____DC____\n";
    for (auto& hero : DC)
    {
        hero.Serialize(std::cout, '\t');
        std::cout << "\n";
    }
}