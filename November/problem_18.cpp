class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end()); 
        vector<vector<int>> ans;
        for(auto& e: intervals){
            if(ans.empty() || e[0] > ans.back()[1]) ans.push_back(e);
            else ans.back()[1] = max(ans.back()[1], e[1]);
        }
        return ans;
    }
};
