/*
Q1)-: Construct a Tree From Inorder and PreOrder Traversal--->>>>>>
 
      int search(int curr , int in [] , int start , int end){
         for( int i = start ; i<=end ; i++){
             if(in[i] == curr){
                 return i ;
             }
         }
         return -1 ;
     }
     Node* Solve( int in[] , int pre[] , int start , int end , int& idx){
         if(start>end){
             return NULL ;
         }
         int curr = pre[idx];
         idx++;
         Node* node = new Node(curr);
         if(start == end){
             return node ;
         }
         
         int pos = search( curr , in , start , end);
         
         node->left = Solve(in , pre , start , pos-1,idx);
         node->right = Solve(in , pre , pos+1 , end,idx);
         return node ;
     }
    Node* buildTree(int in[],int pre[], int n)
    {
        int idx = 0 ;
        Node* head =  Solve( in , pre , 0 , n-1 , idx);
        return head ;
    }






  Q2)-: Minimum Number of swaps Required to convert Binary Tree to Binary Search Tree---->>>>>> 

    #include <iostream>
    #include<vector>
    using namespace std;
    int main()
    {
    vector<int> Bt = {1,2,3};
     int i = 0 ;
     int count = 0 ;
     while(2*i +1 <= Bt.size() && 2*i+2 <= Bt.size() ){
        if(Bt[2*i + 1] > Bt[i]){
            count++ ;
        }
         if(Bt[2*i + 2] < Bt[i]){
            count++ ;
        }
        i++ ;
     }
   cout<< "minimum Number of Swaps reqiured = "<<count<<" ." ;
   return 0;
}



 Q3)-: Check is Sum Tree or Not --->>>>>
  
       int solve( Node* root , bool &ans){
         // base case 
         if(root == NULL){
             return 0;
         }
         if(!root->left && !root->right){
             return root->data ;
         }
         
         int left = solve(root-> left , ans);
         int right = solve(root->right , ans);
         
         if(root->data != left  + right){
             ans = false ;
         }
         
         return root->data + left + right ;
     }
    public:
    bool isSumTree(Node* root)
    {
        if(root == NULL){
            return 1 ;
        }
        bool ans = true ;
        int result = solve( root , ans);
        return ans ;
    }




    Q4)-: Check whether all leaf nodes are at same level or not ?----->>>>>

        bool solve(Node* root , int level , int &maxlevel){
         // base case 
         if(root == NULL){
             return true ;
         }
         if(!root->left && !root->right){
            if(maxlevel == -1){
                maxlevel = level ;
            }
            if(level != maxlevel){
                return false;
            }else{
                return true ;
            }
         }
         
         bool left = solve(root->left , level+1 , maxlevel);
         bool right = solve(root->right , level+1 , maxlevel);
         
         if(left && right){
             return true ;
         }else{
             return false ;
         }
     }
    bool check(Node *root)
    {
      int level = 0 , maxlevel = -1 ;
      
      bool ans = solve(root , level , maxlevel);
      return ans ;
    }



    Q5)-: Duplicate  subTree in Binary Tree (IMP Question)----->>>

      int checkNodeType( Node*root){
        if(root == NULL){
            return 0 ;
        }
        if(root->left== NULL  && root->right == NULL){
            return 1 ;
        }else{
            return 2 ;
        }
    }
    void checkForDuplicates( Node* root , set<string>  & s1 , int &ans ){
        
      if(root==NULL){
            return;
        }
        
        int p1, p2;
        string s="";
        
        p1=checkNodeType(root->left);
        p2=checkNodeType(root->right);
        
        if(p1 == 0 && p2== 0){
              ;
        }else if( p1 == 0 && p2 == 1){
            s=root->data ;
            s+='$';
            s+=root->right->data;
            
            if(s1.find(s) != s1.end()){
                ans = 1 ;
            }
                s1.insert(s);
            
        }else if( p1 == 1 && p2 == 0){
            s=root->data ;
            s+=root->left->data;
            s+='$';
            
             if(s1.find(s) != s1.end()){
                ans = 1 ;
            }
           s1.insert(s);
        }else if( p1 ==1 && p2 ==1){
            s=root->data ;
            s+=root->left->data;
            s+=root->right->data;
            
             if(s1.find(s) != s1.end()){
                ans = 1 ;
            }
           s1.insert(s);
        }else{
            if(p1 == 2){
                checkForDuplicates(root->left , s1 , ans);
            }
            if(p2 == 2){
                checkForDuplicates(root->right , s1 ,ans);
            }
        }
        
    }
    int dupSub(Node *root) {
         set<string> duplicates ;
         int ans = 0 ;
         checkForDuplicates( root , duplicates , ans);
         return ans ;
    }
*/
