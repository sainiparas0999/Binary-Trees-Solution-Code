/*
Q1)-: First negative integer in every window of size k
 
  Brute Force --:
   int checkneg( deque<int>dq){
     while(!dq.empty()){
       if(dq.front() < 0){
           return dq.front();
       }
       dq.pop_front();
     }
     return 0 ;
 }
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        deque<long long int> dq ;
        vector<long long> ans ;
       
       for( int i = 0 ; i<k ; i++){
           if(A[i] < 0){
               dq.push_back(A[i]);
           }
       } 
       if(dq.size() > 0){
           ans.push_back(dq.front());
       }else{
           ans.push_back(0);
       }
       
       for( int i = k ; i<N ; i++){
           
           if(!dq.empty() && i - dq.front() >= k){
               dq.pop_front();
           }
           if(A[i] < 0){
               dq.push_back(A[i]);
           }
           
             if(dq.size() > 0){
           ans.push_back(dq.front());
       }else{
           ans.push_back(0);
       }
       }
       return ans
 }

   Optimized solution-: 

    vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
                                                 
        deque<long long int> dq ;
        vector<long long> ans ;
       
       for( int i = 0 ; i<k ; i++){
           if(A[i] < 0){
               dq.push_back(i);
           }
       } 
       if(dq.size() > 0){
           ans.push_back(A[dq.front()]);
       }else{
           ans.push_back(0);
       }
       
       for( int i = k ; i<N ; i++){
           
           if(!dq.empty() && i - dq.front() >= k){
               dq.pop_front();
           }
           if(A[i] < 0){
               dq.push_back(i);
           }
           
       if(dq.size() > 0){
           ans.push_back(A[dq.front()]);
       }else{
           ans.push_back(0);
       }
       }
       return ans ;
 }


 Q2)-: first Non-repeating character in a stream --->>>

     	   void removeDeque( deque<char>& dq , char ch){
	       // base case
	       if(dq.empty()){
	           return ;
	       }
	       if(dq.front() == ch){
	           dq.pop_front();
	           return ;
	       }
	       char ans = dq.front();
	       dq.pop_front();
	       removeDeque(dq , ch);
	       dq.push_front(ans);
	   }
		string FirstNonRepeating(string A){
		    
		    set<char>s;
		    deque<char>dq ;
		    for( int i = 0 ; i<A.length() ; i++){
		        char ch = A[i];
		        if(s.find(ch) == s.end()){
		          dq.push_back(ch);  
		        }else{
		            removeDeque(dq, ch);
		        }
		        s.insert(ch);
		        if(!dq.empty()){
		            A[i] = dq.front();
		        }else{
		            A[i] = '#';
		        }
		    }
		    return A ;
		}

        Q3)-: Help ClassMate Problem 

            vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> s ;
        s.push(-1);
        for( int i = n-1 ; i>=0 ; i--){
            
            if(!s.empty() && s.top() != -1){
                
                while(s.top() >= arr[i]){
                    s.pop();
                }
            }
           int ans = arr[i];
           arr[i] = s.top();
           s.push(ans);
        }
        
        return arr ;
    } 

    
*/