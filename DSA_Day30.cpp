/*
Q1)-: Minimize the height by changing the tower by K .


sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];
        int mini , maxi;
        
        for(int i=1; i<n; i++){
            if(arr[i]-k<0){
                continue;
            }
            maxi = max(arr[i-1]+k,arr[n-1]-k);
            mini = min(arr[0]+k,arr[i]-k);
            ans = min(ans,maxi-mini);
        }
        return ans;


Q2)-: Find the Duplicate in the the Array of N+1 .

     int findDuplicate(vector<int>& nums) {
        int sum1 = 0 ;
        int sum2 = 0 ;
        unordered_set<int> hs ;
        for( int i =0 ; i< nums.size() ; i++){
            sum1 += nums[i];
            hs.insert(nums[i]);
        }

        for( int i = 0 ; i<hs.size() ; i++){
            sum2+= hs[i];
        }

        return sum1 - sum2 ;


    }
};

Q3) -: Merge two Sorted array without using extra space -->>>

    int i = 0 , j = 0 ;

    while( i< arr1.size() && j < arr2.size()){

        if( arr1[i] < )
    }



    Q4)-: Merge Intervals ---->>>

         vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin() , intervals.end());
        ans.push_back(intervals[0]);
        for( int i = 1 ; i<intervals.size(); i++){
           if(ans.back()[1] < intervals[i][0]){
            ans.push_back(intervals[i]);
           }else{
              ans.back()[0] = min(ans.back()[0] , intervals[i][0]);
              ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
           }
        }
        return ans ;
    }

    
*/