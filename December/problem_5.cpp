class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         if (n == 0) return true;
        if (flowerbed.size() == 0) return false;
        if (flowerbed.size() == 1) return flowerbed[0] == 0;
        
       
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        
        
        int flowers = 0, i = 0;
        while ((i < flowerbed.size() - 2) && (flowers < n)) {
            if ((flowerbed[i] == 0) && (flowerbed[i+1] == 0) && (flowerbed[i+2] == 0)) {
                flowers++;
                flowerbed[i+1] = 1;
            }
            i++;
        }
        return flowers == n;
    }
};
