/*
 Q1)-: Find the minimum distance between the two nodes 

    void findDistance(Node* root , int a , int count , int& ans){
         // base case 
         if(root == NULL){
             return ;
         }
         if(root->data == a){
             ans = count ;
             return ;
         }
         
         findDistance(root->left , a , count +1 , ans);
         findDistance(root->right , a, count + 1 , ans);
     }
     Node* solve( Node* root , int a , int b){
         // base case 
         if(root == NULL){
             return NULL ;
         }
          if( root->data == a || root->data == b){
              return root ;
          }
          
          Node*leftAns = solve(root->left , a , b);
          Node* rightAns = solve(root->right , a , b);
          
          if(!root->right && !root->left) return NULL ;
          if(!leftAns) return rightAns ;
          if(!rightAns) return leftAns ;
           return root ;
     }
    int findDist(Node* root, int a, int b) {
        
        Node * lca = solve(root , a , b);
        int ans1 = 0 , ans2 = 0 ;
        findDistance(lca , a , 0 , ans1);
        findDistance(lca , b , 0 , ans2);
        
        return ans1 + ans2  ;
    }



Q2)-:Finding the Kth Ancestor of Node in the Binary Tree --->>>>>

     int KthAncestor(Node* root , int node , vector<int>  & ans){
        // base case 
        if(root == NULL){
            return 0 ;
        }
        if(root->data == node){
            ans.push_back(root->data);
            return 1 ;
        }

        int left = KthAncestor(root->left , node , ans);
        int right = KthAnscestor(root->right , node , ans);

        if(left || right){
           ans.push_back(root->data);
           retrun 1 ;
        }else{
            return 1 ;
        }
     }

      -->> after the function we can return the Kth No. of Ancestor from the vector 



Q3)-: Print All the Duplicates SubTrees in the Binary Tree 

   string solve(Node* root , vector<Node*> &s1 , map<string , int> & A){
     // base case 
     if(root == NULL){
         return "$";
     }
     
     string s  = "";
     
      s =root->data;
      s+= solve(root->left , s1 , A) + "/" ;
      s += solve(root->right , s1 , A)+ "/";
       A[s]++ ;
      if(A[s] == 2){
          s1.push_back(root);
      }
      return s ;
 }
vector<Node*> printAllDups(Node* root)
{
    vector<Node*> duplicates ;
    map<string , int> ALLStrings ;
    solve(  root , duplicates ,ALLStrings);
    return duplicates ;
}


 Q4)-: Check if the Tree is Isomorphic or Not --->>

    bool isIsomorphic(Node *root1,Node *root2){
        if(!root1 && !root2)return true;
        if(!root1 && root2)return false;
        if(root1 && !root2)return false;
        if(root1->data!=root2->data)return false;
        return (isIsomorphic(root1->left,root2->right)&&isIsomorphic(root1->right,root2->left)) || 
               (isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right));
    }
*/