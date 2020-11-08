class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            return vector<int>(1,0);
        }
        
        vector<unordered_set<int>> adj(n);
        for(vector<int> ed:edges)
        {
            adj[ed[0]].insert(ed[1]);
            adj[ed[1]].insert(ed[0]);
        }
        
        queue<int> q;
        for(int i=0; i<adj.size(); ++i)
        {            
            if(adj[i].size()==1)
                q.push(i);
        }
        
        while(n>2)
        {
            int len = q.size();
            n=n-len;
            for(int i=0; i<len; ++i)
            {
                int node = q.front(); q.pop();
                unordered_set<int> &ad=adj[node];                 
               
                for(auto a:ad)
                {
                    unordered_set<int> &adOfAdjNode=adj[a]; 
                    adOfAdjNode.erase(node);
                    if(adOfAdjNode.size()==1)
                        q.push(a);
                }
            }
        }
        
       
        vector<int> out;
        while(!q.empty())
        {
            out.push_back(q.front()); q.pop();
        }
        return out;
    }
};
