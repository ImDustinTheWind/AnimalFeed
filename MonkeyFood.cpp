//***********************************************************************************************************
//Programming Assignment 06
//Programmer: Dustin Sherer
//Completed: 03/18/2022
//Status: Completed
//
// This assignment is Programming Challenge 4 from Chapter 8 of the textbook. A local zoo wants to keep track of 
// how many pounds of food each of its three monkeys eats each day during a typical week. Write a program that 
// stores this information in a two-dimensional 3 x 7 array, where each row represents a different monkey and 
// each column represents a different day of the week. The program should first have the user input the data for 
// each monkey from the keyboard. The number of pounds of food eaten by one monkey in one day should be a floating-point value.
//
// Input Validation : Do not accept negative numbers.
//
// Then your program should create a report that includes the following information :
//  - A nicely - formatted table with a row for each monkey and a column for each day of the week showing the amount of food 
//      eaten by that monkey on that day.Be sure to include row and column labels.Format all the food amounts so that they 
//      print with the same number of decimal places.This makes the decimal points line up nicely.Note : you should write a separate function to print this table.
//  - The average amount of food eaten per day by the whole group of monkeys.This is the total food eaten by all monkeys during     
//  the week divided by seven.Note : you should write a separate value - returning function to calculate this average.
//  - The least amount of food eaten on any day during the week by any one monkey.Note : you should write a separate value - returning function to find the smallest amount of food.
//  - The greatest amount of food eaten on any day during the week by any one monkey.Note : you should write a separate value - returning function to find the largest amount of food.
//
//***********************************************************************************************************

#include <iostream>
#include <iomanip>
#include "MonkeyFood.h"

int main()
{
    //constants to avoid "magic numbers"
    //const int rows = 3;
    //const int columns = 7;
    float monkeyTable [row][column];

    inputFoodAmount(monkeyTable, row);
    printFoodTable(monkeyTable, row);
    
    std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}

//***********************************************************************************************************
//inputFoodAmount is used to fill out monkeyTable 2d array.
//
// NO NEGATIVE INPUTS!!!
// 
//***********************************************************************************************************
void inputFoodAmount(float mTable[][column], int row)
{
    std::string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    float tempNum = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << "Enter pounds of food eaten by monkey " << i + 1;
            std::cout << " on " << days[j] << " : ";
            std::cin >> tempNum;
            while (tempNum < 0)
            {
                std::cout << "Please enter a positive (+) number: ";
                std::cin >> tempNum;
            }
            mTable[i][j] = tempNum;
        }
    }

    std::cout << std::endl;
    return;
}

//***********************************************************************************************************
// printFoodTable prints out data from 2d array of what each monkey ate on which day, properly formatted.
//  - also prints out avg, max, and min daily food intakes
// 
//***********************************************************************************************************
void printFoodTable(float mTable[][column], int row)
{
    // variable to hold user input until (+) float is verified
    float foodLBS;

    //output row headers
    std::cout << std::right << std::setw(7) << "Monkey";
    std::cout << std::right << std::setw(7) << "Sun";
    std::cout << std::right << std::setw(7) << "Mon";
    std::cout << std::right << std::setw(7) << "Tue";
    std::cout << std::right << std::setw(7) << "Wed";
    std::cout << std::right << std::setw(7) << "Thu";
    std::cout << std::right << std::setw(7) << "Fri";
    std::cout << std::right << std::setw(7) << "Sat" << std::endl;

    for (int i = 0; i < row; i++)
    {
        //output monkey #
        std::cout << std::right << std::setw(7) << i;

        for (int j = 0; j < 7; j++)
        {
            foodLBS = mTable[i][j];
            //output food amounts for each day for monkey[i]
            std::cout << std::right << std::setw(7) << std::setiosflags(std::ios::fixed) << std::setprecision(1) << foodLBS;
        }
        std::cout << std::endl;
    }

    //call AverageFood, then print out
    std::cout << "\nThe average food eaten per day by all monkeys : " << std::setiosflags(std::ios::fixed) << std::setprecision(1) << std::right << std::setw(5) << AverageFood(mTable,3) << " pounds";
    //call LeastFood, then print out
    std::cout << "\nThe least amount of food eaten by any monkey  : " << std::setiosflags(std::ios::fixed) << std::setprecision(1) << std::right << std::setw(5) << LeastFood(mTable, 3) << " pounds";
    //call MostFood, then print out
    std::cout << "\nThe largest amount of food eaten by any monkey: " << std::setiosflags(std::ios::fixed) << std::setprecision(1) << std::right << std::setw(5) << MostFood(mTable, 3) << " pounds";

    return;
}

//***********************************************************************************************************
// AverageFood returns avg weight of food eaten for all days/moneys in 2d array
//
//***********************************************************************************************************
float AverageFood(float mTable[][column], int row)
{
    float average = 0;
    float sum = 0;
    int divisor = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			sum += mTable[i][j];
            divisor++;
		}
	}
    average = sum / divisor;
    return average;
}

//***********************************************************************************************************
// LeastFood returns min weight of food eaten by any monkey recorded in the 2d array
//
//***********************************************************************************************************
float LeastFood(float mTable[][column], int row)
{
    float minWeight;
    minWeight = mTable[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 7; j++)
		{
            if (minWeight < mTable[i][j])
            {
                minWeight = mTable[i][j];
            }
		}
	}
    return minWeight;
}

//***********************************************************************************************************
// MostFood returns max weight of food eaten by any monkey recorded in the 2d array
//
//***********************************************************************************************************
float MostFood(float mTable[][column], int row)
{
	float maxWeight;
	maxWeight = mTable[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (maxWeight > mTable[i][j])
			{
				maxWeight = mTable[i][j];
			}
		}
	}
    return maxWeight;
}

