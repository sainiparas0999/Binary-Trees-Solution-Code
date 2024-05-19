/*
Q1)-: Maximize the Sum of consecutive difference in the circular array-->>

    long long int maxSum(int arr[], int n)
{
    sort(arr , arr+n);
    
    int s = 0 , e = n-1 ;
    long long int sum = 0 ;
    while( s < e){
       
       sum = sum + abs((long long int) arr[s] - arr[e]);
       s++;
       if( s == e){
           s = 0 ;
           sum = sum + abs((long long int) arr[s] -arr[e]);
           break ;
       }
       sum = sum + abs((long long int) arr[s] -arr[e]);
       e-- ;
    }
    
           if( s == e){
           s = 0 ;
           sum = sum + abs((long long int) arr[s] -arr[e]);
       }
    
    return sum ;
}

 Q2)-: Smallest Subset with sum greater than all elements ---->>>> 
  
       int minSubset(vector<int> &Arr,int N){
         int count = 0 ;
         long long sum = 0 ;
         long long totalSum = 0 ;
         for( int i = 0 ; i<N ; i++){
             totalSum += (long long )Arr[i] ;
         }
         sort( Arr.begin() , Arr.end());
        //  cout<<totalSum<<endl;
        for( int i = N-1 ; i>= 0 ; i--){
            
          if( sum > totalSum - sum){
              return count ;
          }
        //   cout<<sum<<endl;
          sum += (long long )Arr[i] ;
          count++ ;
        }
        
        return 1 ;
    }

    Q3)-: Find the maximum possible Equal sum of three Arrays ---->>>
    
        int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
       
       long long sum1 = 0 , sum2 = 0, sum3 = 0 ;
       
       for( auto i : S1){
           sum1 +=  (long long) i ;
       }
       for(auto i : S2){
           sum2 += (long long)i ;
       }
       for(auto i : S3){
           sum3 += (long long)i ;
       }
       
       int i = 0 , j = 0 , k = 0 ;
       
       while( i < N1 && j < N2 && k < N3){
           
          long long minSum = min( min ( sum1 , sum2) , sum3);
           
           if( sum1 == minSum && sum2 == minSum && sum3 == minSum){
               return minSum ;
           }
           
           if( sum1 > minSum){
               sum1 = sum1 - (long long)S1[i];
               i++ ;
           }
           
           if( sum1 == minSum && sum2 == minSum && sum3 == minSum){
               return minSum ;
           }
           
           if( sum2 > minSum){
               sum2 = sum2 - (long long)S2[j] ;
               j++ ;
           }
           
           if( sum1 == minSum && sum2 == minSum && sum3 == minSum){
               return minSum ;
           }
           
           if( sum3 > minSum){
               sum3 = sum3 - (long long)S3[k];
               k++ ;
           }
           
        if( sum1 == minSum && sum2 == minSum && sum3 == minSum){
               return minSum ;
           }
       }
       
       return 0 ;
    }

    Q4)-: Smallest NUmber with digit sums is equal to S ;

         string smallestNumber(int S, int D){
        
          string s="";
    
     if(9*D<S)return "-1";//when not posssible
         
       while(S>9 && D!=0){ //starting from last _ _ _ 9 9
            s='9'+s;
            S=S-9; 
            D--;
       }
       
       if(D==1) s= to_string(S) + s; 
 
       else{
          s= to_string(S-1) + s;  
          D--;
          while(D!=1){
              s='0'+s;
              D--;
          }
        s='1' + s;
       }  
    return s;
    }
*/