/*
 Q1)-: Search a node in the binary tree---->>>>
  
 
  a)-: Recursive method
   bool Search(Node* root , int value){
    // base case 

    if(root == NULL){
        return false ;
    }
    if(root->data == value){
        return true ;
    }

    if(root->data < value){
      return Search(root->right , value);
    }else{
        return Search(root->left , value);
    }
   }

   b)-: Iterative Method

   bool Search(Node* root , int value){
    
     while(root != NULL){
        if(root->data == value){
           treturn true ; 
        }else if(root->data > value){
            root = root->left ;
        }else{
            root = root->right ;
        }
     }
     return false ;

   }


   Q2)-: Insertion in Binary Search Tree --->>>

     Node* Insertion(Node* root , int key){
        // base case 
        if(root == NULL){
            Node* ans = new Node( data); 
            return ans ;
        }
        if(root ->data >key){
            root->left = Insertion(root->left ,key);
        }else{
            root -> right = Insertion(root->right , key);
        }
        return root ;
     }

     


   Q3)-:  Delete the Node in Binary search tree ----->>>>>

     class Solution {
public:
  TreeNode* minValueNode( TreeNode * root){
       TreeNode* curr = root ;
       while(curr != nullptr && curr->left != nullptr){
           curr = curr->left ;
       }
       return curr ;
  }
    TreeNode* deleteNode(TreeNode* root, int key) {
          if(root == nullptr)
            return root;
        
        if(root->val > key)
            root->left = deleteNode(root->left,key);
        
        else if(root->val < key)
            root->right = deleteNode(root->right,key);
        
        else
        {
            //Only right children is present
            if(root->left == nullptr)
            {
                root = root->right;
                return root;
            }

            else if(root->right == nullptr)
            {
                root = root->left;
                return root;
            }

            TreeNode*temp = minValueNode(root->right);
            root->val = temp->val;

            root->right = deleteNode(root->right,temp->val);
        }

        return root;
    }
};

  
   Q4)-: Find Successor and Precessdor in the Binary search Tree 

        void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node * temp = root ;
        
        while(temp  != NULL){
            if(temp ->key == key){
                break ;
            }
            else if(temp -> key > key){
                suc = temp ;
                temp = temp->left ;
            }else {
                pre = temp ;
                temp = temp->right ;
            }
        }
        if(temp == NULL){
            return ;
        }
        
        Node * leftTree = temp->left ;
        while(leftTree != NULL){
            pre = leftTree ;
            leftTree = leftTree->right ;
        }
        
        Node * rightTree = temp->right ;
        while(rightTree != NULL){
            suc = rightTree ;
            rightTree = rightTree->left ;
        }
        
    }
*/