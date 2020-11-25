class Solution {
public:
    int smallestRepunitDivByK(int K) {
     if(K%2 == 0 || K%5 == 0) return -1;
      int rez = 1;                          
      int remainder = 1;              
      int total = 1;                        
      while(total%K != 0){
        rez++;
        remainder = (remainder*10)%K;
        total = (total + remainder)%K;
      }
      return rez;   
    }
};
