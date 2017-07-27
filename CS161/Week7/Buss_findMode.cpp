/********************************************************************************
* Author: Eric Buss
* Date: 22 FEB 2017
* Description: CS161, Assignment 7; This function findMode.cpp takes input parameters
* of an array of int type data, and the size of the array.  It then determines the
* mode of the array, and returns a vector with the mode value.  If multiple modes
* exist within the array, they will populate the vector in ascending order.
*
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

/*****************************************************************************
//prototype
std::vector<int> findMode(int inputs[], int arraySize);
*****************************************************************************/
/*****************************************************************************
//main function for testing
int main()
{
    int num = 2;
    int inputArray[num] = {5,2};
    std::vector<int> outputVec = findMode(inputArray, num);
    for (int i=0; i < outputVec.size() ; i++)
        std::cout << outputVec[i] << std::endl;
    return 0;
}
*****************************************************************************/

std::vector<int> findMode(int inputs[], int arraySize)
{
    int freq = 1; //initialize the maximum frequency of element occurrence
    std::vector<int> modesVec; //initialize vector to contain modes for output


    /**************************************************
    * First for loop compares array elements and
    * determines the maximum occurrence of the mode(s)
    *
    ***************************************************/


    for (int i=0; i < arraySize ;i++) //loops through each element of the array
    {
        int test1 = 0;//initialize test frequency for each element
        for (int j=i; j < arraySize ;j++) //inner loop is utilized to compare element i to each element j
        {
            if (inputs[j]==inputs[i])
                test1++; //test frequency increases for each occurrence
        }
        if (test1 > freq) // a new maximum frequency is applied if appropriate
            freq = test1; // final iteration gives frequency of mode
    }


    /**************************************************
    * The second loop is used to determine which elements
    * occur the most by comparing the maximum frequency
    * to each element's frequency.
    *
    ***************************************************/
    for (int i=0; i < arraySize; i++) //loops for each element of the vector
    {
        int test2 = 0; //initialize test frequency to zero
        for (int j=i; j < arraySize; j++) //each element is compared to all other elements
        {
            if (inputs[i]==inputs[j])
                test2++; //test frequency includes occurrences of element i
        }
        if (test2==freq) //each element's occurrences are compared to occurrence of mode
            modesVec.push_back(inputs[i]); //if element i is a mode, it is included in returned vector
    }

    std::sort(modesVec.begin(), modesVec.end()); //modes are sorted into ascending order
    return modesVec; //vector of mode(s) is returned

}
