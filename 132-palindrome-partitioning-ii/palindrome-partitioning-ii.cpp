class Solution {
public:

    int minCut(string s) {
        int n=s.size();

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j=i+l-1;

                if(s[i]==s[j]){
                    if(l==2){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }

        vector<int> cuts(n, 0);

        for (int i = 0; i < n; i++) {
            if (dp[0][i]) {
                cuts[i] = 0; // No cut needed if s[0..i] is a palindrome
            } else {
                cuts[i] = i; // Max cuts possible (cut before every character)
                for (int j = 1; j <= i; j++) {
                    if (dp[j][i]) {
                        cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }

        return cuts[n - 1];
        
    }
};