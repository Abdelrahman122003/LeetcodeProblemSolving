#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>indcies(n), ans;
        stack<int> stack;
            for(int i = 0;i < n;i++)
                    indcies[i] = i;
// first step we will sort robots asc 
// for example:
// indcies   ---> [0,1,2,3,4]
// positions ---> [5,4,3,2,1]
// after sorting
// indcies   ---> [4,3,2,1,0]

// 1)The std::sort function is used to sort elements in a range.
// indices.begin() and indices.end() specify the range of elements in the indices vector to be sorted. The range is [indices.begin(), indices.end()), which means from the beginning to the end of the vector.
            
//2)Lambda Function as Comparator:

// [&] captures all external variables (in this case, positions) by reference.
// (int lhs, int rhs) specifies that the lambda function takes two integers as parameters (lhs and rhs), which are indices from the indices vector.
// { return positions[lhs] < positions[rhs]; } is the body of the lambda function. 
// It compares the values at the positions specified by lhs and rhs in the positions vector and returns true if the value at positions[lhs] is less than the value at positions[rhs].
            sort(indcies.begin(), indcies.end(),
                [&](int i, int j) {return positions[i] < positions[j];});
        
         for(auto index : indcies)
         {
                 if(directions[index] == 'R')
                         stack.push(index);
                 else{
                         while (!stack.empty() && healths[index] > 0) {
                                 int top = stack.top();
                                 stack.pop();
                                 if (healths[top] == healths[index]) {
                                        healths[index] = 0;
                                        healths[top] = 0;
                                    } 
                                 else if (healths[top] > healths[index])
                                       healths[index] = 0, healths[top]--, stack.push(top);

                                 else 
                                       healths[index]--,  healths[top] = 0;
                         }
                 }
         }
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};




