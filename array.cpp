//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num3;

        for (int i = 0; i < nums1.size(); i++) {
            num3.push_back(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++) {
            num3.push_back(nums2[i]);
        }

        // Bubble sort
        for (int i = 0; i < num3.size(); i++) {
            for (int j = 0; j < num3.size() - i - 1; j++) {
                if (num3[j] > num3[j + 1]) {
                    int temp = num3[j];
                    num3[j] = num3[j + 1];
                    num3[j + 1] = temp;
                }
            }
        }

        // Calculating median
        int n = num3.size();
        double median;
        if (n % 2 == 0) {
            median = (num3[n / 2] + num3[n / 2 - 1]) / 2.0;
        } else {
            median = num3[n / 2];
        }

        return median;
    }
};

int main() {
    Solution sol;
    vector<int> nums1;
    vector<int> nums2;
    int n,m;
    cout<<"enter the value of n for nums1 and m for nums2"<<endl;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter the value of the element in nums1 "<<endl;
        cin>>x;
        nums1.push_back(x);
    }
        for(int i=0;i<m;i++){
        int x;
        cout<<"enter the value of the element in nums2"<<endl;
        cin>>x;
        nums2.push_back(x);
    }

    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;

    return 0;
}