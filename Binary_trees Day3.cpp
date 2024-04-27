/*
 Q1)-: Diagonal Traversal of The Binary Tree --->>>>

    void solve( Node* root , int hd , map<int ,vector<int> > &diagonals){
     // base case 
     if(root == NULL){
         return ;
     }
     
     diagonals[hd].push_back(root->data);
     
     solve( root->left , hd+1 , diagonals);
     solve(root->right , hd , diagonals );
     }
     
       vector<int> diagonal(Node *root)
        {
        map<int , vector<int> > diagonals ;
            solve( root , 0 , diagonals);
            vector<int> result ;
            for(auto i : diagonals){
        
        vector<int> v = i.second;
        
                for( auto j : v){
                    result.push_back(j);
                }
            }
         return result ;





Q2)-:Boundary Traversal of the tree 
  Note -: 1-: focus on finding the left Node But not leafNode 
         2-:   find the right Node But not leafNode  and find them reverse 
         3-:  find all the leaf Node 

     void solveleft(Node* root , vector<int> &left ){
         // base case
         if(root == NULL){
             return ;
         }
         if(root->left== NULL && root->right == NULL){
             return ;
         }
         left.push_back(root->data);
         
        if(root->left){
         solveleft(root->left , left );
          }
         else if(root->right){
             solveleft(root->right , left);
         }
     }
      void solveright(Node* root , vector<int> &right ){
         // base case
         if(root == NULL){
             return ;
         }
         if(root->left== NULL && root->right == NULL){
             return ;
         }
          right.push_back(root->data);
          if(root->right){
         solveright(root->right , right );
          }
         else if(root->left){
             solveright(root->left , right);
         }
     }
     
       void solve(Node* root , vector<int> &leaf ){
         // base case
         if(root == NULL){
             return ;
         }
         if(root->left== NULL && root->right == NULL){
             leaf.push_back(root->data);
             return ;
         }
          if(root->left)
         solve(root->left , leaf );
         
         if(root->right)
         solve(root->right , leaf);
         
     }
     
public:
    vector <int> boundary(Node *root)
    {
        vector<int> left ;
        vector<int> right ;
        vector<int> leaf ;
        
        solveleft(root->left , left );
        solveright(root->right , right);
        solve(root->left , leaf);
        solve(root->right , leaf);
        
        reverse(right.begin() , right.end());
        
        vector<int> result ;
        result.push_back(root->data);
        for(auto i : left){
            result.push_back(i);
        }
        
          for(auto i : leaf){
            result.push_back(i);
        }
        
        for( auto i: right){
            result.push_back(i);
        }
        return result ;
    }




Q3)-: TransForm to SumTree ------->>>>>>

   
    int solve(Node* &root){
        // base case 
         if(root == NULL){
            return 0 ;
        }
        if(root->left == NULL && root->right == NULL){
            int ans =  root->data ;
            root->data = 0 ;
            return ans ;
        }
       
        int left = solve( root->left);
        int right = solve(root->right);
        
        int ans = root->data + left + right ;
        root->data = left+right ;
        return ans;
    }
    void toSumTree(Node *root)
    {
        int ans = solve(root);
    
    }


    Q4)-: Binary Tree to DLLO(Doubly Linked List)

       Node* head = NULL;
    Node* prev = NULL;
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return root;
        bToDLL(root->left);
        if(prev==NULL) {
            prev = root;
            head = root;
        }
        else {
            root->left = prev;
            prev->right = root;
            prev = root;
        }
        bToDLL(root->right);
        
        return head;
    }

*/