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
            result.push_back(curr);  // add current permutation to solutions
        else {
            for(int i = 0; i != nums.size(); ++i){ // explore all candidates for the current position
                if(!used[i] && (i == 0 || nums[i] != nums[i-1] || !used[i-1])){ // selection of valid candidate
                    used[i] = true; // mark candidate as used for the current solution
                    curr.push_back(nums[i]); // add the candidate to the current permutation
                    permute_unique_bt(nums, used, result, curr, k+1); // produce the rest of the permutation
                    used[i] = false; // re-add candidate for use in other permutations
                    curr.pop_back(); // remove candidate from current solution at this position in the permutation
                }
            }   
        }
    }
};

