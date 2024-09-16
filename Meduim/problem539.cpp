class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        // Get the number of time points
        int size = timePoints.size();
        
        // Vector to store time in minutes since midnight
        vector<int> time_min(size, 0);
        
        // Convert each time point to minutes since midnight
        for(int i = 0; i < size; i++) {
            int hours = stoi(timePoints[i].substr(0, 2));  // Extract hours
            int minutes = stoi(timePoints[i].substr(3, 2)); // Extract minutes
            time_min[i] = (hours == 0 ? 24 : hours) * 60 + minutes;  // Convert to minutes, treating midnight as 24 hours
        }
        
        // Sort the times in minutes
        sort(time_min.begin(), time_min.end());

        // Initialize minimum difference to a large value
        int mn = 1e9;
        
        // Find the minimum difference between consecutive times
        for(int i = 1; i < size; i++)
            mn = min(mn, time_min[i] - time_min[i - 1]);
        
        // Check the difference that wraps around midnight
        mn = min(mn, 1440 - time_min.back() + time_min.front());

        return mn;  // Return the minimum difference
    }
};
