/*
 Q1)-: Implement a Queue in the array --->>> 
  
  class Queue{
   private:
   int data ;
   int front ;
   int rear ;
   int size ;
   int *arr ;
   public:
    
    Queue( int size){
      arr = new int[size];
      int front = 0 ;
      int rear = 0 ;
    }

    void push( int data){
     
     if( rear >= size-1){
        cout<<"queue is full "<<endl;
        return ;
     }

     arr[rear++] = data ;
    }

    int pop(){

        if( rear == front){
         cout<<" queue is empty"<<endl;
         return -1 ;
        }else{
          
          int ans = arr[front++];

          if( front == rear){
            front = 0 ;
            rear =  0 ;
          }
          return ans ;
        }   
    }
  }

  Q2)-: Implelment the Circular Queue ->>>>
   
     class CircularQueue{
        private: 
        int * arr ;
        int front ;
        int rear ;
        int size  ;

        public:

        CircularQueue( int size ){
          arr = new int[size];
          front = rear = -1 ;
          this->size = size ;
        }

        void push( int data){
          if( (front == 0 && rear == size) || ( rear == front -1 )){
            cout<<" queue is full"<<endl;
            return ;
          }
          
           if( front == -1){
            rear = front = 0 ;
          }else if( rear == size -1 && front != 0){
            rear = 0 ;
          }else{
            rear++ ;
          }
          arr[rear] = data ;
        }

        int pop(){
            if( front == -1){
                cout<<" your stack is empty"<< endl;
                return -1;
            }

            int ans = arr[front];
            arr[front] = -1 ;

            if(front == rear){
                front = rear = -1 ;
            }else if( front == size -1){
                front = 0 ;
            }else{
                front++ ;
            }
           return ans ;
        }
     }


     Q3)-: Doubly Ended Queue ----->>>>

      class deque{
        private:

        int size ;
        int *arr ;
        int front ;
        int rear ;

        public:

         deque( int size){
            this->size = size ;
            arr = new int[size];
            rear = front = -1 ;
         }

         bool pushfront( int data){

            if(( front == 0 && rear == size-1) ||( rear == front-1)){
                cout<<"deque is OverFlow"<<endl;
                return false ;
            }
            if( front = -1){
                front = rear = 0 ;
            }
            else if(front == 0){
                front = size-1 ;
            }else {
                front-- ;
            }

            arr[front] = data ;
            return true ;
         }
      }

      bool pushback( int data){
        if(( rear == size-1 && front == 0) || ( front == rear + 1)){
            return false ;
        }
        if( front = -1){
            front = rear = 0 ;
        }
        else if(rear == size -1){
            rear = 0 ;
        }else{
            rear++ ;
        }
        arr[rear] = data ;
        return true ;
      }

    int popfront(){
        if(front == -1){
            return -1 ;
        }
      
      int ans = arr[front];
      arr[front] == -1 ;
     
      if( front == rear){
        front = rear = -1 ;
      }else if( front == size -1){
        front = 0 ;
      }else{
        front++ ;
      }
      return ans ;
      }


      int popback(){
        if(front == -1){
            return -1 ;
        }
        int ans = arr[rear];
        ans[rear] = -1 ;

        if( rear == front){
            rear = front = -1 ;
        }else if( rear == 0){
            rear = size-1 ;
        }else{
            rear -- ;
        }

        return ans ;
      }
    };


    Q4)-: Implement N queues in a single array ---->>>

      class nQueue{
        private:
         int size ;
         int *arr ;
         int *rear ;
         int *front;
         int *next ;
         int N ;
         int freeSpot ;
         public:

         nQueue( int size , int N){
            this->size = size ;
            this->N = N ;
            arr = new int[size];
            next = new int[size];
            front = new int[N];
            rear = new int[N];

            for( int i = 0 ; i<size-1 ; i++){
                next[i] = i+1 ;
            }

            next[size-1] = -1 ;

            for( int i = 0 ; i<N ; i++){
                front[i] = -1 ;
                rear[i] = -1 ;
            }

            int freeSpot = 0 ;
         }

         void push( int data , int m){
            if(freeSpot == -1){
                cout<<Queue is full<<endl;
                return ;
            }

            int index = freeSpot ;
            freeSpot = next[index];

            arr[index] = data ;
            if( front[m-1] == -1 ){
                front[m-1] = index;
            }else{
                next[rear[m-1]] = index ;
            }
            rear[m-1] = index ;
            next[index] = -1 ;
         }

         int pop(int m){
            
            if( front[m-1] == -1){
                return -1 ;
            }

           int index = front[m-1];
           front[m-1] = next[index]; // find the front and update the front by one ago

           next[index] = freeSpot ;
           freeSpot = index ;
           return arr[index];
         }
      }

     Q5)-:  Reverse a Queue with the help of Recurssion

       a)-:    void Reverse( queue<int> &q){
         // base case 
         if( q.empty()){
             return ;
         }
         
         int ans = q.front();
         q.pop();
         Reverse(q);
         q.push(ans);
     }
    queue<int> rev(queue<int> q)
    {
        Reverse(q);
        return q;
    }

b)-:     queue<int> rev(queue<int> q)
    {
        stack<int>s ;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        
        while( !s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        return q ;
    }


*/