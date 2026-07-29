class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int l=0,r=1,cnt=0;
        sort(intervals.begin(),intervals.end());
        while(l<intervals.size() && r<intervals.size()){
                if(intervals[l][1]>intervals[r][0]){
                    cnt++;
                    if(intervals[l][1]>intervals[r][1]){
                        l=r;

                    }
                    r++;
                }
                else {
                    l=r;
                    r++;
                }

        }
        return cnt;
    }
};