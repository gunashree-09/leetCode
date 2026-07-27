class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        int cnt=0;
        if(s.size()==0) return 0;
        while(r<s.size() && l<g.size()){
            if(s[r]>=g[l]){
                
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return l;
    }
};