class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int n = nums2.size();
            map<int, int>m;
        stack<int>s;
            s.push(0);
        for(int i = 1;i < n;i++){
// If the current element is greater than the top element of the stack, pop the top element, and set the current element as the next greater element for the top of the stack.
                while(!s.empty()&&nums2[i] > nums2[s.top()])
                        m[nums2[s.top()]] = nums2[i], s.pop();
//when loop terminated so current ele not greater than top of stack -> push it
                s.push(i);
        }
        for(auto [k, v] : m)
                cout << k << " " << v << endl;
        vector<int>ans;
            for(auto k : nums1){
                    if(m.count(k))ans.push_back(m[k]);
                    else ans.push_back(-1);
            }
            return ans;
    }
};