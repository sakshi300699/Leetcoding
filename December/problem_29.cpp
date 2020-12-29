 void treeTraverse(TreeNode* root, vector<int>&numFreq, int& oddFreq, int& count)
    {
        // increment node value frequency
        numFreq[root->val]++;
        
        // update oddFreq count based on updated node frequency count
        if(numFreq[root->val]&1)oddFreq++;
        else oddFreq--;
        
        // leaf node
        if(!root->left && !root->right)
        {
            // odd frequency node count < 2 then increment Pseudo-Palindromic path count
            if(oddFreq<2)
                count++;
            
            // restore node value frequency
            numFreq[root->val]--;
            
            // restore oddFreq count
            if(numFreq[root->val]&1)oddFreq++;
            else oddFreq--;
            
            return;
        }
        
        // traverse left child if not NULL
        if(root->left)
            treeTraverse(root->left,numFreq,oddFreq,count);

        // traverse right child if not NULL
        if(root->right)
            treeTraverse(root->right,numFreq,oddFreq,count);

        // restore node value frequency
        numFreq[root->val]--;
        
        // restore oddFreq count
        if(numFreq[root->val]&1)oddFreq++;
        else oddFreq--;        
    }
