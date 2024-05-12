/*
Q1)-: Reverse first K element of the Queue--->>.
 
  a)-: By using vector 
    queue<int> modifyQueue(queue<int> q, int k) {
    vector<int> v ;
       while(!q.empty()){
         v.push_back(q.front());
         q.pop();
       } 
       
       reverse(v.begin() , v.begin()+k);
       
       for(auto i : v){
           q.push(i);
       }
       return q ;
    }


Q2)-: InterLoop the two halfs of the Queue--->>>>
 
      vector<int> rearrangeQueue(queue<int> &q){
       vector<int>v1 ;
       int mid = q.size()/2 ;
       int i = 0 ;
       while( i<mid){
           v1.push_back(q.front());
           q.pop();
           i++ ;
       }
       
       vector<int> ans ;
       
       for( int i = 0 ; i<mid ; i++){
           ans.push_back(v1[i]);
           ans.push_back(q.front());
           q.pop();
       }
       
       return ans ;
    }

    Q3)-: find the first point of the Circular tour that visits all the petrol pump --->>>

       int point = -1 ;
       int extra = 0 ;
       vector<int> x ;
       for( int i = 0 ; i<n ; i++){
           int petrol = p[i].petrol ;
           int distance = p[i].distance ;
           
           if( petrol >= distance ){
               if(point == -1){
                   point = i ;
                   x.push_back(extra);
                   extra = 0 ;
               }
             
              extra =  extra + (petrol - distance);
           }else{
               if( (distance - petrol) > extra ){
                   point = -1 ;
               }
               extra = extra - (distance - petrol) ;
           }
       }
       x.push_back(extra);
       int ans = 0 ;
       for(auto i : x){
          ans = ans +i ; 
       }
       if( ans >=0){
           return point ;
       }else{
           return -1 ;
       }
    }


    Q4)-: Sum of maximum And minimum of subArray of length K ---->>>

     int SumOfKsubArray(int arr[], int N, int k)
   {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        int length = 0;
        for (int j = i; j < N; j++) {
            length++;

            // When there is subarray of size k
            if (length == k) {
                // To store maximum and minimum element
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (int m = i; m <= j; m++) {
                    // Find maximum and minimum element
                    maxi = max(maxi, arr[m]);
                    mini = min(mini, arr[m]);
                }

                sum += maxi + mini;
                break ;
            }
        }
    }
    return sum;
} 

 Note-: we can also use deque instead of making a window ;

   
*/