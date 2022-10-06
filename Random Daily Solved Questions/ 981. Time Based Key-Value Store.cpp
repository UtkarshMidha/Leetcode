// class TimeMap {
// public:
//     unordered_map<string, unordered_map<int, string>> keyTimeMap;
//     TimeMap() {
//     }
    
//     void set(string key, string value, int timestamp) {
//         // Store '(timestamp, value)' pair in 'key' bucket.
//         keyTimeMap[key][timestamp] = value;
//     }
    
//     string get(string key, int timestamp) {
//         // If the 'key' does not exist in map we will return empty string.
//         if (!keyTimeMap.count(key)) {
//             return "";
//         }
        
//         // Iterate on time from 'timestamp' to '1'.
//         for (int currTime = timestamp; currTime >= 1; --currTime) {
//             // If a value for current time is stored in key's bucket we return the value.
//             if (keyTimeMap[key].count(currTime)) {
//                 return keyTimeMap[key][currTime];
//             }
//         }
        
//         // Otherwise no time <= timestamp was stored in key's bucket.
//         return "";
//     }
// };



class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // Push '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        
        if (timestamp < keyTimeMap[key][0].first) {
            return "";
        }
        
        // Using binary search on the array of pairs.
        int left = 0;
        int right = keyTimeMap[key].size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (keyTimeMap[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // If iterator points to first element it means, no time <= timestamp exists.
        if (right == 0) {
            return "";
        }
                
        return keyTimeMap[key][right - 1].second;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
