/*
Q1)-: Build BST from PreOrder traversal --->>>

        Node* solve( int pre[] , int size , int &index , int max , int min){
         // base case 
         if(index >= size){
             return  NULL ;
         }
         
        if( pre[index] > max  || pre[index] < min){
            return NULL ;
        }
        
        Node * root = newNode(pre[index++]);
        
        root->left = solve(  pre , size , index , root->data , min);
        root->right = solve(  pre , size , index , max , root->data);
        
        return root ;
         
     }
    Node* Bst(int pre[], int size) {
        int i = 0 ;
         Node * head = solve( pre , size , i , INT_MAX , INT_MIN);
         return head ;
    }

  
    Greedy Algorithms starts from here ----->>>>


    Q2)-: N meetings in One Room ---->>> 
       
     static bool cmp(pair<int,int> a , pair<int , int> b){
          return a.second < b.second ;
     }
    int maxMeetings(int start[], int end[], int n)
    {
        int count = 1 ;
       vector<pair<int , int> > v ;
       
       for( int i = 0 ; i<n ; i++){
           pair<int, int> p = make_pair(start[i] , end[i]);
           v.push_back(p);
       }
       
       sort( v.begin() , v.end() , cmp);
       
       int finish = v[0].second ;
       
       for( int i = 1 ; i<n ; i++){
           int starting = v[i].first ;
           if( starting > finish){
               count++ ;
               finish = v[i].second ;
           }
       }
       return count ;
    }

  Q3)-: Job sequencing problems ------>>>>>>

     static bool cmp( Job a , Job b){
         return a.profit > b.profit ;
     }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort( arr , arr+n , cmp);
        
        int maxdeadline = INT_MIN ;
        
        for( int i =0 ; i<n ; i++){
            maxdeadline = max( maxdeadline , arr[i].dead);
        }
        
        vector<int> schedule(maxdeadline + 1 ,  -1);
         int count = 0 ;
         int maxProfit = 0 ;
        for( int i = 0 ; i<n ; i++){
            int currId = arr[i].id ;
            int currdead = arr[i].dead ;
            int currProfit = arr[i].profit ;
            
            for( int k = currdead ; k > 0 ; k--){
                if(schedule[k] == -1){
                    count++ ;
                    schedule[k] = currId ;
                    maxProfit += currProfit ;
                    break ;
                }
            }
        }
        vector<int> ans ;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans ;
    } 
     

     Q4)-: Huffman Encoding ----->>>>>

      
  class Node{
      public:
      Node*left ;
      Node*right ;
      int data ;
      
      Node(int data){
          left = NULL ;
          right = NULL ;
          this->data =data ;
      }
  };
  
  class cmp{
      public:
      bool operator()(Node*a , Node*b){
          return a->data > b->data ;
      }
  };
class Solution
{
	public:
	  void traverse(Node* root , vector<string>&ans , string temp){
	      // base case 
	      if(root->left == NULL && root->right == NULL){
	          ans.push_back(temp);
              return ;
	      }
	      
	      traverse(root->left , ans , temp +'0');
	      traverse(root->right , ans , temp +'1');
	  }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		   priority_queue<Node* , vector<Node*> , cmp> pq ;
		   
		   for( int i = 0 ; i<N ; i++){
		       Node* temp = new Node(f[i]);
		       pq.push(temp);
		   }
		   
		   while(pq.size() > 1){
		       Node*left = pq.top();
		       pq.pop();
		       Node*right = pq.top();
		       pq.pop();
		       
		       Node*newNode = new Node(left->data + right-> data);
		       
		       newNode->left = left ;
		       newNode->right = right ;
		       
		       pq.push(newNode);
		   }
		   
		   Node*root = pq.top();
		   
		   vector<string> ans ;
		   string temp = "";
		    traverse( root, ans , temp) ;
		    return ans ;
		}
};
*/