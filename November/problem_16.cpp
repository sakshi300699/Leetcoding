class Solution {
public:
    int longestMountain(vector<int>& A) {
        int lm = 0, cm = 0, state = 0;
        for(int i = 1; i < A.size(); i++) {
            if(A[i] > A[i-1])
                if(!state and cm) cm++;
                else state = 0, cm = 2;
            else if(A[i] < A[i-1])
                if(state) cm++;
                else
                    if(cm > 0) state = 1, cm++;
                    else state = 0, cm = 0;
            else state = 0, cm = 0;
            if(state) lm = max(lm, cm);
        }
        return lm;
    }
};
