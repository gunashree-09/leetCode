class Solution {
public:
    bool checkValidString(string s) {
        int l=0;
        int h=0;
     
        for(char st:s){
            if(st=='('){
                l++;
                h++;
            }
            else if( st==')'){
                l--;
                h--;
            }
            else{
                l--;
                h++;
            }
            if(l<0){
                l=0;
            }
            if(h<0) return false;
        }
       return l==0;
    }
};