class Solution {
public:
    
    bool timeEnough(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for (int t : time) {
            actualTrips += givenTime / t;
        }
        return actualTrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left = 1, right = 1LL * *max_element(time.begin(), time.end()) * totalTrips;

        
        while (left < right) {
            long long mid = (left + right) / 2;
            if (timeEnough(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
