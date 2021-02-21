class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n != 0) {
            if (n == 1) return true;
            if ((n & 0b11) != 0) return false;
            n >>= 2;
        }

        return false;
    }
};