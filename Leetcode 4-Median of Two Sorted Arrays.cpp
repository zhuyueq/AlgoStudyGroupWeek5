//Solution1:faster than 98%

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        int left = 0, right = n * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};

// Solution2:overflow...

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //n>=m
        vector<int> nums_1,nums_2;
        int m=nums1.size();
        int n=nums2.size();
        if (m==0)
        {
            if (n%2==0)   return (nums2[n/2]+nums2[n/2-1])/2;
            else return nums2[int(n/2)];
        }
        if (n==0)
        {
            if (m%2==0)   return (nums1[m/2]+nums1[m/2-1])/2;
            else return nums1[int(m/2)];
        }
        if (n<m) {
            nums_1=nums2;
            nums_2=nums1;
        }
        else
        {
            nums_1=nums1;
            nums_2=nums2;
        }
        int left=0;
        int right=nums_1.size();
        int i,j;
        while (left<=right)
        {
            i=int((left+right)/2);
            j=int((m+n+1)/2-i);
            if (i<right && nums_2[j-1]>nums_1[i]) left=i+1;
            else if  (i>left && nums_1[i-1]>nums_2[j]) right=i-1;
            else
            {
                int maxLeft,minRight=0;
                if (i==0) maxLeft=nums_2[j-1];
                else if (j==0) maxLeft=nums_1[i-1];
                else maxLeft=max(nums_1[i-1],nums_2[j-1]);
                if ((m+n)%2==1) return maxLeft;
                
                if (i==m) minRight=nums_2[j];
                else if (j==n) minRight=nums_1[i];
                else minRight=min(nums_2[j],nums_1[i]);
                
                return (maxLeft+minRight)/2.0;
            }
        }
        return 0;
    }
};