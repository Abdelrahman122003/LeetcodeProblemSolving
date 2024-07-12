class Solution {
public:
    int findTheWinner(int n, int k) {
            int count = n, countK = k;
            queue<int>q;
            for(int i = 1; i <= n;i++){
                    q.push(i);
            }
            while(q.size() > 1){
                    countK = k;
                    if(q.size() < countK)
                            countK-=q.size();
                    while(countK--)
                            if(countK)
                                    q.push(q.front()), q.pop();
                    q.pop();
            }
            return q.front();
    }
};

// for example:

// peopel = 5
// k = 4

// first iteration
// 1 2 3 4 5 ---> 5 1 2 3 
// second iteration
// 5 1 2 3   ---> 2 1 5
// third iteration
// 2 1 5     ---> 1 5
// fourth iteration
// 1 5       ---> 1
