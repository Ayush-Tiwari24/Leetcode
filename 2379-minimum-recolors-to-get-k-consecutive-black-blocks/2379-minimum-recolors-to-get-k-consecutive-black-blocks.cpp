class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int st = 0;
        int ans = INT_MAX;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'B') {
                count++;
            }
            if (i - st + 1 > k) {
                if (blocks[st] == 'B') {
                    count--;
                }
                st++;
            }
            if (i - st + 1 == k) {
                ans = min(ans, k - count);
            }
        }
        return ans;
    }
};