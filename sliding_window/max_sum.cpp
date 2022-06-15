#include<iostream>
#include <vector>
using namespace std;

int max_sum(vector<int> arr){
    int curr_max = 0;
    int curr_sum = 0;

    for(int i =0; i< arr.size(); i++){
        if(curr_sum > curr_max){
                curr_max = curr_sum;
            }

        if(arr[i] >= 0){
            curr_sum +=arr[i];
        }else{
            
            curr_sum =0;
        }

    }
     if(curr_sum > curr_max){
                curr_max = curr_sum;
            }

    return curr_max;

}

int main(){
    vector<int> arr = {3,2,5, -2, 8,4,1};

    cout<<max_sum(arr)<<endl;

}