#include <vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> subs;
    set<vector<int>>    subsAsSet;
    vector<int> emptySet = {};
    subs.push_back(emptySet);

    for(int i =0; i<nums.size(); i++){
        vector<int> currSet = {nums[i]};
        pair<set<vector<int>>::iterator, bool> newPair = subsAsSet.insert(currSet);
        if(newPair.second){
                subs.push_back(currSet);
            vector<vector<int>> expandedSubs = expandSubsets(nums, i+1, currSet, subsAsSet);
            subs.insert( subs.end(), expandedSubs.begin(), expandedSubs.end());
        }else{}
        
        
        
    }
return subs;
}
vector<vector<int>> expandSubsets(vector<int>& nums,
                                  int index, vector<int> currSet, set<vector<int>>& subsAsSet){
    vector<vector<int>> subs;
    for(int i =index; i<nums.size();i++){
        vector<int> newSet= {nums[i]};
        newSet.insert(newSet.end(), currSet.begin(), currSet.end());
        sort(newSet.begin(), newSet.end());
        pair<set<vector<int>>::iterator, bool> newPair = subsAsSet.insert(newSet);
        if(newPair.second){
             subs.push_back(newSet);
            vector<vector<int>> expandedSubs = expandSubsets(nums, i+1, newSet, subsAsSet);
             subs.insert( subs.end(), expandedSubs.begin(), expandedSubs.end());
        }else{}
       
        
    }
    return subs;
    
}