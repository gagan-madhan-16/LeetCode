class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0,n=arr.size(),maxsum=0;

        for(int i=n-k;i<n;i++){
            sum+=arr[i];
        }

        maxsum=sum;

        for(int i=0;i<k;i++){
            sum=sum+arr[i]-arr[n-k+i];
            maxsum=max(maxsum,sum);
        }

        return maxsum;
    }
};