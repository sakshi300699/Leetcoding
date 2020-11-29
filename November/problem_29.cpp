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
        
        
        arr[start] = -1;
        
        bool ans = canReach(arr, start+temp)
                   || canReach(arr, start-temp);
        
        
        arr[start] = temp;
        
        return ans;
    }
};
