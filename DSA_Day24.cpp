/*
Q1)-: Maximize Sum After K negotiation ---->>>
    
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort( a , a+ n);
        long long int sum = 0 ;
        long long int minEle = INT_MAX ;
        for( int i = 0 ; i< n ; i++){
            if(a[i] < 0 && k > 0){
                a[i] = -1*a[i];
                k-- ;
            }
            sum = sum + a[i];
            minEle = min( a[i] , minEle);
            // cout<<sum<<" "<<minEle<<endl;
        }
        
        if( k > 0){
            if(k%2 == 0){
               return sum ; 
            }else{
              sum = sum - (2*minEle) ; 
              return sum ;
            }
        }else{
            return sum ;
        }
    }


    Q2)-:  Maximize the Sum of a[i]*i array --->>

         int Maximize(int a[],int n)
    
    {
        // Complete the function
        sort(a,a+n);
        long long given = 1000000007; 
        long long  sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum=(sum+ (long) a[i]*i)%given;
        }
        sum =  sum%given;
        return (int) sum ;
    }

    Q3)-: Maximize the Sum of Absolute Array --->>> 

     int maxSum( int arr[] ,  int n){

        sort( arr , arr+n);
        int s = 0 , e = n-1 ;
        int sum = 0 ;
        while( s > e){
          sum = sum + ( arr[e] - arr[s]);
          e-- ;
          s++ ;
        }

        return sum ;
     }

     Q4) -: Minimum Sum of abs difference of ele of Two Arrays ---->>>>

    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        sort( A.begin() , A.end());
        sort(B.begin() , B.end());
        long long sum = 0 ;
        for( int i = N-1; i>=0 ; i--){
            sum = sum + abs((long long)( A[i] - B[i]));
        }
        return sum ;
    }


*/