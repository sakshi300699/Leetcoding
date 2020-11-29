class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start>=arr.size() || start < 0 || arr[start] == -1){
            return false;
        }
        
        if (arr[start] == 0){
            return true;
        }
        
        int temp = arr[start];
        
        //To not visit the same position again
        //Set to some random value and check in the base condition
        arr[start] = -1;
        
        bool ans = canReach(arr, start+temp)
                   || canReach(arr, start-temp);
        
        //Reset to original Value
        arr[start] = temp;
        
        return ans;
    }
};
