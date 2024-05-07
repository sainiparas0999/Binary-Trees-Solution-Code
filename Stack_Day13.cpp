/*
Q1)-: Reverse the string with the use of stack -->>>
   char* reverse(char *S, int len)
{
     stack<char> s  ;
     
     for( int i = 0 ; i<len ; i++){
         s.push(S[i]);
     }
     
     for(int i = 0 ; i<len ; i++){
         S[i] = s.top();
         s.pop();
     }
     
     return S ;
}

 Q2)-: Special stack 
     

        stack<int> poped ;
   int element = s.top() ;
   while( a > element){
       poped.push(element);
       s.pop();
       element = s.top();
   }
   
    s.push(a);
    
   for(int i = 0 ; i<poped.size() ; i++){
       s.push(poped.top());
       poped.pop();
   }

}

bool isFull(stack<int>& s,int n){
    if(s.size() == n)
   return true ;
   else
    return false ;
}

bool isEmpty(stack<int>& s){
	if(s.top() == -1)
	return true ;
	else
	return false ;
}

int pop(stack<int>& s){
   return -1 ;
}

int getMin(stack<int>& s){
	return s.top();
}

 Q3)-: Next greater element in the array --->>>>

        //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){

          stack<long long> s ;
          
          for( int i = n-1 ; i>=0 ; i--){
              
              if( i == n-1){
                  s.push(arr[i]);
                  arr[i] = -1 ;
              }else{
                  
                  if(arr[i] < s.top()){
                      long long temp = s.top();
                      s.push(arr[i]);
                      arr[i] = temp ;
                  }else{
                      
                      while( !s.empty() && arr[i] >= s.top()){
                          s.pop();
                      }
                      
                      if(s.empty()){
                          s.push(arr[i]);
                          arr[i] = -1 ;
                      }else{
                          long long temp = s.top();
                          s.push(arr[i]);
                          arr[i] = temp ;
                      }
                  }
              }
          }
          
          return arr ;
        
    }
Q4)-:   The celebrity Problem --->>>>

        int celebrity(vector<vector<int> >& M, int n) 
    {
       
       stack<int> s ;
       
       for( int i = 0 ; i<n ; i++){
           s.push(i);
       }
       
       while (s.size() > 1){
           
          int a = s.top() ;
           s.pop() ;
          int b = s.top() ;
          s.pop() ;
          
          if(M[a][b] == 1){
              s.push(b);
          }else{
              s.push(a);
          }
       }
       
       int ans = s.top() ;
        bool celeb = true ;
       for( int i = 0 ; i<n ; i++){
           if(M[i][ans] == 0 && i != ans)
           celeb = false ;
       }
       
       for( int i = 0 ; i<n ; i++){
           if(M[ans][i] == 1)
              celeb = false ;
       }
       
       if(celeb == true){
           return ans ;
       }else{
           return -1 ;
       }
       
    }
*/