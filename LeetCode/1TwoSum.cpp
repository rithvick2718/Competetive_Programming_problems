#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; //we return this
        vector<pair<int,int>> Num_Index; //See right now I don't have a better way
        int i=0;
        for(int num : nums)
        {
            Num_Index.push_back({num,i});
            i++;
        } // O(n) Space and Time -> I don't like I take O(n) space
        sort(Num_Index.begin(),Num_Index.end()); //O(nlogn)
        int low =0; int high =i-1;
        while(low<high)
        {
            if(Num_Index[low].first+Num_Index[high].first > target) high--;
            else if(Num_Index[low].first+Num_Index[high].first<target) low++;
            else break; 
        } // O(n)
        ans.push_back(Num_Index[low].second);
        ans.push_back(Num_Index[high].second);
        return ans;
    }
};