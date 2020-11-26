class Solution {
public:
    int longestSubstring(string s, int k) {
       int n=s.length();
        if(n==0 || k>n){
            return 0;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;  //frequency map 
        }
        int j=0;
        while(j<n && mp[s[j]]>=k){
            j++;  //if frequency of each character is more than k 
            }
            if(j>=n-1){
                return j; //if we reach the end of string
            }
        int substring1=longestSubstring(s.substr(0,j),k); 
        while(j<n && mp[s[j]]<k){ // if more than one character appears which has frequency less than k
            j++;
        }
        int substring2;
        if(j<n){ 
             substring2=longestSubstring(s.substr(j),k);
        }else{
             substring2=0;
        }
        return max(substring1,substring2);
    }
};
