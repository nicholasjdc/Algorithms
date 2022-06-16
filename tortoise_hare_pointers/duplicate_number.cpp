#include <vector>
#include<iostream>
using namespace std;

int findDuplicate(vector<int> arr){
    int turtle = 0;
    int rabbit = 0;
    //initial loop, find point of convergence
    do{
        turtle = arr[turtle];
        rabbit = arr[arr[rabbit]];
    }while(turtle != rabbit);

    //iterating from start and from convergence gives start of loop--duplicate number
    turtle = 0;
    while(turtle !=rabbit){
        turtle = arr[turtle];
        rabbit = arr[rabbit];
    }
    return turtle;
}

int main(){
    vector<int> arr = {1,4,5,3,2,3};
    cout<<findDuplicate(arr)<<endl;
}