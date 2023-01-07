class Solution {
public:
    long long count = 0;
    int n;
    std::vector<int> v;
    std::vector<int> u;

    //find number of elements in u which are >= x
    int myBinarySearch(int x) {
        if (x <= u[0]) return u.size();
        if (x > u.back()) return 0;
        int left = 0;
        int right = u.size() - 1;
        //control u[left] < x <= u[right]
        int mid;
        while (left < right) {
            if (right - left == 1) break;
            mid = (left + right) / 2;
            if (u[mid] < x) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return u.size() - right;
    }

    void myBinaryInsert(long long y) {
        if (y >= u.back()) {
            u.push_back(y);
            return;
        }
        if (y <= u[0]) {
            u.insert(u.begin(), y);
            return;
        }
        int left = 0, right = u.size() - 1;
        int mid;
        //control u[left]<y<u[right] 
        while (left <= right) {
            if (right == left + 1) {
                u.insert(u.begin() + right, y);
                break;
            }
            mid = (left + right) / 2;
            if (u[mid] == y) {
                u.insert(u.begin() + mid, y);
                break;
            }
            else if (u[mid] < y) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        n = nums1.size();
        for (int i = 0; i < n; i++) {
            v.push_back(nums1[i] - nums2[i]);
        }
        u.push_back(v.back());
        long long test;
        for (int i = n - 2; i >= 0; i--) {
            test = v[i] - diff;
            count += myBinarySearch(test);
            myBinaryInsert(v[i]);
        }
        return count;
    }
};