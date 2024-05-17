/*
   Today marks Day23 of my journey tackling DSA problems! Check out my progress on my GitHub page: https://lnkd.in/e6vnR3xZ
. Feel free to leave any feedback. Let's keep learning and growing together.

Q1)-: Maximum Train for which Stoppage can be provided ---->>>>
      
      int maximumTrain( int arr[][] , int n , int m){

          vector<int> v ;

          for( int i = 0 ; i<n ; i++){
            v.push_back(-1);
          }

          int count = 0 ;
 
         vector< pair< pair<int,int> , int>> trains ;

         for( int i = 0 ; i<m ; i++){
            trains.push_back( { { arr[i][2] , arr[i][1]} , arr[i][3]});
         }

         sort(trains.begin() , trains.end());

        for(int i = 0 ; i<m ; i++){

          int goTime = trains[i].first.first ;
          int inTime = trains[i].first.second ;
          int platform = trains[i].second ;

          if(v[platfrom - 1] < inTime){
            count++ ;
            v[platform -1] = goTime ;
          }
        }

        return count ;

      }


   Q2)-: Minimum No. of Platforms required to Stops all Trains -->>>

          int findPlatform(int arr[], int dep[], int n)
    {
    	vector< pair<int,int> > trains ;
    	
    	for( int i= 0 ;i< n ; i++){
    	    trains.push_back({arr[i] , dep[i]});
    	}
    	
    	sort( trains.begin() , trains.end());
    	vector<int>platform(n ,-1);
    	
    	for( int i = 0 ; i<n ; i++){
    	    for( int j = 0 ; i<n; j++){
    	        if(platform[j] < trains[i].first){
    	            platform[j] = trains[i].second ;
    	            break;
    	        }
    	    }
    	}
    	
    	int count = 0 ;
    	for( int i = 0 ; i<n ; i++){
    	    if(platform[i] != -1)
    	    count++ ;
    	}
    	
    	return count ;
    	
    }


    Q3)-: Minimum Cost to cut a Board into Square Pieces ----->>>>

          sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int v=1,h=1;
        
        int i=0,j=0,cost = 0;
        while (i<X.size() && j<Y.size()) {
            if (X[i] >= Y[j]) {
                cost += (X[i]*h);
                v++;
                i++;
            } else {
                cost += (Y[j]*v);
                h++;
                j++;
            }
        }
        
        while (i<X.size()) {
            cost += (X[i]*h);
            v++;
            i++;
        }
        
        while (j<Y.size()) {
            cost += (Y[j]*v);
            h++;
            j++;
        }
        
        return cost;
    }

    
   Q4)-: Maximum product Subset of Array --->>>

  long long int findMaxProduct(vector<int>&a, int n){


        if(n==1) return a[0];
        
        long int mod = 1e9+7; 
        long long int maxNeg = INT_MIN;
        long long int result = 1;
        int zero = 0, neg = 0;
        
        for(int i=0; i<n; i++){
            if( a[i] == 0 ) {
                zero++;
                continue;
            }
            else if( a[i] < 0 ){
                neg++;
                maxNeg = max( maxNeg, (long long int)a[i] );
            }
            
            result = ( result*a[i] ) % mod;
        }
        
        if(zero == n || (zero == n-1 && neg == 1) )  return 0;
        
        if( neg%2 != 0 ){
            result = ( result/maxNeg )%mod;
        }
        
        return result;
    }

*/