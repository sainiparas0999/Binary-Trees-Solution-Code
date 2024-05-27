/*
Q1)-: Inversion Count --->>>>


    BruteForce Code --->>>>

      long long int inversionCount(long long arr[], long long N)
    {
       long long int count = 0 ;
       
       long long i = 1 ;
       
       while( i < N ){
           
           long long j = i ;
           
           while( j>0 &&  arr[j] < arr[j-1]){
               swap( arr[j] , arr[j-1]);
               count++ ;
               j-- ;
           }
           
           i++ ;
       }
       
       return count ;
        
    }


    Optitmized Code --->>>>

    void merge(long long arr[],long long s,long long m,long long e,long long &cnt)
    {
        long long *temp = new long long[e-s+1];
        long long i=s; // first part
        long long j=m+1; //second part
        long long k=0; //for temp indexing
        
        while(i<=m && j<=e)
        {
            if(arr[i] > arr[j])
            {
                cnt+=m-i+1;
                temp[k++]=arr[j++];
            }
            else
                temp[k++]=arr[i++];
        }
        while(i<=m)
            temp[k++]=arr[i++];
        while(j<=e)
            temp[k++]=arr[j++];    
        
        k=0;
        for(int i=s;i<=e;)
        {
            arr[i++]=temp[k++];
        }
        delete [] temp;
    }
    void mergesort(long long arr[],long long s,long long e,long long &cnt)
    {
        if(s>=e)    return ;
        long long m= s+(e-s)/2;
        mergesort(arr,s,m,cnt);
        mergesort(arr,m+1,e,cnt);
        merge(arr,s,m,e,cnt);
    }
    
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long cnt=0;
        mergesort(arr,0,n-1,cnt);
        return cnt;
    }


Q2)--: Best time to Buy and sell the stock --->>>>>

         int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minPrice = prices[0] ;
        for( int i = 1 ; i<prices.size()  ; i++){
  
          if( prices[i] < minPrice){
            minPrice = prices[i];
          }else{
            maxP = max( maxP , prices[i] - minPrice);
          }
        }

        return maxP ;
    }

    Q3)-: Find the number of pairs having the sum equal to k --->>>>

         int getPairsCount(int arr[], int n, int k) {
    
                unordered_map<int , int> mp ;
        int Count = 0 ;
         for( int i =0 ; i< n ; i++){
             
             int element = k - arr[i];
             if(mp[element] > 0){
                 Count = Count + mp[element] ;
             }
             mp[arr[i]]++ ;
         }
          
          return Count ;
    }
    }

*/