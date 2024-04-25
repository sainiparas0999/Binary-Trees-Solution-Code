
    /* 
    
     Q1)-: Function to return the level order traversal of a tree.--->>>>>

    vector<int> levelOrder(Node* root)
    {
      queue<Node*> q ;
      vector<int> ans ;
      
      q.push(root);
      q.push(NULL);
      
      while(!q.empty()){
          Node * temp = q.front();
          q.pop();
          
          if(temp == NULL){
             if(!q.empty()){
                 q.push(NULL);
             } 
          }else{
              ans.push_back(temp->data);
              if(temp->left){
                  q.push(temp->left);
              }
              if(temp->right){
                  q.push(temp->right);
              }
          }
      }
      return ans ;
    }




   Q2) -: function to Reverse the level order traversal 

     INput -:  1
              2     3
            4  5   6  7    

    OUtPUt -: 7 6 5 4 3 2 1  


    vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*> q ;
    vector<int> ans ;
    
     q.push(root);
    while(!q.empty()){
       Node* temp = q.front();
       q.pop();
       ans.push_back(temp->data);
       
       if(temp->right){
           q.push(temp->right);
       }
       
       if(temp->left){
           q.push(temp->left);
       }
       
    }
     reverse(ans.begin() , ans.end());

    return ans ;
}





Q3)-:  Finding the Height of TREE -->>>

 1) -->>  BY USING LEVEL ORDER TRAVERSAL  METHOD 

  int height(struct Node* node){
        queue<Node*> q ;
        q.push(node);
        q.push(NULL) ;
        
        int count = 1 ;
        
        while(!q.empty()){
           
           Node * temp = q.front();
           q.pop();
           if(temp == NULL){
               if(!q.empty()){
                   q.push(NULL);
                   count++ ;
               }
           }else{
               if(temp->left){
                   q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
           }
        }
        return count ;
    }

 2)---->>  BY USING RECURSION METHOD

 class Solution{
    private:
     int solve(Node* &root ){
         // base case 
         if(root-> left == NULL && root->right== NULL){
             return 1;
         }
         
         if(root->left == NULL){
             return solve(root->right) + 1 ; 
         }
         
         if(root->right == NULL){
             return solve(root->left) + 1 ;
         }
         
         return max(solve(root->left) , solve(root->right) ) + 1 ;
     }
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
     int count = solve(node);
      return count ;
    }
}; 





 Q4)-: Finding the diameter of the Binary Tree---->>>>>

 class Solution {
    private:
    
    int solve( Node* root , int &maxDia){
        // base case
        if( root == NULL){
            return 0 ;
        }
        int ans1 = solve(root->left , maxDia) ;
        
        int ans2 = solve(root->right , maxDia) ;
        
        maxDia = max(maxDia , ans1+ans2+1);
        return max(ans1 , ans2) + 1 ;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        int maxDia = 0 ;
        int count = solve(root , maxDia);
        return maxDia ;
    }
};


We also have the three basics traversal algorithms of Binary trees 

1-> Preorder traversal 
2-> Inorder Traversal 
3-> PostOrder traversal




Q5)-: MIRROR a given Binary tree ->>>>>>

treenode* mirrorTree(node* root)
{
    // Base Case
    if (root == NULL)
        return root;
    node* t = root->left;
    root->left = root->right;
    root->right = t;
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return root;
}


*/



