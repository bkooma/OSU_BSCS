#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

//findMode function    
std::vector<int> findMode(int xArr[], int sizeArr) {
	int i, j, k, m, count;
	int yArr[sizeArr];
	int maxNum = 0;
	int xArrVal;

	std::vector<int> results;

	//loop to count an array from left to right
	for (i = 0; i<sizeArr; i++) {
		count = 0;
		xArrVal = xArr[i]; //xArrVal will equal the value of xArr[i]

		for (j = i; j<sizeArr; j++) {
			if (xArrVal == xArr[j])
				count++;
		}
		yArr[i] = count; //
		std::cout << yArr[i] << ' ' << std::endl;
	}

	//find highest number in array
	for (k = 0; k<sizeArr; k++) {
		if (yArr[k]>maxNum)
			maxNum = yArr[k];
	}

	//push results to vector
	for (m = 0; m < sizeArr; m++) {
		if (maxNum == yArr[m]) {
			results.push_back(xArr[m]);
		}
	}

	//sort vector
	std::sort(results.begin(), results.end());
	return results;
}

int main(void) {
	int* x;
	int size = 0;
	int arraycount;
        std::vector<int> returnVec;
        std::vector<int>::iterator pos;

	//intialize array
	std::cout << "Enter number of integers ";
	std::cout << "you wish to input." << std::endl;
	std::cin >> size;
	std::cout << "Enter the integers." << std::endl;
	x = new int[size];

	for (arraycount = 0; arraycount < size; arraycount++)
		std::cin >> x[arraycount];

	//send array and size to function
	returnVec = findMode(x, size);

	std::cout << "The mode(s) is/are: ";
	for (pos=returnVec.begin(); pos!=returnVec.end(); ++pos)
//	for (int v : std::findMode(x, size)) 
             {
             std::cout << *pos << ' ';
             }
			 std::endl;
	return 0;
}
