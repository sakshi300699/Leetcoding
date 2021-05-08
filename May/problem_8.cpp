class Solution {
public:
     long long l, r;
    long long ans = 0;
    bool isPalindrome(long long num) {
        string s = to_string(num);
        int n = s.size();
        int low = 0;
        int high = n - 1;
        while(low < high) {
            if(s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    long long to_integer(string s) {
        int n = s.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
    void dfs(int pos, long long num) {
        if(pos == 10) {
            long long sq = num * num;
            if(sq >= l && sq <= r && isPalindrome(num) && isPalindrome(sq)) {
                ans++;
            }
            return;
        }
        dfs(pos + 1, num * 10 + 0);
        dfs(pos + 1, num * 10 + 1);
        dfs(pos + 1, num * 10 + 2);
    }
    int superpalindromesInRange(string left, string right) {
         l = to_integer(left);
        r = to_integer(right);
        dfs(0, 0);
        if(9 >= l && 9 <= r)
            ans++;
        return ans;
    }
};
