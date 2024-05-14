/*
Q1)-: N meetings in One room --->>

       static bool cmp( pair<int , int>a , pair<int,int>b){
        return a.second < b.second ;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector< pair<int , int>> meeting ;
        for( int i = 0 ; i<n ; i++){
            pair<int , int> p = make_pair(start[i] , end[i]);
            meeting.push_back(p);
        }
        
        sort( meeting.begin() , meeting.end() , cmp);
        int count = 1 ;
        
        int ending = meeting[0].second;
        
        for( int i = 1 ; i<n ; i++){
          
           int starting = meeting[i].first;
           if(starting > ending){
               ending = meeting[i].second;
               count++ ;
           }
        }
        return count ;
    }


Q2)-:vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
    
        vector< pair< pair<int,int> , int>>v ;
       
         for( int i = 0 ; i<N ; i++){
           v.push_back({{F[i] ,S[i]} , i+1});
         }
         
         sort(v.begin() , v.end());
         vector<int> ans ;
         ans.push_back(v[0].second);
         int end = v[0].first.first ;
         
         for( int i = 1 ; i<N ; i++){
             int start = v[i].first.second ;
             
             if(start > end){
                 ans.push_back(v[i].second);
                 end = v[i].first.first ;
             }
         }
         
         sort( ans.begin() , ans.end());
         return ans ;
    }

  Q3)-: job Sequencing Problem --->>>>

        static bool cmp( Job a , Job b){
        return a.profit > b.profit ;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        
        int maxTime = 0 ;
        
        for( int i = 0 ; i<n ; i++){
            maxTime = max( maxTime , arr[i].dead );
        }
        
        vector<int> schedule(maxTime+1 , -1);
        
        sort( arr , arr+n , cmp);
        vector<int> ans;
        int count = 0;
        int maxprofit = 0;
        for( int i = 0 ; i<n ; i++){
            
            int id = arr[i].id ;
            int dead = arr[i].dead ;
            int profit = arr[i].profit ;
            
            while( dead > 0){
                if(schedule[dead-1] == -1){
                    schedule[dead-1] = id ;
                    count++ ;
                    maxprofit = profit + maxprofit ;
                    break ;
                }
                dead-- ;
            } 
        }
        ans.push_back(count);
        ans.push_back( maxprofit);
        return ans ;
        
    }

    Q4)-: Shopping in Candy Store----->>>>>

         vector<int> candyStore(int candies[], int N, int k)
    {
        sort( candies , candies+N );
        int minPrice = 0;
        int maxPrice = 0;
        int minCount = 0, maxCount = 0 ;
        for( int i = 0 ; i< N ; i++){
            minPrice+=candies[i];
            minCount+= k + 1 ;
            if(minCount >= N)
            break ;
        }
        
        reverse(candies , candies + N);
        
        for( int i = 0 ; i<N ; i++){
            maxPrice+=candies[i];
            maxCount+=  k + 1 ;
            if(maxCount >= N)
            break ;
        }
        
        vector<int>ans ;
        ans.push_back(minPrice);
        ans.push_back(maxPrice);
        
        return ans ;
    }

*/