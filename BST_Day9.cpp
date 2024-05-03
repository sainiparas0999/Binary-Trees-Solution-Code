/*
 Q1)-: Change the (Binary Tree ) >--into--> (Binary Search tree) 

    void solve(Node * root , vector<int>&ans){
        // base case 
        if(root == NULL){
            return ;
        }
         ans.push_back(root->data);
         solve(root->left , ans);
         solve(root->right , ans);
    }
    
    void change(Node *root , vector<int>&ans , int &index){
        // base case
        if(root == NULL){
            return ;
        }
        change(root->left , ans , index);
        root->data = ans[index];
        index++ ;
        change(root->right , ans , index);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>ans ;
        solve( root , ans);
        sort( ans.begin() , ans.end());
         int index = 0 ;
        change( root , ans , index);
        
        return root ;
    }


    Q2)-: Normal BST to Balanced BST --->>>>>



         void InOrderTravs(Node* root , vector<Node*>&ans){
         // base case 
         if(root == NULL){
             return ;
         }
         
         InOrderTravs( root->left , ans);
         ans.push_back(root);
         InOrderTravs(root->right , ans);
     }
     
     Node* convert(vector<Node*>&ans , int start , int end){
         if(start > end){
             return NULL ;
         }
         int mid = (start+end)/2 ;
             Node * head = ans[mid];
             head->left = convert(ans , start , mid-1);
             head->right= convert(ans , mid+1 , end);
        
         return head ;
     }
    Node* buildBalancedTree(Node* root)
    {
    	 vector<Node*> ans ;
    	 InOrderTravs(root , ans );
    	 return convert( ans , 0 , ans.size()-1);
    }


  

  Q3)-:  Kth Smallest element in a BST .

         void solve(Node* root , int &ans , int& K){
         // base case 
         if(root == NULL){
             return  ;
         }
         
         solve(root->left , ans , K) ;
         K-- ;
         if(K == 0){
             ans = root->data ;
         }
         solve(root->right , ans , K) ;
         
     }
    int KthSmallestElement(Node *root, int K) {
       int ans = -1 ;
       solve( root , ans , K);
       return ans ;
    }


Q4)-: Brothers from Different roots --->>>>

       void solve(Node* root , map<int , int> & mp){
        // base case 
        if( root == NULL){
            return ;
        }
        
        mp[root->data]++ ;
        solve(root->left , mp);
        solve(root->right , mp);
    }
    
     void solve2( Node* root , map<int , int> &mp , int x , int &count){
        // base case 
        if(root == NULL){
            return ;
        }
        if(mp.find(x-root->data) != mp.end()){
            count++ ;
        }
        solve2(root->left , mp , x, count);
        solve2(root->right , mp , x, count);
     }
    int countPairs(Node* root1, Node* root2, int x)
    { 
       int count = 0 ;
       map<int , int > mp ;
       solve(root1 , mp );
       solve2( root2 , mp , x, count) ;
       return count ;
    }
*/