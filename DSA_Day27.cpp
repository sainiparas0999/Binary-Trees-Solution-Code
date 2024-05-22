/*
Q1) -: count And Say problem in Strings -->>

      class Solution {
public:
    string countAndSay(int n) {
        
         if( n == 1){
            return "1" ;
         }else{

            string prev = countAndSay( n-1);

            char currChar = prev[0];
            int currCount = 1 ;

            string ret = "";

            for( int i =1 ; i<prev.size() ; i++){

           if( prev[i] != currChar){
            ret  = ret + to_string(currCount) + currChar ;
            currChar = prev[i];
            currCount = 1 ;
           }else{
             currCount++ ;
           }

            }

            ret = ret + to_string(currCount) + currChar ;
            return ret ;
         }
    }
};


 Q2) - :  Find the Longest palindrome in the String --->>> 

       string longestPalin (string S) {

       int maxLength = INT_MIN ;
       int start = 0 , end = 0 ;
       
       for( int i = 0 ; i<S.length() ; i++){
           
           int left = i ;
           int right = i ;
           
           while( S[left] == S[right] && left >= 0 && right<S.length()){
               left-- ;
               right++ ;
           }
           
           int length =  (right-1) - (left+1) ;
           
           if( length > maxLength){
              maxLength = length ;
              start = left+1 ;
              end = right -1 ;
           }
       }
       
       
       
        for( int i = 0 ; i<S.length()-1 ; i++){
           
           int left = i ;
           int right = i+1 ;
           
           while( S[left] == S[right] && left >= 0 && right<S.length()){
               left-- ;
               right++ ;
           }
           
           int length =  (right-1) - (left+1) ;
           
           if( length > maxLength){
              maxLength = length ;
              start = left+1 ;
              end =   right -1 ;
           }
        }
        
        string ans = "";
        for( int i = start ; i<= end ; i++){
           ans = ans + S[i]; 
        }
        
        return ans ;
    
    }

    Q3) -: Print all the Subsequence of the String --->>

        void allSubsequence( String input , vector<string>&ans , string temp , int  index ){
        // base case 
        if(index > input.size()){
            ans.push_back(temp); 
        }

        // exclude 
       
         allSubsequence( input , ans , temp , index+1);

         //include

         allSubsequence( input , ans , temp+input[index] , index+1) ;

      }
     
     void printSubsequence( String input , String output){

       vector<string>ans 
       string temp ="";
       int index = 0 ;

         allSubsequence( input , ans ,temp ,  index) ;

         return temp ;
     }


     Q4)-: Longest Common SubStrings ---->>>>

          string longestCommonPrefix(vector<string>& strs) {

        string ans = "";
       for( int i = 0 ; i<strs[0].length() ; i++){
         char common = strs[0][i];
         for( int j = 1 ; j<strs.size() ;j++ ){
            if(strs[j][i] != common){
                return ans ;
            }
         }
         ans.push_back(common);
       } 
       return ans ;
    }
*/