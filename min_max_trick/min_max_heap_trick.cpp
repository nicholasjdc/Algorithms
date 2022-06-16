#include <queue>
#include<vector>
#include <iostream>
using namespace std;

//simulating stream through vector
int find_median(vector<int> stream){
    priority_queue<int, vector<int>, std::greater<int> > minHeap;
    priority_queue<int> maxHeap;

    for(int i =0; i<stream.size();i++){
        if(minHeap.empty()){
            minHeap.push(stream[i]);
        
        }else if(maxHeap.empty()){
            maxHeap.push(stream[i]);
        }else{
            if(stream[i] > minHeap.top()){
                minHeap.push(stream[i]);
            }else{
                maxHeap.push(stream[i]);
            }
        }
        if(maxHeap.size() > minHeap.size() +1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    return maxHeap.size()>minHeap.size()? maxHeap.top(): minHeap.top();

}
int main(){
    cout<<find_median({5,8,3,2,2,10,4})<<endl;

}