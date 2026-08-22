class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum = 0 ;
        int temp = n;
        while(temp > 0){
         int digit = temp%10;
         sum += digit;
         prod*=digit;
         temp = temp/10;
        }
        int ans = sum + prod ;
        if(n % ans == 0){
            return true;
        } else
        return false;
    }
};