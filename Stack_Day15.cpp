/*
  Q1)-: Valid Substrings of Brackets only .

       int findMaxLen(string s) {
        
        int n =s.length();
        int maxAns = 0 ;
        int l = 0 , r= 0 ;
        for( int i = 0 ; i<n ; i++){
           if(s[i] == '(') l++ ;
           else r++ ;
           
           if( r == l) maxAns = max( 2 * l , maxAns);
           else if( r > l) r = l = 0 ;
        }
        
        l = r = 0 ;
        
        for( int i = n-1 ; i>=0 ; i--){
           if(s[i] == '(') l++ ;
           else r++ ;
           
           if( r == l) maxAns = max( 2 * l , maxAns);
           else if(l>r) r = l = 0 ;
        }
        
        return maxAns ;
        
    }


    Q2)-: Expression Contain Redundant Bracket or Not --:

     bool checkRedundancy(string& str){
 
      stack<char>s ;
      bool ans = true ;
       for( int i = 0 ; i<str.length() ; i++){

        if(str[i] == '(' || str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-'){
            s.push(str[i]);
        }else{
            ans = true ;   
           while( s.top() != '(' && !s.empty()){
            if(s.top() == "*" || s.top() == "/" || s.top() == "+" || s.top() == "-"){
                ans = flase ;
            }
           }

           if( ans == true)
            return true ;
        }

       }

       return true ;

     }

     Q3)-: Implement a stack with the help of two Queue --::

void QueueStack :: push(int x)
{
     while(!q1.empty()){
         q2.push(q1.front());
         q1.pop();
     }
     
     q1.push(x);
     
     while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
     }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
   if(q1.empty()) return -1 ;
   
   else{
   int ans = q1.front();
   q1.pop();
   return ans ;
   }
}

 Q4)-: Implement a queue with the help of two stack --:: 
   
   void StackQueue :: push(int x)
{
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
   if(s1.empty()) return -1 ;
   
   else{
       int ans = s1.top();
       s1.pop();
       return ans ;
   }
}

Q5)-: check if the two array are stack permutation are Not -:
   
       int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack<int> s ;
        int k = 0 ;
        for( int i = 0 ; i<N ; i++){
            s.push(A[i]);
            while( !s.empty() && s.top() == B[k]){
                s.pop();
                k++ ;
            }
        }
        
        if(s.empty()){
            return 1 ;
        }else{
            return 0 ;
        }
    }
*/