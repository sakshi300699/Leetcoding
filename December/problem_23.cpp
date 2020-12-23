class Solution {
public:
    int nextGreaterElement(int n) {
         int temp = n;
        vector<int>digits;
        //Getting digits from n
        while(temp>0){
            digits.push_back(temp%10);
            temp/=10;
        }
        //reverse the order of digits array
        reverse(digits.begin(), digits.end());
        //Finding the next smallest integer greater than n
        next_permutation(digits.begin(), digits.end());
        long long int res = 0;
        for(int i=0; i<digits.size(); i++){
            res+=(pow(10, digits.size()-i-1)*digits[i]);
        }
        if((res > pow(2,31)-1) || (res < 0) || (res <= n)){
            return -1;
        }
        return res;
    }
};
