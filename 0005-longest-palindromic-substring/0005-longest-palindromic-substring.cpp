class Solution {
public:

   void expandaround(string s,int left,int right,int& start,int& maxlen){

    int n=s.length();
    while(left>=0 && right<n && s[left]==s[right]){
        if(right-left+1>maxlen){
            start=left;
            maxlen=right-left+1;
        }
        left--;
        right++;
    }
   }
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
         int maxlen=1;
         int start=0;
        for(int i=0;i<n;i++){
            expandaround(s,i,i,start,maxlen);
            expandaround(s,i,i+1,start,maxlen);
        }
        return s.substr(start,maxlen);
    }
};