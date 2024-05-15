/*
Q1)-: Huffman Encoding ---->>>>
  
   class Node{
     public:
      int data ;
      Node* right ;
      Node* left;
      
      Node( int data){
          this->data = data ;
          right = NULL ;
          left = NULL ;
      }
 };
 
  class cmp{
     public: 
     bool operator()(Node * a , Node*b){
         return a->data > b->data ;
     }  
  };

class Solution
{
    
     public: 
     
       void traverse( Node* root , vector<string>& ans , string temp){
           
           // base case 
           if( root == NULL){
               return ;
           }
           if( root->right == NULL && root->left == NULL){
               ans.push_back(temp);
               return ;
           }
           
           if(root->left){
               traverse(root->left ,  ans , temp + '0');
           }
           if(root->right){
               traverse(root->right , ans , temp + '1');
           }
       }

		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		 
		   priority_queue< Node* , vector<Node*> , cmp> pq ;
		   
		   for( int i = 0 ; i<N ; i++){
		       Node* temp = new Node(f[i]);
		       pq.push(temp);
		   }
		   
		   while(pq.size() > 1){
		       
		       Node* left = pq.top();
		       pq.pop();
		       Node* right = pq.top();
		       pq.pop();
		       
		       Node * New = new Node( left->data + right->data);
		       
		       New->left = left ;
		       New->right= right;
		       
		       pq.push(New);
		   }
		   
		   Node * root = pq.top() ;
		   
		   vector<string> ans ;
		   string temp="";
		   traverse( root , ans , temp);
		   
		   return ans ;
		    
		}
};

 Q2)-:  Fractional Knapsack Problem -->>

       static bool cmp( pair< double , Item> a , pair< double , Item> b){
         return a.first > b.first ;
     }
     
    double fractionalKnapsack(int w, Item arr[], int n) {
        
        vector<pair< double , Item >> v;
        
        for( int i = 0 ; i<n ; i++){
            double perUnitValue = (1.0 * arr[i].value) / arr[i].weight ;
            v.push_back({perUnitValue , arr[i]});
        }
        
        sort(v.begin() , v.end(), cmp);
        
        double TotalValue = 0 ;
         int TotalWeight = w ;
         int i = 0 ;
         while(TotalWeight > 0){
             
             if(v[i].second.weight < TotalWeight ){
                 TotalValue += 1.0*(v[i].second.value) ;
                 TotalWeight = TotalWeight -  v[i].second.weight ;
             }else{
                 TotalValue += v[i].first * (1.0 * TotalWeight);
                 TotalWeight = 0 ;
             }
             
             i++ ;
         }
         
         return TotalValue ;
    }


    Q3)-: Check if it is possible to Survive on Island or Not--->>>

         int minimumDays(int S, int N, int M){
        
        int Sunday = S/7;
        
        int TotalCandy = (S-Sunday) * N ;
        int TotalFoodRequired = S*M ;
        if( TotalCandy < TotalFoodRequired ){
            return -1 ;
        }
        
        
       if( TotalFoodRequired % N ==  0 ){
           return TotalFoodRequired / N ;
       }else{
            return (TotalFoodRequired / N ) + 1 ;
       }
    }

    Q4)-: Choclate Distribution Problem --->>>

        long long findMinDiff(vector<long long> a, long long n, long long m){
    
    
        sort(a.begin() , a.end());
        long long start = 0 ;
        long long  end = m-1;
        
        long long minDiff = INT_MAX ;
        
        while( end < n){
            long long diff = a[end] - a[start] ;
            minDiff = min( diff , minDiff);
            
            start++ ;
            end++ ;
        }
        
        return minDiff ;
    
    } 

*/