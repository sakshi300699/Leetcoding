class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        for(int i = 0;i<A.size();i++){
            reverse(A[i].begin(), A[i].end());
        }
        for(int i = 0;i<A.size();i++){
            int n = A[0].size();
            for(int j=0;j<n;j++){
               if(A[i][j]==0)
                   A[i][j]=1;
                else
                    A[i][j]=0;
            }
        }
        
        
        return A;
    }
};
