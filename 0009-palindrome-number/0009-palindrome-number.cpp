class Solution {
public:
    bool isPalindrome(int x) {
        double reverse = 0 , i , org = x;
        if(x<0){
            return false;
        }
        while(x > 0 ){
             i = x%10;
             reverse =( reverse * 10 )+ (i);
             x = x/10;
        }
     return org == reverse;
    }
};