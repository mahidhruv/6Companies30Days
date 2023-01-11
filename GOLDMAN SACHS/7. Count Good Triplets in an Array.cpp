class Solution {
public:
    class SegmentTree {
    public:
        int size;
        vector<int> values;

        SegmentTree(int s): size(s) {
            values = vector<int>(s * 2);
        }

        void increase(int pos) {
            pos += size;

            while (pos > 0) {
                values[pos]++;
                pos /= 2;
            }
        }

        int sum(int l, int r) {
            l += size;
            r += size;

            int res = 0;
            while (l <= r) {
                if (l % 2 == 1) {
                    res += values[l];
                    l++;
                }
                if (r % 2 == 0) {
                    res += values[r];
                    r--;
                }

                r /= 2;
                l /= 2;
            }

            return res;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> indexMap(n, 0);

        for (int i = 0; i < n; ++i) {
            indexMap[nums2[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            nums2[indexMap[nums1[i]]] = i;
            nums1[i] = i;
        }

        SegmentTree st(n);

        long long res = 0;

        st.increase(nums2[0]);

        for (int i = 1; i < n - 1; ++i) {
            int num = nums2[i];

            int l = st.sum(0, num - 1);
            int r = n - num - i + l - 1;

            res += (long long)r * l;

            st.increase(num);
        }

        return res;
    }
};