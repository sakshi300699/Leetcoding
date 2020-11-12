class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> curr;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        permute_unique_bt(nums, used, result, curr);
        return result;
    }
    
    void permute_unique_bt(vector<int>& nums, vector<bool>& used, vector<vector<int>>& result, vector<int>& curr, int k = 0){
        if(k == nums.size()) 
            result.push_back(curr);  
        else {
            for(int i = 0; i != nums.size(); ++i){ 
                if(!used[i] && (i == 0 || nums[i] != nums[i-1] || !used[i-1])){ 
                    used[i] = true;
                    curr.push_back(nums[i]); 
                    permute_unique_bt(nums, used, result, curr, k+1);
                    used[i] = false;
                    curr.pop_back();
                }
            }   
        }
    }
};

