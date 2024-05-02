/*
  Q1)-: Check for BST is Valid or Not ?

        bool isvalidate(Node * root , int mini , int maxi){
        // base case 
        if(root == NULL){
            return true ;
        }
        
        if( root->data <= mini || root ->data >= maxi ){
            return false ;
        }
        bool ans1 = isvalidate( root->left , mini , root->data) ;
        bool ans2 =  isvalidate(root->right , root->data , maxi);
        
        return (ans1 && ans2);
    }
    bool isBST(Node* root) 
    {
        bool  ans = isvalidate( root , INT_MIN , INT_MAX);
        return ans ;
    }


    Q2)-: Populate Inorder Successor in the BST 

  a)-: Recurssive Method   
    Node * prev = NULL ;
    void populateNext(Node *root)
    {
       // base case 
       if(root == NULL){
           return ;
       }
       populateNext(root->left);
       if(prev){
           prev->next = root ;
       }
        prev = root ;
       populateNext(root->right);
    } 

    b)-: Iterative Method 

    void inorder(Node* root, vector<Node*>& arr){
        if(root == NULL) return;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    void populateNext(Node *root)
    {
      if(root == NULL) return;
      vector<Node*> arr;
      inorder(root,arr);
      for(int i=0; i<arr.size()-1; i++){
         arr[i]->next = arr[i+1];
      }
      arr[arr.size()] = NULL;
    }


    Q3)-: Lowest Common Ancestor in BST ---->>>

     // base case 
            if(root == NULL){
                return NULL;
            }
             Node* temp = root ;
             
             while(temp-> data != NULL){
                 if(root-> data < n1 && root -> data <n2){
                     root= root-> right ;
                 }
                 
                 else if(root-> data > n1 && root -> data >n2){
                     root= root-> left;
                 }else{
                     return root ;
                 }
             }
        
        }

        Q4)-: Find the K largest element in the BST 

             void solve(Node* root , vector<int>&ans){
         // base case
         if(root == NULL){
             return ;
         }
         solve(root ->right , ans);
         ans.push_back(root->data);
         solve(root->left , ans);
     }
    int kthLargest(Node *root, int K)
    {
         vector<int> ans ;
         solve( root , ans) ;
        //  sort(ans.begin() , ans.end());
         return ans[K-1];
    }
*/