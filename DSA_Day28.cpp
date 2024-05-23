/*
Q1)-: Print all the permutation of a given String --->>> 

  	 void permu( string &s , int index , vector<string> &ans){
	     
	     // base case 
	     if( index >= s.length()){
	         ans.push_back(s);
	         return ;
	     }
	     
	     for( int j = index ; j<s.length() ; j++){
	         
	         swap(s[index] , s[j]);
	         permu(s , index+1 , ans);
	         swap(s[index] , s[j]);
	     }
	     
	 }
		vector<string>find_permutation(string S)
		{
		    
		    vector<string> result ;
		    int i = 0 ;
		    permu( S , i , result);
		    vector<string> ans ;
		    for( int i = 0 ; i<result.size() ; i++){
		        
		        if(find(ans.begin() , ans.end() , result[i] ) == ans.end()){
		            ans.push_back(result[i]);
		        }
		    }
		    
		    return ans ;
		}


        Q2)-: Split the Binary string into two SubStrings with equal 0 and 1 -->>>

             int maxSubStr(string s){
      
      int zero = 0 , one = 0 ;
      int count = 0 ;
      
      for( int i = 0 ; i<s.length() ; i++){
          
          if(s[i] == '0')
           zero ++ ;
           
          if( s[i] == '1')
          one++ ;
          
          if(zero == one){
              count++ ;
              zero = 0 ;
              one = 0 ;
          }
      }
      if( zero != one){
          return -1 ;
      }
      return count ;
    }


    Q3)-: Find the next permutation of the String --->>> 

         vector<int> nextPermutation(int N, vector<int> arr){
        
        int ind = 0;
        vector<int> v = arr;
        
    
        for(int i = N-2;i >= 0;i--){
            if(v[i] < v[i+1]){
                ind = i;
                break;
            }
        }
        
      
        for(int i = N-1;i > ind;i--){
            if(v[i] > v[ind]){
                swap(v[i], v[ind]);
                ind++;
                break;
            }
        }
        
        // Reversing the elements from ind to end
        for(int i = 0;i < (N-ind)/2;i++)
            swap(v[i+ind], v[N-i-1]);
        
        // Returning the next permutation
        return v;
        
    }

    Q4) -: find the second most repetitive string in the vector --->>
      
 string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    
    int maxfreq = INT_MIN;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > maxfreq) {
            maxfreq = it->second;
        }
    }
    
    int secondmaxfreq = INT_MIN;
    string secondmaxName = "";
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second < maxfreq && it->second > secondmaxfreq) {
            secondmaxfreq = it->second;
            secondmaxName = it->first;
        }
    }
    
    return secondmaxName;
    }  
*/