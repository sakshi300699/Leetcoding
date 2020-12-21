class Solution {
public:
    int smallestRangeII(vector<int>& a, int k) {
        sort(begin(a), end(a));
        int res = a.back() - a.front();
        for (int i = 1, n = size(a); i < n; ++i)
            res = min(res, max(a[i - 1] + k, a[n - 1] - k) - min(a[0] + k, a[i] - k));
        return res;
    }
};
