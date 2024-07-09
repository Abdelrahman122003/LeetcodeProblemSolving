class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double curr = 0, waiting = 0;
            for(int i = 0; i < customers.size();i++)
            {
                    if(curr >= customers[i][0])
                            curr += customers[i][1];
                    else
                         curr = customers[i][0] + customers[i][1];
                    waiting += curr - customers[i][0];
           }
            
       return (waiting/customers.size());
    }
};