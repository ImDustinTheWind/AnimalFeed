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

#pragma once

//constants to avoid "magic numbers"
const static int row = 3;
const static int column = 7;


//function to input the food amounts
void inputFoodAmount(float mTable[][column], int row);
//function to print the table of food eaten
void printFoodTable(float mTable[][column], int row);
//value-returning function to find each of the following: average food eaten
float AverageFood(float mTable[][column], int row);
//value-returning function to find each of the following: least food eaten
float LeastFood(float mTable[][column], int row);
//value-returning function to find each of the following: most food eaten
float MostFood(float mTable[][column], int row);

