class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;
        unordered_map<char, char> mp;

        for(int i = 0; i < n; i++){
            char original = s[i];
            char replace = t[i];

            if(mp.find(original) == mp.end()){
                for(auto it : mp){
                    if(it.second == replace){
                        return false;
                    }
                }
                mp[original] = replace;
            }
            else{
                if(mp[original] != replace) return false;
            }
        }

        return true;
    }
};