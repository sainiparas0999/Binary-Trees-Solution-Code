/*
Q1)-: Rat in a Maze problem --->>>>>

         void solve(  vector< vector<int> > &m ,vector<string>& ans , string temp , int i , int j , int n){
         
         // base case 
         if( i <0 || j< 0 || i>=n || j>=n ||  m[i][j] == 0 ) return ;
         
         if( i == n-1 && j == n-1){
             ans.push_back( temp);
             return ;
         }
         
          m[i][j] =  0 ;
           
           temp.push_back('U');
          solve(m , ans , temp , i-1 , j , n );
          temp.pop_back();
          
          
          temp.push_back('R');
          solve( m , ans , temp , i , j+1 , n);
          temp.pop_back();
          
          temp.push_back('D');
          solve( m , ans , temp  , i+1 , j , n);
          temp.pop_back();
          
          temp.push_back('L');
          solve( m , ans , temp , i , j-1 , n);
          temp.pop_back() ;
          m[i][j] = 1;
     }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
      
       vector<string> res ;
       string temp = "";
       solve( m , res , temp , 0 , 0, n);
       return res ;
    }


    Q2)-: 
*/