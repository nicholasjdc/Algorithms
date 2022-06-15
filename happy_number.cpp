#include <string>
#include<set>
#include<iostream>
using namespace std;
bool happy_check(int n){
    set<int> nums;
    int current_num = n;
    nums.insert(current_num);
    
    while(true){

        if(current_num == 1) return true;
        int new_num =  sum_square(current_num);
        pair<std::set<int>::iterator, bool> new_pair = nums.insert(new_num);
        if(!new_pair.second) return false;
        
        current_num = new_num;

    }
}

int sum_square(int n){

    int sum = 0;
    string s = to_string(n);
    for(int i =0; i < s.length(); i++){
        int val = s[i] - '0';
        sum += val*val;
    }
    return sum;

}
int main(){
    int n;
    cin>>n;
    cout<<happy_check(n)<<endl;
}