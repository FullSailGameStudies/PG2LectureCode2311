// Day07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pickaxe.h"
#include "color.h"


/*              CLASSESS

            ╔═════╗ ╔═════════╗
            ║class║ ║SomeClass║
            ╚═════╝ ╚═════════╝
                │          │        
             ┌──┘          │         
        ┌────▼─────┐   ┌───▼───┐   
        │ Keyword  │   │ Class │  
        │          │   │  Name │
        └──────────┘   └───────┘ 

        FIELDS - the data of the class

        METHODS - the behavior of the class (what the class can do)

        SPECIAL METHODS:
            Getters/Setters - the gatekeepers of the fields
            CONSTRUCTORS - the initializer of the class
            DESTRUCTORS - destroys allocated memory.


      


    ╔══════════════════╗
    ║ ACCESS MODIFIERS ║ - determines who can see it
    ╚══════════════════╝
        public: EVERYONE can see it
        private: ONLY this class can see it  (default)
        protected: this class and all its descendent classes can see it




*/


int main()
{
    /*
    
    */


    /*
        ╔════════╗
        ║ FIELDS ║ - the data members of the class
        ╚════════╝

        use mCamelCasingNamingConvention to name your fields in a C# class

        int mModelYear;

        Lecture code: add a Pickaxe class
        Lecture code: add material, durability fields

    */

    /*
        CHALLENGE:

			1. Create a Player class.
			Right-Click the project and select "Add > Class..."

			2. Add these Fields: gamertag, health, experience, armorLevel
    */





    /*
        ╔═════════╗
        ║ METHODS ║ - the member functions of the class -- the behavior of the class (what it can do)
        ╚═════════╝

        non-static methods can access the fields/methods of the class
        static methods can only access the static members of the class

        EXAMPLE:
        void whoAmI()
        {
            std::cout << mName;
        }

        Lecture code: add MineSomething and UpdateDurability methods
    */
    Pickaxe fortune500(Material::Netherite);//we are calling the DEFAULT ctor here
    fortune500.MineSomething(5, 5, 5);

    //Pickaxe* picky = new Pickaxe(Material::Gold);


    /*
        CHALLENGE:
            add a PickupItem method w/ a string parameter
            add the item to vector inventory
    */





    /*
        ╔═════════════════╗
        ║ Getters/Setters ║ - the gatekeepers (control access) of the fields
        ╚═════════════════╝

        use camelCasingNamingConvention to name your getter/setter methods


        int modelYear() const  //const says the method can't modify anything
        {
            return mModelYear;  //provides access to the field's value
        }

        void modelYear(int year)
        {
            mModelYear = year;
        }

        Lecture code: add getters/setters 
    */


    /*

        CHALLENGE:
            Add a getter/setter for the Player's experience_ field
    */




    /*
        ╔══════════════╗
        ║ CONSTRUCTORS ║ - the initializer of the class. Initialize the data of the class.
        ╚══════════════╝

        RULES FOR CONSTRUCTORS...
        1) cannot have any return type, not even void
        2) must have the same name as the class

        HINT: use the ctor code snippet to provide a default contructor

        Car(int year, std::string make)
        {
           mModelYear = year;
           mMake = make;
        }

        Lecture code: add 2 ctors (default and non-default) 
    */


    /*

        CHALLENGE:
            Add a constructor to the Player class to initialize the fields
    */




    /*
        ╔══════════════╗
        ║  STRUCTURES  ║ - light-weight data objects
        ╚══════════════╝

        In C++, structs are just like classes EXCEPT members are public by default.

        Lecture code: add struct for color (r,g,b,a)
    */

    COLOR woolColor;
    woolColor.red = woolColor.green = woolColor.blue = 255;

}