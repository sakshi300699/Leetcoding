class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        if(len == 0){
            return 0;
        }

        unordered_map<int,int> AB;
        unordered_map<int,int> CD;
        
        int count = 0;
        int ab = 0;
        int cd = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                ab = A[i]+B[j];
                cd = 0-(C[i]+D[j]);
                
                if(AB.count(ab) == 0){
                    AB[ab] = 1;
                }
                else{
                    AB[ab]++;
                }
                
                if(CD.count(cd) == 0){
                    CD[cd] = 1;
                }
                else{
                    CD[cd]++;
                }
            }
        }
        
        for(auto it:AB){
            ab = it.first;
            count += AB[ab]*CD[ab];
        }

        return count;
    }
};
