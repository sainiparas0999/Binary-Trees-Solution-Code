/*
 Q1)-: Choose and Swap to give Lexiographically small String ---->>>>>

      string chooseandswap(string a){
        
        vector<int>charArr(26 , -1);
       
       for( int i = 0 ; i<a.length() ; i++){
          int pos = a[i]-'a' ;
          if(charArr[pos] == -1){
          charArr[pos] = i ;
          }
       }
       
       int i , j ;
       
       for( i = 0 ; i<a.size() ; i++){  // this loop checks for every element 
           bool flag = false ;
           
           for( j = 0 ; j<a[i]-'a' ; j++){
               
               if(charArr[a[i]-'a'] < charArr[j]){
               flag = true ;
                break ;
               }
               
           }
           
           if(flag) break ;
       }
       
      if( i < a.size()){
                     char ch1 = a[i];
           char ch2 = char( j + 'a');
 
           for(  i = 0 ; i<a.size() ; i++){
               if( a[i] == ch1){
                   a[i] = ch2 ;
               }else if( a[i] == ch2){
                   a[i] = ch1 ;
               }
           }
      }
       
       
       return a ;
    }

    Q2)-: Buy Maximum No. of Stocks if i stocks can be bought on ith day ----->>>>

         int buyMaximumProducts(int n, int k, int price[]){
        
       vector<pair<int , int> > v ;
       
       for( int i = 0 ; i< n ; i++){
           v.push_back({price[i] , i+1});
       }
       
       sort( v.begin() , v.end());
       int maxStocks = 0 ;
       int i = 0 ;
       while( k > 0 && i<n){
          
          int stockAvail = v[i].second ;
          int stockPrice = v[i].first ;
          
          while( stockAvail > 0 && k >= stockPrice){
              maxStocks++ ;
              stockAvail -- ;
              k = k - stockPrice ;
          }
          
          i++ ;
          
       }
       return maxStocks ;
        
    }

    Q3)-: Cost of N Ropes ---->>>>

         static bool cmp( long long a , long long b){
        return a < b ;
    }
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long , vector<long long> , greater<long long> > pq ;
        
        for( long long i = 0 ; i<n ; i++){
            pq.push(arr[i]);
        }
        long long cost = 0 ;
        
        while(pq.size() > 1){
            long long first = pq.top();
            pq.pop() ;
            long long second = pq.top();
            pq.pop() ;
            
            long long sum = first + second ;
            
           cost += sum ;
            pq.push(sum);
        }
        
        return cost ;
    }

    Q4)-: Reverse the word in a String --->>> 
     
         string reverseWords(string S) 
    { 
        string ans="";
        string temp ="";
        for( int i =S.length()-1 ; i>=0 ; i--){
            if(S[i] == '.'){
                reverse(temp.begin() , temp.end());
                ans = ans + temp +".";
                temp.clear();
            }else{
                temp = temp + S[i] ;
            }
        }
        reverse(temp.begin() , temp.end());
        ans = ans + temp ;
        return ans ;
    } 
*/