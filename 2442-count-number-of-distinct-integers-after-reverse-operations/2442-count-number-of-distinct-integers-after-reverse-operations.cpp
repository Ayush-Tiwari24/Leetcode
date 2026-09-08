class Solution {
public:
    int reverse(int n) {
        int r = 0;

        while (n) {
            r = (r * 10) + (n % 10);
            n /= 10;
        }

        return r;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            int rev = reverse(nums[i]);
            s.insert(rev);
            s.insert(nums[i]);
        }


        return s.size();
    }
};