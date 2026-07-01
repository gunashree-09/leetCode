class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0,r=cardPoints.size()-1,lsum=0,rsum=0;


        for(int i=0;i<=k-1;i++){
            lsum+=cardPoints[i];
        }
        int maxsum=lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[r];
            r--;
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};