/*
 Q1) -: Function to return a list containing elements of left view of the binary tree.


a) ITERATIVE METHOD--->>>>
vector<int> leftView(Node *root){
    vector<int> ans ;
    queue<Node*> q ;
    
    q.push(root) ;
    q.push(NULL);
    
    if(root == NULL){
        return ans ;
    }
   ans.push_back(root->data);
   
   while(!q.empty()){
       
       Node* temp = q.front();
       q.pop();
       
       if(temp == NULL){
          if(!q.empty()){
           ans.push_back(q.front() -> data);
           q.push(NULL);
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
   return ans ;
}

b) RECCURSIVE METHOD --->>>>>> 

 void solve(Node* root , vector<int> &ans , int level){
     // base case 
     if(root == NULL){
         return ;
     }
      if(level == ans.size()){
          ans.push_back(root->data);
      }
     solve(root-> left , ans , level+ 1);
     solve(root->right , ans , level + 1) ;
 }
vector<int> leftView(Node *root)
{
   
   vector<int> ans ;
   solve( root , ans , 0) ;
   return ans ;
   
}




Q2)-: RightView of a Binary tree 

ANS -: Just swap the calls of Recursion method , you will get the right view 



q3)-: TOP and BOTTOM view of the Tree ---->>>

  TOP view -: 
  vector<int> topView(Node *root)
    {
        queue<pair<Node* , int>> q ;
        map<int , int > topNode ;
        vector<int> ans ;
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            
            pair<Node* , int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second ;
            
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data ;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left , hd-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right , hd+1));
            }
        }
        
        for(auto i :topNode){
           ans.push_back(i.second); 
        }
        
        return ans ;
    }


    BOTTOM VIEW -: 

       vector <int> bottomView(Node *root) {
        
        queue<pair<Node* , int>> q ;
        map<int , int > topNode ;
        vector<int> ans ;
        q.push(make_pair(root , 0));
        
        while(!q.empty()){
            
            pair<Node* , int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second ;
            
       
            topNode[hd] = frontNode->data ;
            
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left , hd-1));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right , hd+1));
            }
        }
        
        for(auto i :topNode){
           ans.push_back(i.second); 
        }
        
        return ans ;
    }

 
  Q4)-: Zig-Zag traversal of the tree ---->>>>

     Here I am Using the Level order Traversal and keep Tracking of the level and storing the data Accordingly in the main vector

      vector <int> zigZagTraversal(Node* root)
    {
        int flag = 0 ;
    	vector<int> ans ;
    	vector<int> tempVector ;
    	queue<Node*> q ;
    	
    	q.push(root);
    	q.push(NULL);
    	
      while(!q.empty()){
	    Node *temp = q.front();
	    q.pop();
	    
	      if(temp == NULL){
	          if(!q.empty()){
	              if(flag == 1){
	                  reverse(tempVector.begin() , tempVector.end());
	                  flag = 0 ;
	              }else{
	                  flag = 1 ;
	              }
	              for(auto i : tempVector){
	                  ans.push_back(i);
	              }
	              tempVector.clear();
	              q.push(NULL);
	          }
	      }else{
	           tempVector.push_back(temp->data);
	          if(temp->left){
	              q.push(temp->left);
	          }
	          if(temp->right){
	              q.push(temp->right);
	          }
	      }
	   
	    }
	    
	    if(flag ==1){
	      reverse(tempVector.begin() , tempVector.end());  
	    }
	    
	     for(auto i : tempVector){
	      ans.push_back(i);
	      }
	    
	    return ans ;
     
    }



Q5)-: Check if the tree is Balanced or not ---->>>>>>

      int solve( Node*root , bool &ans){
         // base case 
         if(root == NULL){
             return 0 ;
         }
         
         int left = solve( root->left , ans)  ;
          int right = solve(root->right , ans);
          
         if(abs(left - right) > 1){
             ans = false ;
         }
         
         return max(left , right)+ 1 ;
         
     }

    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    { 
       bool ans = true ; 
       int height =  solve(root , ans) ;
        return ans ;
       
    }


*/


