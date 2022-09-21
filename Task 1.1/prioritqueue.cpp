/*Given “n” ropes of different lengths, connect them into a single rope with 
minimum cost. Assume that the cost to connect two ropes is the same as the 
sum of their lengths.*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct rope
{
   int length;
   int priority;
};

rope p[100];
int s=-1; 

void enqueue(int length,int priority){
   s++;
   p[s].length=length;
   p[s].priority=priority; 
   
};

int Top()
{
    int highestPriority = INT_MIN;
    int ind = -1;
 
    for (int i = 0; i <= s; i++) {
 
        if (highestPriority == p[i].priority && ind > -1
            && p[ind].length > p[i].length) {
            highestPriority = p[i].priority;
            ind = i;
        }
        else if (highestPriority < p[i].priority) {
            highestPriority = p[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = Top();
    for (int i = ind; i < s; i++) {
        p[i] = p[i + 1];
    }
    s--;
}
int len()
{
   int count;
    int ind = Top();
    for (int i = ind; i < s; i++) {
        count++;
    }
    s--;
    return count;
}

int main(){
   cout << "length of ropes\n";
   int arr[]={3,5,24,5,1,7,8};
   enqueue(3,2);
   enqueue(5,4);
   enqueue(24,6);
   enqueue(1,1);
   enqueue(7,4);
   enqueue(8,5);
   int price=0;
   for (int i=0;i<len()/2;i++){
    int ind = Top();
    ind = Top();
    cout << p[ind].length << endl;
    price=price+p[ind].length;
    dequeue();
    ind = Top();
    cout << p[ind].length << endl;
    price=price+p[ind].length;
    dequeue();
   }
   cout <<"\nprize of ropes\n"<<price;
    return 0;
};
