class Solution {
public:
    int m,n;
    vector<vector<int>> G;
    int dp[71][71][71];
    int robo(int i,int j1,int j2){
        if(i>=m || j1<0 || j1>=n || j2<0 || j2>=n){
            return 0;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int ans=0;
        ans=G[i][j1];
        if(j1!=j2){
            ans+=G[i][j2];
        }
        
        int tmp=0;
        // if(i!=m-1)
        for(int k=-1;k<2;k++){
            for(int j=-1;j<2;++j){
                tmp=max(tmp,robo(i+1,j1+k,j2+j));
            }
        }
        dp[i][j1][j2]=ans+tmp;
        return dp[i][j1][j2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
         m=grid.size();
        G=grid;
        n=grid[0].size();
        int ans;
        memset(dp,-1,sizeof(dp));
        ans=robo(0,0,n-1);
        return ans;
    }
};
