class Solution {
public:
    int countSeniors(vector<string>& details) {
        int counter = 0;
            for(auto k : details){
                    int age = stoi(k.substr(11, 2));
                    counter += (age > 60);
            }
            return counter;
    }
};