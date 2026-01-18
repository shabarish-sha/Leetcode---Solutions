int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0], cur = nums[0];
    for (int i = 1; i < numsSize; i++) {
        cur = cur > 0 ? cur + nums[i] : nums[i];
        if (cur > maxSum) maxSum = cur;
    }
    return maxSum;
}
