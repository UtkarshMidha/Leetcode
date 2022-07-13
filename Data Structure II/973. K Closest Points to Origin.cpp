class Solution {
private:
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         // Sort the vector with a custom lambda comparator function
//         sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
//             return squaredDistance(a) < squaredDistance(b);
//         });
        
//         // Return the first k elements of the sorted vector
//         return vector<vector<int>>(points.begin(), points.begin() + k);
//     }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxPQ;
        for (int i = 0 ; i < points.size(); i++) {
            pair<int, int> entry = {squaredDistance(points[i]), i};
            if (maxPQ.size() < k) {
                // Fill the max PQ up to k points
                maxPQ.push(entry);
            } else if (entry.first < maxPQ.top().first) {
                // If the max PQ is full and a closer point is found,
                // discard the farthest point and add this one
                maxPQ.pop();
                maxPQ.push(entry);
            }
        }

        // Return all points stored in the max PQ
        vector<vector<int>> answer;
        while (!maxPQ.empty()) {
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            answer.push_back(points[entryIndex]);
        }
        return answer;
    }
    
};
