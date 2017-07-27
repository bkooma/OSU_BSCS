#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

#define N 100

void findMode(int x[], int size);       //function prototype
vector<int> results;    //vector

int main(void) {
   int* x;
   int size=0;
   int arraycount;

//intialize array
   cout << "Enter number of integers ";
   cout << "you wish to input."  << endl;
   cin >> size;
   cout << "Enter the integers." << endl;
   x = new int[size];

   for (arraycount = 0; arraycount < size;
   arraycount++)
      cin >> x[arraycount];

//send array and size to function
   findMode(x, size);

   return 0;
}

//findMode function    
void findMode(int x[], int size) {
   int y[N]={0};
   int i, j, k, m, cnt, count, max=0;
   int mode_cnt=0;
   int num;
   int v;
   vector<int> results;
   vector<int>::iterator pos;

//loop to count an array from left to right
   for(k=0; k<size; k++) {
      cnt=0;
      num=x[k]; //num will equal the value of x[k]

      for(i=k; i<size; i++) {   
         if(num==x[i])
            cnt++;              
      }
      y[k]=cnt; //
   }

//find highest number in array
   for(j=0; j<size; j++) {
      if(y[j]>max)
         max=y[j];
   }

//find how many modes there are
   for(m=0; m<size; m++) {
      if(max==y[m])
         mode_cnt++;
   }

//push results to vector
   for (m=0; m < size; m++) {
      if(max == y[m]) {
//after taking out this line the code works properly
//      std::cin >> x[m];      
       results.push_back(x[m]);
      }
   }

//sort vector and print
   std::sort(results.begin(), results.end());
   cout << "The mode(s) is/are: ";
   for (pos=results.begin(); pos!=results.end(); ++pos) {
         cout << *pos << " ";
   }
}