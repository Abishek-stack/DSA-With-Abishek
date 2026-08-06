class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int mul = 1;
            int x = n;

            while (x > 0) {
                int digit = x % 10;
                mul *= digit;
                x /= 10;
            }

            if (mul % t == 0)
                return n;

            n++;
        }
    }
};