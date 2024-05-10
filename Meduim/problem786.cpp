class Solution {
public:
//         time compelexity n^2
    // vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    //     vector<tuple<float, int , int>>v;
    //         for(int i = 0 ;i < arr.size();i++){
    //                 for(int j = i+1 ;j < arr.size();j++)
    //                         v.push_back({(float)arr[i]/arr[j], arr[i], arr[j]});
    //         }
    //         sort(v.begin(), v.end());
    //         auto[c, a ,b] = v[k-1];
    //         vector<int>ans{a, b};
    //         return ans;
    // }
//     another apporach with compelexity nlog(n) + klog(n) --> (n+k)log(n)
   vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
   {
           priority_queue<tuple<float, int , int>>q;
           for (int i = 0;i < arr.size();i++)
                   q.push({-1.0* arr[i] / arr.back(), i , arr.size()-1});
           k--;
           while(k--){
                   auto [res, i, j] = q.top();
                   q.pop();
                   j--;
                   q.push({-1.0 * arr[i] / arr[j], i , j});
           }
           auto[res, i, j] = q.top();
           
           
           return {arr[i], arr[j]};
   }
};
 // [1,2,3,5], k = 3
// => 