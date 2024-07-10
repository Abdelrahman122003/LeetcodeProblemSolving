class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
            for(auto k : logs)
                    count += (k == "../" && count > 0)?-1:(k != "../" && k != "./")?1:0;
            return (count < 0)?0:count;
    }
};