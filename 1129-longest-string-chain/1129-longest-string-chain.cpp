class Solution {
private:
    bool compare(string a , string b){
        if(b.size()!=a.size()+1)
        return false;
        int n=b.size();
        int ct=0,i=0,j=0;
        while(i<n){
            if(ct>1)
            return false;
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else{
                ct++;
                j++;
            }
        }
        return true;
    }
    int solve(int n , vector<string> &arr){
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(arr[j],arr[i]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }

       return maxi;
    }
public:
    static bool cmp(string &a , string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        return solve(words.size(),words);
    }
};