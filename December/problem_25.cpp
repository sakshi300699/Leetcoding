class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
          vector<int> res;
        int n = a.size();
        
        if(n == 0)
            return res;
        int m = a[0].size();
        
        int i=0,j=0;
        int c = 0;
        
        while(c < m*n)
        {
            //move in up-right direction until boundary occurs
            while(i >= 0 && j < m)
            {
                res.push_back(a[i--][j++]);
                c++;
            }
            i++;
            if(j == m)
            {
                i++;
                j--;
            }
            
            //move in down-left direction until boundary occurs
            while(j >= 0 && i < n)
            {
                res.push_back(a[i++][j--]);
                c++;
            }
            j++;
            if(i == n)
            {
                j++;
                i--;
            }
        }
        return res;
    }
};
