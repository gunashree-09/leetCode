class Solution {
public:
 int findmax(vector<int>& pils){
            int maxi=INT_MIN;
            for(int i=0;i<pils.size();i++){
                if(pils[i]>maxi){
                    maxi=pils[i];
                }
            }
            return maxi;
        } 
long long totalhr(vector<int>& piles,int speed){

    long long total = 0;

    for(int i=0;i<piles.size();i++){
        total += ceil((double)piles[i] / (double)(speed));
    }

    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1;
        int hi=findmax(piles);
        while(l<=hi){
            int mid=l+(hi-l)/2;
            long long toth=totalhr(piles,mid);
            if(toth<=h){
                hi=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};