class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int j = 0;  
        int m = passengers.size();
        vector<int> lastBusPassengers;
        for (int i = 0; i < buses.size(); i++) {
            int cap = capacity;
            while (j < m && passengers[j] <= buses[i] && cap > 0) {
                if (i == buses.size() - 1) {  
                    lastBusPassengers.push_back(passengers[j]);
                }
                j++;
                cap--;
            }
        }

        int lastBus = buses.back();
        int ans;
        if (lastBusPassengers.size() < capacity) {
            ans = lastBus;
        } 
        else {
            ans = lastBusPassengers.back() - 1;
        }
        unordered_set<int> S(passengers.begin(), passengers.end());
        while (S.count(ans)) ans--;

        return ans;
    }
};