// Day04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <string_view>


std::string toUpper(const std::string& original)
{
	std::string copy = original;
	for (auto& c : copy)
		c = toupper(c);
	return copy;
}

void recursiveLoop(int N)
{
	if (N < 10)
	{
		std::cout << N << "\n";
		recursiveLoop(N + 1);
		std::cout << N << "\n";
	}
}

unsigned long factorial(unsigned int N)
{
	if (N <= 1) return 1; //here's the exit condition!
	return N * factorial(N - 1);
}

void BubbleSort(std::vector<int>& unsorted)
{
	bool swapped;
	int n = unsorted.size();
	do
	{
		swapped = false;
		for (size_t i = 1; i <= n-1; i++)
		{
			if (unsorted[i - 1] > unsorted[i]) //time to swap!
			{
				//swap(A[i - 1], A[i]);
				int temp = unsorted[i - 1];//the type of temp must match the type of values in the vector
				unsorted[i - 1] = unsorted[i];
				unsorted[i] = temp;
				swapped = true;
			}
		}
		--n;
	} while (swapped);
}

void BubbleSort(std::vector<std::string>& unsorted)
{
	bool swapped;
	int n = unsorted.size();
	do
	{
		swapped = false;
		for (size_t i = 1; i <= n - 1; i++)
		{
			//if (_stricmp(unsorted[i - 1].c_str(), unsorted[i].c_str()) > 0) //time to swap!
			if(toUpper(unsorted[i - 1]).compare(toUpper(unsorted[i])))
			{
				//swap(A[i - 1], A[i]);
				std::string temp = unsorted[i - 1];//the type of temp must match the type of values in the vector
				unsorted[i - 1] = unsorted[i];
				unsorted[i] = temp;
				swapped = true;
			}
		}
		--n;
	} while (swapped);
}

void someMethod(int n)
{
	int v = 5;
	if (v < n)
		std::cout << "You win!\n";
	else
		std::cout << "You lose.\n";
}

void Bats(int i)
{
	if (i >= 100) return;

	std::cout << (char)78 << (char)65 << ' ';
	Bats(i + 1);
}

int main()
{
	someMethod(6);

	std::vector<int> scores{ 1,2,3,4,5 };
	int index = 0;
	while (index < scores.size())
	{
		break;
	}
	do
	{
		break;
	} while (index < scores.size());
	for (int i = 0; i < scores.size(); i++)
	{
		std::cout << "Aquaman sucks!";
		break;
	}
	/*
		╔═════════╗
		║Recursion║
		╚═════════╝

		Recursion happens when a method calls itself. This creates a recursive loop.

		All recursive methods need an exit condition, something that prevents the loop from continuing.

	*/
	int N = 0;
	recursiveLoop(N);


	/*
		CHALLENGE 1:

			convert this for loop to a recursive method called Bats.
			Call Bats here in Main.

			for(int i = 0;i < 100;i++)
			{
				std::cout << (char)78 << (char)65 << ' ';
			}
	*/
	//call Bats here.
	int i = 0;
	Bats(i);

	char c[] = { '\n', 66, 65, 84, 77, 65, 78, 33, 33 };
	for (auto ch : c) std::cout << ch;



	/*
		╔═════════════════╗
		║  Swapping Items ║
		╚═════════════════╝

		add #include <string_view>
		make sure the project is using C++17 or greater.

	*/
	std::cout << "\n\n---SWAPPING ITEMS---\n";
	std::vector<int> nums = { 1,2,3,4,5 };
	for (auto i : nums)
		std::cout << i << " ";
	std::cout << " (original)\n";

	//write code to swap 2 items in the vector

	std::cout << " (after swapping)\n";
	for (auto i : nums)
		std::cout << i << " ";

	std::vector<int> grades;
	for (size_t i = 0; i < 10; i++)
	{
		grades.push_back(rand() % 101);
	}
	std::cout << "-------UNSORTED---------\n";
	for (auto& grade : grades)
	{
		std::cout << grade << "\n";
	}
	BubbleSort(grades);
	std::cout << "-------SORTED---------\n";
	for (auto& grade : grades)
	{
		std::cout << grade << "\n";
	}


	/*
		╔═════════════════╗
		║Comparing Strings║
		╚═════════════════╝

		the compare functions return an int that will tell you
		how the strings compare to each other.
		< 0 means s1 is LESS THAN (or comes before) s2
		  0 means s1 is EQUAL TO s2
		> 0 means s1 is GREATER THAN (or comes after) s2

		_stricmp: case-insensitive string comparison.
			The methods needs pointers to char arrays therefore
			you need to call c_str on the std::string

		std::string::compare:  case-sensitive string comparison
			If you want to ignore case, you can convert the strings
			to all uppercase/lowercase

	*/
	std::string s1 = "Batman", s2 = "Aquaman";
	int compResult = _stricmp(s1.c_str(), s2.c_str());
	if (compResult < 0)
		std::cout << s1 << " is LESS THAN " << s2 << "\n";
	else if(compResult == 0)
		std::cout << s1 << " is EQUAL TO " << s2 << "\n";
	else if(compResult > 0)
		std::cout << s1 << " is GREATER THAN " << s2 << "\n";
	//OR...
	int compareResult = toUpper(s1).compare(toUpper(s2));
	if (compareResult < 0)
		std::cout << s1 << " is LESS THAN " << s2 << "\n";
	else if (compareResult == 0)
		std::cout << s1 << " is EQUAL TO " << s2 << "\n";
	else if (compareResult > 0)
		std::cout << s1 << " is GREATER THAN " << s2 << "\n";






	/*
		╔═══════╗
		║Sorting║
		╚═══════╝

		Sorting is used to order the items in a vector/array is a specific way

		CHALLENGE 2:

			Convert this BubbleSort pseudo-code into a method

			procedure bubbleSort(A : list of sortable items)
			  n := length(A)
			  repeat
				  swapped := false
				  for i := 1 to n - 1 inclusive do
					  if A[i - 1] > A[i] then
						  swap(A, i - 1, i)
						  swapped = true
					  end if
				  end for
				  n := n - 1
			  while swapped
			end procedure

	*/
	std::vector<std::string> names = { "Wonder Woman", "Superman", "Batman", "Flash", "Aquaman" };
	//print the unsorted vector.
	std::cout << "-------UNSORTED---------\n";
	for (auto& name : names)
		std::cout << name << "\n";
	//call your BubbleSort on the names vector.
	BubbleSort(names);


	//print the sorted vector.
	std::cout << "-------SORTED---------\n";
	for (auto& name : names)
		std::cout << name << "\n";
}