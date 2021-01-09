class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0,j = 0;
        int iind = 0;
        int jind = 0;
        
        while(i<word1.size() and j<word2.size()){
            
            if(word1[i][iind] != word2[j][jind]){
                return false;
            }
            iind++;
            jind++;
            if(iind>=word1[i].size()){
                iind = 0;
                i++;
            }
            if(jind>=word2[j].size()){
                jind = 0;
                j++;
            }
            
        }
        if(i<word1.size() or j<word2.size()){
            return false;
        }
        return true;
    }
};
