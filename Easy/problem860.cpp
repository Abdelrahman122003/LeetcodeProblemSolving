class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Tuple to store the count of $5, $10, and $20 bills, initialized to (0, 0, 0)
        tuple<int, int , int> prices(0, 0, 0);

        // Iterate through each bill in the input vector
        for(auto k : bills) {
            // If the bill is $5, increment the count of $5 bills
            if(k == 5)
                get<0>(prices)++;

            // If the bill is $10
            if(k == 10) {
                // Check if there's at least one $5 bill to give as change
                if(get<0>(prices) > 0)
                    get<0>(prices)--;  // Give back one $5 bill
                else 
                    return false;  // If no $5 bill, return false (change cannot be given)
                
                // Increment the count of $10 bills
                get<1>(prices)++;
            }

            // If the bill is $20
            if(k == 20) {
                // Check if there's at least one $10 bill and one $5 bill to give as change
                if(get<0>(prices) > 0 && get<1>(prices) > 0) 
                    get<0>(prices)--,  // Give back one $5 bill
                    get<1>(prices)--;  // Give back one $10 bill
                
                // Otherwise, check if there are at least three $5 bills to give as change
                else if(get<0>(prices) >= 3)
                    get<0>(prices) -= 3;  // Give back three $5 bills
                else 
                    return false;  // If neither condition is met, return false (change cannot be given)
            }
        }
        // If all customers can be given correct change, return true
        return true;
    }
};
