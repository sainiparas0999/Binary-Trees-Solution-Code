/*
Q1) -: check whether the String is Palindrome or not -->>

     	int isPalindrome(string S)
	{
	    int s = 0 , e = S.length()-1 ;
	    
	    while( s < e){
	        if(S[s] != S[e])
	        return false ;
	        s++ ;
	        e-- ;
	    }
	    
	    return true ;
	}



 Q2)-: Find the Duplicate characters in a string 

    vector<char> duplicate( String S){
        vector<char> ans ;
        vector<int>arr(26 , -1);

        for( int i = 0 ; i<S.length() ; i++){

            int ele = S[i] - 'a' ;

            if(arr[ele] != -1){
               ans.push_back(S[i]);
            }else{
                arr[ele] = 1 ;
            }
        }

        return ans ;
    }

    Q3)-: check whether that one string is rotation of other or not --->>> 

     bool isRotation( string s1 , string s2 , int n){
 
       // Note all the positons in String 2 which will be the starting point of string 1 ;

       vector<int> startingPoint ;

       for( int i = 0 ; i<n ; i++){
           if(s1[0] == s2[i])
           startingPoint.push_back(i);
       }


       for( int i = 0 ; i<startingPoint.size() ; i++){

          int index = startingPoint[i]; 
          bool ans = true ;    
        for( int j = 0 ; j<n ; j++){
            if(s1[j] != s2[index % n])
              ans  = false ;
              
              index++ ;
        }

           if( ans == true){
            return true ;
           }
       }

       return false ;

     }


     Q4)-:  Valid Parenthesis Problem --->>>

          bool ispar(string x)
    {
        stack<char> s ;
        for( int  i = 0 ; i<x.length() ; i++){
           
           if(x[i] == '(' || x[i] == '{' || x[i] == '['){
               s.push(x[i]);
           }else if(  (s.empty()) && (x[i] == ')' || x[i] == '}' || x[i] == ']')){
               return false ;
           }  else if( x[i] == ')' && s.top() == '('){
               s.pop();
            }else if( x[i] == '}' && s.top() == '{'){
               s.pop();
           }else if( x[i] == ']' && s.top() == '['){
               s.pop();
           }else{
               s.push(x[i]);
           }
        }
        if(s.empty()){
            return true ;
        }else{
            return false ;
        }
    }
*/