class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
            vector<int>ans(tem.size(), 0);
            stack<int>st;
            st.push(0);
            for(int i = 1;i < tem.size();i++){
                    while(!st.empty()&&tem[i] > tem[st.top()])
                            ans[st.top()] = i - st.top(), st.pop();
                    st.push(i);
           }
            return ans;
    }
};