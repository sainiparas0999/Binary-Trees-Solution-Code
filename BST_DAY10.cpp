/*
Q1)-: Find the median of the Binary Search tree 
 
  void solve( Node* root , vector<int>&ans){
     // base case
     if(root == NULL){
         return ;
     }
     
     solve(root->left , ans);
     ans.push_back( root ->data);
     solve(root->right , ans);
 }
float findMedian(struct Node *root)
{
      vector<int> ans ;
      solve( root , ans);
      int n = ans.size() ;
      if( n % 2 != 0){
          float res =  ans[n/2];
          return res ;
      }else{
           float res1 = ans[n/2];
           float res2 = ans[(n/2)-1] ;
           return  (res1 + res2)/2 ;
      }
}




 Q2)-: Count BST nodes that lies in given Nodes --->>>

       void solve( Node* root , int l , int h , int &count){
         // base case 
         if(root == NULL){
             return ;
         }
         if(root->data <= h && root->data >= l){
             count++ ;
             solve(root->left , l , h , count);
             solve(root->right , l , h , count);
         }else if( root ->data > h){
             solve(root->left , l , h , count);
         }else if( root->data < l){
             solve( root->right , l , h , count);
         }
     }
public:
    int getCount(Node *root, int l, int h)
    {
       int count = 0 ;
       solve( root , l , h , count);
       return count ;
    }


    Q3)-: Replace Every element with the least greater element in their right ;

         vector<int> findLeastGreater(vector<int>& arr, int n) {
         vector<int> ans(n , -1) ;
         set<int> s ;
         
         for( int i = n-1 ; i>= 0 ; i--){
             s.insert(arr[i]);
             
             auto it = s.upper_bound(arr[i]);
             if(it != s.end()){
                 ans[i] =*it ;
             }
         }
         return ans ;
    }


    Q4)-: Flatten a Binary search Tree into sorted linked list 

     void solve(Node *root , Node* &prevs ){
        // base case 
        if(root == NULL){
            return ;
        }

        solve( root->left , prevs);
        Node * curr = new Node(root->data);
        prevs->right = curr ;
        curr->right = NULL ;
        prevs = curr ;

        solve(root -> right , prevs);
     }

     Node * main( Node* root ){
        Node * head = new Node(-1);
        head->left = NULL ;
        solve( root , head);
        prevs->left = NULL ;
        prevs->right = NULL ;
        return head ->right;
     }
*/