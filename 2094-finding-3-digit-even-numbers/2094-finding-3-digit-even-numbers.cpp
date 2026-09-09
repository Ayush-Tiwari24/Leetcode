class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        vector<int> ans;
        vector<int> freq(10, 0);

        for (int x : arr)
            freq[x]++;

        for (int i = 100; i <= 999; i++) {
            int x = i;

            int a = x % 10;
            x /= 10;

            int b = x % 10;
            x /= 10;

            int c = x;

            if (a % 2 != 0)
                continue;

            freq[c]--;

            if (freq[c] >= 0) {
                freq[b]--;

                if (freq[b] >= 0) {
                    freq[a]--;

                    if (freq[a] >= 0)
                        ans.push_back(i);

                    freq[a]++;
                }

                freq[b]++;
            }

            freq[c]++;
        }

        return ans;
    }
};