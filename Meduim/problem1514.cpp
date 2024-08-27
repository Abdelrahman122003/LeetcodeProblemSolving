// Solving this problem using Dijkstra's algorithm
class Solution {
public:
    double dijkstra(int n, int start, int end, vector<vector<pair<int, double>>> &graph) {
        priority_queue<pair<double, int>> q;
        vector<double> probs(n + 1, 0.0);

        probs[start] = 1.0; // Initialize the start node with probability 1.0
        q.push({1.0, start});

        while (!q.empty()) {
            double currProb = q.top().first;
            int currNode = q.top().second;
            q.pop();
            if(currNode == end)
                    return currProb;

            for (auto &[nodeTo, probTo] : graph[currNode]) {
                if (currProb * probTo > probs[nodeTo]) {
                    probs[nodeTo] = currProb * probTo;
                    q.push({probs[nodeTo], nodeTo});
                }
            }
        }
        return (double)0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n + 1);

        // Build the graph using edges and their corresponding probabilities
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        double prob = dijkstra(n, start_node, end_node, graph);

        return prob;
    }
};
