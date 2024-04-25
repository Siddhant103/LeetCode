class Solution {


   int SolveByMemo(string &s , int &k , int index , int prev , vector<vector<int>> &dp)
   {
       if(index == s.length())
       return 0;

       if(dp[index][prev] != -1)
       return dp[index][prev];

       int op1 = 0 + SolveByMemo(s, k , index+1 , prev , dp);

       int op2 = 0 ;

       if(prev == 26)
       op2 = 1 + SolveByMemo(s, k , index+1 , s[index]-'a' , dp);
       else if(abs(s[index]-'a' - prev) <= k)
       op2 = 1 + SolveByMemo(s, k , index+1 , s[index]-'a' , dp);

       return dp[index][prev] = max(op1 , op2);
   }

   int SolveByTab(string &s , int &k )
   {
        vector<vector<int>> dp(s.length()+1 , vector<int> (27, 0));
       
        for(int index = s.length()-1 ; index>=0 ; index--)
        {
            for(int prev = 0 ; prev<= 26 ; prev++)
            {
                int op1 = 0 + dp[index+1][prev];
                int op2 = 0 ;

               if(prev == 26)
               op2 = 1 + dp[index+1][s[index]-'a'];
               else if(abs(s[index]-'a' - prev) <= k)
               op2 = 1 + dp[index+1][s[index]-'a'];

               dp[index][prev] = max(op1 , op2);
            }
        }

       return max(dp[0][s[0]-'a'] , dp[0][26]);
   }

   int SolveByTabSpaceOptimised(string &s , int &k )
   {
        vector<int> next(27, 0) ;
        vector<int> curr(27, 0);
       
        for(int index = s.length()-1 ; index>=0 ; index--)
        {
            for(int prev = 0 ; prev<= 26 ; prev++)
            {
                int op1 = 0 + next[prev];
                int op2 = 0 ;

               if(prev == 26)
               op2 = 1 + next[s[index]-'a'];
               else if(abs(s[index]-'a' - prev) <= k)
               op2 = 1 + next[s[index]-'a'];

               curr[prev] = max(op1 , op2);
            }
            next = curr;
        }

       return max(curr[s[0]-'a'] , curr[26]);
   }

public:
    int longestIdealString(string s, int k) {
        
        // 1. Recursion + Memoization || Top Down Approach
        // vector<vector<int>> dp(s.length() , vector<int> (27, -1));
        // return SolveByMemo(s, k , 0 , 26, dp);

        // 2. Tabulation Method || Bottom Up Approach
        // return SolveByTab(s, k);

        // 3. Space Optimisation using Tabulation
        return SolveByTabSpaceOptimised(s , k);
    }
};