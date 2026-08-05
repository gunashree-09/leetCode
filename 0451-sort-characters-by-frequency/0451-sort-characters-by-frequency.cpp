class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(freq--){
                ans+=ch;

            }
            

        }
        return ans;
    }
};