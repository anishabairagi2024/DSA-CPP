#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right;

        while (left <= right) {
            int k = left + (right - left) / 2;
            long long hours = 0;

            for (int p : piles) {
                // Integer ceiling division for p / k
                hours += (p + k - 1) / k;
            }

            if (hours <= h) {
                res = k;
                right = k - 1; // try a slower speed
            } else {
                left = k + 1;  // need a faster speed
            }
        }

        return res;
    }
};
