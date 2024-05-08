/*'
 Q1)-: Implement methods to push the element in the bottom or sorted wise in the stack--::
  
  -->> Implement a method to push element into the bottom of the stack 

    void pushBottom( stack<int> & s , int n){
    // base case 
    if(s.empty()){
        s.push(n);
        return ;
    }
     
     int ele = s.top() ;
     s.pop();
     pushBottom( s, n);
     s.push(ele);
   }

   -->> Implement a method to push sorted wise element into the stack 

    void pushSorted( stack<int> &s , int n){
        // base case 
        if(s.empty()){
            s.push(n);
            return ;
        }
        
        int ele= s.top();
        
        if( n < ele){
            s.push(n);
            return ;
        }

        s.pop();
        pushSorted( s , n);
        s.push(ele);
    }


   Q)2 -: Reverse a stack in O(1) space complexity --->>

    void pushBottom( stack<int>&s , int n){
         // base case
         if(s.empty()){
             s.push(n);
             return ;
         }
         
         int ele = s.top();
          s.pop();
          pushBottom( s , n);
          s.push(ele);
     }
    void Reverse(stack<int> &s){
       // base case 
       if(s.empty()){
           return ;
       }
       
       int ele = s.top();
       s.pop();
       Reverse(s);
       pushBottom( s , ele);
    }

  
  Q3)-: Sort a Stack with the help of ---->>>>

     void pushSorted(stack<int> &s , int n){
     // base case
     if(s.empty()){
         s.push(n);
         return ;
     }
     
     int ele = s.top();
     if(n > ele){
         s.push(n);
         return ;
     }
     
     s.pop();
     pushSorted( s , n);
     s.push(ele);
 }
void SortedStack :: sort()
{
  vector<int> v ;
  while(!s.empty()){
      v.push_back(s.top());
      s.pop();
  }

  for( int i = 0 ; i<v.size() ; i++){
     pushSorted( s , v[i]);
  }


  
   
   */