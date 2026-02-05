class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = -1;

        // Binary search
        while (low <= high) {
            int m = low + (high - low) / 2;
            if (nums[m] == target) {
                mid = m;
                break;
            } else if (nums[m] < target) {
                low = m + 1;
            } else {
                high = m - 1;
            }
        }

        // Target not found
        if (mid == -1)
            return {-1, -1};

        int l = mid;
        int r = mid;

        while (l >= 0 && nums[l] == target) l--;
        while (r < nums.size() && nums[r] == target) r++;

        return {l + 1, r - 1};
    }
};