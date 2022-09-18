
/*
Given “n” ropes of different lengths, connect them into a single rope with minimum cost. 
Assume that the cost to connect two ropes is the same as the sum of their lengths.
(Hint: Use Priority Queue)
*/

#include<iostream>
#include<queue>
using namespace std;

int findMinimumCost(int arr[], int n) {
   priority_queue< int, vector<int>, greater<int>>queue(arr, arr+n);

   int minCost = 0;

   while (queue.size() > 1) {              
      int item1 = queue.top();            
      queue.pop();

      int item2 = queue.top();          
      queue.pop();

      minCost += item1 + item2;         
      queue.push(item1 + item2);
   }
   return minCost;
}

int main() {
   int ropeLength[] = {7,5,4,2,9,1,3};
   int n = 7;
   cout<<"The minimum cost is "<<findMinimumCost(ropeLength,n);
}