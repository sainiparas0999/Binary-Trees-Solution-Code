/*
  Implementation of stack with the help of array ---->>>>>>

   class stack{
     int size ;
     int top ;
     int *arr ;

     stack(int size){
        this->size = size ;
        top = -1 ;
        arr = new int[size];
     }

     void push( int element){

        if(size - top > 1){
            top++ ;
            arr[top] = element ;
        }else{
            cout<<"The stack is Overflow"<<endl;
        }
     }

     void pop(){
      
      if( top > 0){
        top-- ;
      }else{
        cout<< " stack is empty" ;
      }
     }

     void peek(){
        if(top > 0){
            return arr[top];
        }else{
            cout<<"stack is empty";
        }
     }
   }



   Q2)-: Implement two stacks in one array ---->>>>

     class twoStacks
{
    public:
   
    int top1 ;
    int top2 ;
    int size ;
    int *arr ;
    
    
    twoStacks()
    {
        size = 1000 ;
        top1 = -1 ;
        top2 = size ;
        arr = new int[size];
    }
 
    //Function to push an integer into the stack1.
    void push1(int element)
    {
        if(top2 - top1 > 1){
            top1++ ;
            arr[top1] = element ;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int element)
    {
       if(top2 - top1 > 1){
           top2-- ;
           arr[top2] = element;
       }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
       if( top1 >= 0){
          return arr[top1--];
       }else{
           return -1 ;
       }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2 < size){
           return arr[top2++];
       }else{
           return -1 ;
       }
    }
};

  Q3)-: Delete the middle element of the stack ---->>>

    void deleteMiddle( stack<int> s , int count){

        // base case 
        if( count == size/2){
            s.pop();
            return ;
        }

        int ans = s.top();
        deleteMiddle( s , count+1);
        s.push(ans);
    }



    Q4)-: K stacks in an array ---->>>>>

     class nStack{

        int *arr ;
        int * top ;
        int * next ;

        int n , s ;

        int freeSpot ;


        nstack( int n , int s){

            arr = new int[s];
            top = new int[n];
            next = new int[s];

            for( int i = 0 ; i< n ; i++){
                top[i] = -1 ;                // all top are at -1 bcz no stack have element in it ;
            }

            for ( int i = 0 ; i < s-1 ; i++){
                next[i] = i+1 ;               // all indexes point to the next free index ;
            }
            
            next[s-1] = -1 ;
            freespot = 0 ;                // every time on a free index;
        }

        bool push( int x , int m){

            if(freespot == -1){
                return false ;         // if no freespot is left ;
            }
 
            int index = freespot ;        // using the freespot ;
            freespot = next[index];       // upgrading the freespot to new freespot ;

            arr[index] = x ;          -- updating the all three array ;
            next[index] = top[m-1];   -- next stores the last top index ..which used while 
            top[m-1] = index ;        -- top stores the current top index of stack 
        }

        int pop( int m){
            if( top[m-1] == -1){
                return -1 ;
            }

            index = top[m-1];
            top[m-1] = next[index];

            next[index] = freespot ;

            freespot = index ;

            return arr[index];
        }
     }


     Q5)-: Valid Parenthesis or Not ---->>>>>>

    bool ispar(string x)
    {
        stack<char> s ;
        for( int  i = 0 ; i<x.length() ; i++){
           
           if(x[i] == '(' || x[i] == '{' || x[i] == '['){
               s.push(x[i]);
           }else if(  (s.empty()) && (x[i] == ')' || x[i] == '}' || x[i] == ']')){
               return false ;
           }  else if( x[i] == ')' && s.top() == '('){
               s.pop();
            }else if( x[i] == '}' && s.top() == '{'){
               s.pop();
           }else if( x[i] == ']' && s.top() == '['){
               s.pop();
           }else{
               s.push(x[i]);
           }
        }
        if(s.empty()){
            return true ;
        }else{
            return false ;
        }
    }

*/