class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;

        int pre = 0, cur = 1;
        for (int i = 2; i <= N; ++i) {
            int tmp = cur;
            cur = pre + cur;
            pre = tmp;
        }

        return cur;
    }
};