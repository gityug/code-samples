// https://leetcode.com/problems/merge-sorted-array/
//
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 1; i <= m; ++i) {
            nums1[m + n - i] = nums1[m - i];
        }
        int i = n;
        int j = 0;
        int k = 0;
        while (k < m + n) {
            if (i >= m + n) {
                nums1[k++] = nums2[j++];
            } else if (j >= n) {
                nums1[k++] = nums1[i++];
            } else {
                if (nums1[i] < nums2[j]) {
                    nums1[k++] = nums1[i++];
                } else {
                    nums1[k++] = nums2[j++];
                }
            }
        }
    }
};
