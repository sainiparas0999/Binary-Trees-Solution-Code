/*
Q1)-: Word Break Problem by using memoization --->>> 
     
     class Solution
{
    unordered_map<string , int> dp ;
    int solve( int n , string s , vector<string>&d){
        
        int sz = s.length() ;
        if( sz == 0) return 1 ;
        if( dp[s] != 0){
            return dp[s];
        }
        
        for( int i = 1 ; i<=sz ; i++){
            
            string temp = s.substr( 0 , i);
             bool flag = false ;
            for( int j = 0 ; j<d.size() ; j++){
                if(temp.compare( d[j]) == 0){
                    flag = true ;
                    break ;
                }
            }
            
            if( flag == true && solve( n , s.substr( i , sz-i) , d) == 1) return dp[s] = 1;
        }
        return dp[s] = -1 ;
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        
        int ans =  solve(n ,s , dictionary);
        if( ans == 1) return 1 ;
        else return 0 ;
    }
};


Q2)-: Word Break Problem (Hard Question By using Backtracking) ---->>>>>>

    int solve( int & n , vector<string> &dict , string s , vector<string> &ans , string temp){
       
       int sz = s.length() ;
       if( sz == 0){
           ans.push_back(temp);
           return 1 ;
       }
       
       for( int i = 1 ; i<=sz ; i++){
           string ss = s.substr( 0 , i);
             int f = 0 ;
            for( int j = 0 ; j<n ; j++){
                
              if(ss.compare( dict[j]) == 0){ 
                  f = 1 ;
                  break ;
              }  
            }
            
            if( f == 1){
                string word ="" ;
                if( temp.empty()){
                  word = temp + ss ;
                }else{
                   word = temp + " " + ss ;
                }
                solve( n  , dict , s.substr( i , sz-i) , ans , word);
            }
            
       }
       return -1 ;
       
   }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans ;
        string temp ="";
        solve( n , dict , s  , ans , temp );
        
        return ans ;
    }



    Q3)-: Word Wrap Problem (Dynamic programming) ---->>>>>

          int dp[505][2005];
    int solve( int index , int rem , vector<int>&nums , int k){
        
        // base case 
        if( index >= nums.size()){
            return 0 ;
        }
         if(dp[index][rem] != -1){
             return dp[index][rem];
         }
         int ans ;
        if( rem < nums[index]){
            ans =  (rem +1)*(rem +1) + solve( index + 1 , k-nums[index]-1 , nums , k );
        }else{
            
            int ans1 = solve( index  +1 , rem -nums[index] - 1 , nums , k);
            int ans2 =  ( rem+1) *(rem+1) + solve( index + 1 , k -nums[index]-1 , nums , k);
            
            ans = min( ans1 , ans2);
        }
        dp[index][rem] = ans ;
        return dp[index][rem] ;
        
    }
    
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
      memset( dp , -1 , sizeof(dp));
      return solve( 0 , k , nums , k);
    
    } 


    
   
*/