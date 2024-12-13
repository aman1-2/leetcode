#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int end1, int end2) {
    return end2 > end1;
}

int maxTwoEvents(vector<vector<int>> &events) {
    //STEP 1: Need to sort the event based on their end time
    sort(events.begin(), events.end(), ([](
        const vector<int> &a, vector<int> &b) { 
            return a[1] < b[1]; // Sort by end time.
        }
    ));
    
    int n = events.size();

    //STEP 2: Creating a max value upto each event
    vector<int> max_value_before(n, 0);
    //STEP 3: To store start times of the event.
    vector<int> start_times(n);

    int max_so_far = 0;

    for(int i=0; i<n; i++) {
        max_so_far = max(max_so_far, events[i][2]);
        max_value_before[i] = max_so_far;
        start_times[i] = events[i][0];
    }

    int max_sum = 0;

    for(int i=0; i<n; i++) {
        int currStart = events[i][0];
        int currValue = events[i][2];

        //OPTION 1: To consider the current value alone itself
        auto it = lower_bound(start_times.begin(), start_times.end(), currStart) - 1;
        int idx = distance(start_times.begin(), it);

        if (idx >= 0) {
            max_sum = max(max_sum, currValue + max_value_before[idx]);
        }
    }

    return max_sum;
}

int main() {
    vector<vector<int>> events = {{1,3,2}, {4,5,2}, {2,4,3}};
    int ans = maxTwoEvents(events);
    cout<<ans;
    return 0;
}

