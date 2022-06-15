#include <vector>
#include<iostream>
using namespace std;

unsigned match_sum(vector<int> arr, int target){
    int i = 0;
    int j = arr.size()-1;
    unsigned num_pairs = 0;
    
    while(i <j){
        int curr_sum  = arr[i] + arr[j];
        if (curr_sum > target){
            j--;
        }else if (curr_sum < target){
            i++;
        }else{
            num_pairs++;
            i++;
        }
    }
    return num_pairs;
}

int main(){
 
    cout<<match_sum({1,2,3,4,5}, 5)<<endl;
}