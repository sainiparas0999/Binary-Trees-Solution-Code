/*
  Q1)-: Find the two Trees are Mirror or Not 

         int checkMirrorTree(int n, int e, int A[], int B[]) {
         unordered_map<int, stack<int>> mp ;
         
         for(int i = 0 ; i<2*e ; i+=2){
            mp[A[i]].push(A[i+1]);
         }
         
         for( int i = 0 ; i<2*e ; i+=2){
             if(mp[B[i]].top() != B[i+1])
                return 0 ;
              else{
                  mp[B[i]].pop();
              }
         }
         return 1 ;
    }


  Q2)-: Sum of nodes on the longest path from root to leaf node----->>>>

     
   pair<int,int> solve(Node* root ){
        // base case 
        if(root == NULL){
            pair<int,int> ans =  make_pair(0,0) ;
            return ans ;
        }
        
        pair<int,int> leftSum =  solve(root->left );
        pair<int,int> rightSum = solve(root->right );
        
        if(leftSum.first == rightSum.first){
            int sum = max(leftSum.second , rightSum.second) + root->data;
            pair<int,int> ans = make_pair(leftSum.first + 1 ,  sum);
        }else if(leftSum.first > rightSum.first){
            
            pair<int,int> ans = make_pair(leftSum.first + 1 ,  leftSum.second + root->data);
        }else{
            pair<int,int> ans = make_pair(rightSum.first + 1 , rightSum.second + root->data);
        }
    }
  
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int,int> sum = solve(root);
        return sum.second ;
    }




  Q3)-: Find the largest SubTree sum in the Binary tree --->>>>

   
    int findLargestSubtreeSumUtil(Node* root, int& ans)
    {
        // If current node is null then
        // return 0 to parent node.
        if (root == NULL)     
            return 0;
        
        // Subtree sum rooted at current node.
        int currSum = root->key + 
        findLargestSubtreeSumUtil(root->left, ans)
        + findLargestSubtreeSumUtil(root->right, ans);
    
        // Update answer if current subtree
        // sum is greater than answer so far.
        ans = max(ans, currSum);
    
        // Return current subtree sum to
        // its parent node.
        return currSum;
    }



 Q4)-: Find the Maximum Sum of Nodes but Not the two Nodes are Adjacent to each other ---->>>>


int sumOfGrandChildren(node* node,
                       map<struct node*, int>& mp)
{
    int sum = 0;
 
    //  call for children of left child only if it is not NULL

    if (node->left)
        sum += getMaxSumUtil(node->left->left, mp)
               + getMaxSumUtil(node->left->right, mp);
 
    //  call for children of right child only if it is not NULL


    if (node->right)
        sum += getMaxSumUtil(node->right->left, mp)
               + getMaxSumUtil(node->right->right, mp);
 
    return sum;
}
 

int getMaxSumUtil(node* node, map<struct node*, int>& mp)
{
    if (node == NULL)
        return 0;
 
    // If node is already processed then return calculated
    // value from map
    if (mp.find(node) != mp.end())
        return mp[node];
 
    //  take current node value and call for all grand
    //  children
    int incl = node->data + sumOfGrandChildren(node, mp);
 
    //  don't take current node value and call for all
    //  children
    int excl = getMaxSumUtil(node->left, mp)
               + getMaxSumUtil(node->right, mp);
 
    //  choose maximum from both above calls and store that in map

    mp[node] = max(incl, excl);
    return mp[node];
}
 


int getMaxSum(node* node)
{
    if (node == NULL)
        return 0;
    map<struct node*, int> mp;
    return getMaxSumUtil(node, mp);
}




 Q5)-: Print all the paths in the Binary tree with PathSum = K ;----->>>>>> 

   In this question I am not giving the answer code but suggesting the steps 
   1) -: Initialize a string s and keep puting the root->data ;
   2) -: After everyTime putting the data check and reaching a leaf node check that pathSum is equal to k oe not ;
   4) -: if yes then store that string and go back to explore other parts ;
   5) -: while going back Remember to pop_back the root->data from the node we go back ;


Q6)-: Lowest Common ancestor in the  Binary Tree ---->>>>
  
   Node* lca(Node* root ,int n1 ,int n2 )
    {
      // base case 
      if(root == NULL){
          return NULL ;
      }
      
      if( root -> data == n1 || root->data == n2){
          return root ;
      }
      
       Node* leftAns = lca( root->left , n1 ,n2);
       Node* rightAns = lca(root->right , n1  , n2);
       
       if(root->right == NULL && root->left == NULL){
           return NULL ;
       }
       if(!leftAns){
           return rightAns ;
       }
       if(!rightAns){
           return leftAns ;
       }
        return root ;
       
    }


*/