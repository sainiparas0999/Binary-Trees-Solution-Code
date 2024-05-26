/*
Q1)-: First and last occurence of the X ---->>>>

     vector<int> find(int arr[], int n , int x )
    {
        
        int s = 0 , e = n-1 ;
        
        int mid =(s+e)/2 ;
        int first = -1 , last = -1 ;
        while( s <= e){
            
            if(arr[mid] == x){
               first = mid ;
               e = mid-1 ;
            }else if( arr[mid] < x){
                s = mid+1 ;
            }else{
                e = mid -1 ;
            }

            mid = (s+e)/2 ;
        }
        
        
        s = 0 , e = n-1 ;
        mid =(s+e)/2 ;
         while( s <= e){
            //  cout<<mid<<endl;
            if(arr[mid] == x){
               last = mid;
               s = mid+1;
            }else if( arr[mid] < x){
                s = mid+1 ;
            }else{
                e = mid -1 ;
            }
            
            mid = (s+e)/2 ;
        }
        
        vector<int> ans ;
        
        ans.push_back(first);
        ans.push_back(last);
        
        return ans ;
    }


    Q2)-: Search in the Rotated array->>>>>

         int search(vector<int>& nums, int target) {
        int s=0, e=nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[s]<=nums[mid]){
                if(nums[s]<=target && target<nums[mid])
                    e = mid-1;
                else
                    s = mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[e])
                    s = mid+1;
                else
                    e = mid-1;
            }
        }
        return -1;
    }

   Q3)-: Count the Squares present upto the number --->>>

        int countSquares(int N) {
        
        
        int count = 0 ;
        
        long long i =1 ;
        
        while( i*i < N){
            count++ ;
            i++ ;
        }
        
        return count ;
        
        
    }

    Q4)-: Find the repeating and the missing ---->>>

     vector<int> findTwoElement(vector<int> nums, int size) {
        // code here
        vector<int> ans;
        int total=0;
        for(int i=0;i<size;i++){
            int index = abs(nums[i]) - 1; 
            if(nums[index]<0 ){
                ans.push_back(abs(nums[i]));
            }else{
                nums[index] = -  nums[index]; 
                 total += abs(nums[i]);
            }

        }
                int sum = (nums.size() *( nums.size() + 1)/2);
                ans.push_back(sum-total);   
        return ans;
        
    } 
*/