class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {

        int i = nums.size() - 1;

        while (i >= 0 && k > 0) {
            int sum = nums[i] + k % 10;

            nums[i] = sum % 10;
            k = k / 10 + sum / 10; // carry handling

            i--;
        }
        while(k > 0) {
            nums.insert(nums.begin(), k % 10);
            k /= 10;
        }

        return nums;
    }
};