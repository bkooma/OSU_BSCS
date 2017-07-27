/**********************************************************
 * Name: Alexander Goodman
 *
 * Due Date: 22 February 2017
 *
 * Assignment: Assignment 7 ; Project 7
 *
 * Description: This function takes an array of int values
 * 		and returns the mode(s) as a vector in 
 * 		ascending order.
 *
 *********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>  // to use sort

using std::cout;
using std::endl;
using std::sort;
using std::vector;
//using namespace std;

//Function Prototype
vector <int> findMode(int arr[], int size_arr);

/**********************************************************
 * Function Name: findMode.cpp
 * 
 * Description: Takes an array of int values and returns the
 * 		mode(s) as a vector in ascending order.
 *
 * Function Prototype: vector <int> findMode(int arr[], size_arr);
 *
 * *******************************************************/

//defining vector findMode

vector <int> findMode(int arr[], int size_arr)
{
 sort(arr, arr+size_arr);  // to sort original array in ascending order.

  int freq, highest;  // used to determine frequency of Numbers

  vector <int> mode;  //defining vector mode to store mode-values

  for (int count=0; count < size_arr; count++)
  {
   freq = 1;
   if (count==0)
    highest = 1;	//initialized first value to 1
    for (int i=0; i<size_arr; i++)
    {
      if (arr[count] == arr[i] && (count != i))
	freq = freq +1;
      if(freq > highest)
      {
	highest = freq;	//change highest to freq count
	//cout << "highest frequency: " << freq <<endl;  //to check freq count
        mode.clear();
	mode.push_back(arr[count]); //add new value to recently cleared vector
      }
      else if (freq == highest)
      {
	//if statement below: eliminates duplicates by deleting previous value if
	// newvalue=oldvalue since the array is in ascending order.
	if (mode.size() >0 && (arr[count]== mode[mode.size()-1]))
		mode.pop_back();
	mode.push_back(arr[count]);   //add new value to vector
      }  
    }
  }

  return mode; // returns mode vector in ascending order
}




/**********************************************
 *
 * NOTE: Below is the first way I solved and wanted to keep code
 *       
 * ********************************************/

// Sorts Vector in Ascending Order (used for double checking)
//  sort(mode.begin(), mode.end());	


/**********************************************************
 * Eliminate Duplicate Numbers -- Checks ascended order vector if current value == previous value
 *  				   Do NOT add to result vector.
 * NOTE: Written before the check before, so now redundant...
 * *******************************************************/
/*********
 vector <int> result;  // defines final Vector to be returned

//  "RESULT vector Values: " 
  for(int count=0; count<mode.size(); count++)	//For Loop to eliminate duplicate values
  {
    if (count == 0 || (mode[count] != mode[count-1]))  
    {
      int val = mode[count];
      result.push_back(val);  //stores mode vector value in result vector 
    }
  }
*********/



