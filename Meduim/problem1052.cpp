// Prefix Sum Solution
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satisfied = 0, notSatisfied = 0;
// Convert the customers vector to only include days that are unsatisfied and evaluate the satisfied minutes.
            for(int i = 0; i < n;i++){
                    if(!grumpy[i])
                            satisfied += customers[i];
                    customers[i] *= grumpy[i];
            }
//             then perform perfix sum
            for(int i = 1;i < n;i++)
                    customers[i] += customers[i-1];
//             then max consecutive minutes
            for(int i = minutes - 1; i < n;i++)
                    notSatisfied = max(notSatisfied, customers[i] - (i - minutes >= 0? customers[i - minutes]: 0));
            cout << notSatisfied << endl;
            return satisfied + notSatisfied;
    }
};
