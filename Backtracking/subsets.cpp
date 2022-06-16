 #include <vector>
 using namespace std;
 vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> emptySet = {};
    subs.push_back(emptySet);
    
    for(int i =0; i<nums.size(); i++){
        vector<int> currSet = {nums[i]};
        subs.push_back(currSet);
        vector<vector<int>> expandedSubs = expandSubsets(nums, i+1, currSet);
        subs.insert( subs.end(), expandedSubs.begin(), expandedSubs.end());
    }
    return subs;
}
vector<vector<int>> expandSubsets(vector<int>& nums,int index, vector<int> currSet){
    vector<vector<int>> subs;
    for(int i =index; i<nums.size();i++){
        vector<int> newSet= {nums[i]};
        newSet.insert(newSet.end(), currSet.begin(), currSet.end());
        subs.push_back(newSet);
        vector<vector<int>> expandedSubs = expandSubsets(nums, i+1, newSet);
        subs.insert( subs.end(), expandedSubs.begin(), expandedSubs.end());
        
    }
    return subs;
    
}