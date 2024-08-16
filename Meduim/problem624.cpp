// The solution description:

//1)For this problem, we aim to maximize the difference between the values in two priority queues.

// 2)If we consider using mn and mx variables to minimize and maximize values, a problem arises: mn and mx might come from the same array, but the problem requires that mn and mx come from different arrays.

// 3)To handle this, we will use a max heap and a min heap. If the top of the min heap and the top of the max heap are from the same index, we will remove one of them and store it in mn or mx accordingly.

// 4)We will then decide whether to reinsert mn or mx based on the following condition:

// If max.top().first - mn.first >= mx.first - min.top().first, we reinsert mn.
// Otherwise, we reinsert mx.
// Example:
// Given:

// Min heap: [{1, 0}, {5, 2}, {6, 1}]
// Max heap: [{20, 0}, {19, 2}, {17, 1}]
// Initially, the top of the min heap and the top of the max heap are from the same index, so we remove one of them. For example:

// Min heap after removal: [{5, 2}, {6, 1}]
// Max heap after removal: [{19, 2}, {17, 1}]
// mn = {1, 0}
// mx = {20, 0}
// We then compare:

// Case 1: Reinsert mn, which gives a difference of 19 - 1 = 18
// Case 2: Reinsert mx, which gives a difference of 20 - 5 = 15
// Since the difference in Case 1 is greater, we reinsert mn.
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>>max;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>min;
        for(int i = 0; i < arrays.size(); i++)
                max.push({arrays[i].back(), i}),   min.push({arrays[i][0], i});
       while(min.top().second == max.top().second){
               pair<int, int>mn = min.top(), mx = max.top();
               min.pop(), max.pop();
               if(max.top().first - mn.first >= mx.first - min.top().first)
                       min.push(mn);
               else
                       max.push(mx);
       }
            return abs(max.top().first - min.top().first);
    }
};
