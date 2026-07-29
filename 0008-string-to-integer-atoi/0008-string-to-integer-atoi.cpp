class Solution {

public:
    int myAtoi(string s) {
        int i = 0;
        bool isNeg = false;

        while(s[i] == ' ')
            i++;
        
        if(s[i] == '-'){
            isNeg = true;
            i++;
        } else if(s[i] == '+'){
            isNeg = false;
            i++;
        }
        
        while(s[i] == '0'){
            i++;
        }

        long long ans = 0;
        for(int j = i; j < s.size(); j++){
            if(!isdigit(s[j]))
                break;

            if(isNeg){
                ans = ans * 10 - (s[j] - '0');
            } else {
                ans = ans * 10 + (s[j] - '0');
            }

            if(ans > INT_MAX)
                return INT_MAX;
            if(ans < INT_MIN) 
                return INT_MIN;
        }
        return ans;
    }   
};
    