/*
Q1)-: Minimum Sum of Squares of char count after removing K characters.
 
        int minValue(string s, int k){
        map<char , int> count;
        
        for( int i = 0 ; i<s.length() ; i++){
            count[s[i]]++ ;
        }
        
        priority_queue<int> pq ;
        
        for(auto i :count){
            pq.push(i.second);
        }
        
        while(k >0){
            int ans = pq.top();
            ans = ans-1 ;
            pq.pop();
            k-- ;
            pq.push(ans);
        }
        
        int sum = 0 ;
        while(!pq.empty()){
          int ele = pq.top();
           sum = sum+(ele*ele);
           pq.pop();
        }
        
        return sum ;
    }

   Q2)-: check two trees are Anagram are not --->>>>

    
        bool areAnagrams(Node *root1, Node *root2){
        if(!root1 || !root2) return true;
        if(!root1 && !root2) return false;
        if(root1->data != root2->data) return false;
        
        queue<Node*>q1;
        queue<Node*>q2;
        
        q1.push(root1);
        q2.push(root2);
        
        int size1;
        int size2;
        vector<int>ans1;
        vector<int>ans2;
        
        while(!q1.empty() && !q2.empty()) {
            size1= q1.size();
            size2= q2.size();
            
            if(size1 != size2) return false;
            
            while(size1--) {
                Node *temp1 = q1.front();
                Node *temp2 = q2.front();
                q1.pop();
                q2.pop();
                
                ans1.push_back(temp1->data);
                ans2.push_back(temp2->data);
                
                if(temp1->left) q1.push(temp1->left);
                if(temp1->right) q1.push(temp1->right);
                
                if(temp2->left) q2.push(temp2->left);
                if(temp2->right) q2.push(temp2->right);
            }
            
            if(ans1.size() != ans2.size()) return false;
            
            sort(ans1.begin(), ans1.end());
            sort(ans2.begin(), ans2.end());
            
           if(ans1 != ans2) return false;
        }
        
        return true;
    }

    Q3)-: Merge Intervals int the form of array--->>>

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

    Q4)-: Kadane's Algortihm ---->>>>
     
         long long maxSubarraySum(int arr[], int n){
        
        long long maxSum = INT_MIN ;
        long long sum = 0 ;
        for( int i = 0 ; i<n ; i++){
            sum = sum + arr[i];
             maxSum = max(sum , maxSum);
             if( sum < 0){
                 sum = 0 ;
             }
        }
        return maxSum ;
    }
*/