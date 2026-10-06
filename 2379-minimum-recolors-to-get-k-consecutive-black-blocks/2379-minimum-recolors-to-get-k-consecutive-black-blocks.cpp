class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int st = 0;
        int ans = INT_MAX;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                count++;
            }
            if (i - st + 1 > k) {
                if (blocks[st] == 'W') {
                    count--;
                }
                st++;
            }
            if (i - st + 1 == k) {
                ans = min(ans, count);
            }
        }
        return ans;
    }
};