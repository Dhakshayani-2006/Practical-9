#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prim(vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();

    vector<bool> visited(n, false);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    int totalCost = 0;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (visited[vertex])
            continue;

        visited[vertex] = true;

        totalCost += weight;

        for (auto edge : graph[vertex])
        {
            int neighbour = edge.first;
            int edgeWeight = edge.second;

            if (!visited[neighbour])
            {
                pq.push({edgeWeight, neighbour});
            }
        }
    }

    cout << "Total Cost = " << totalCost << endl;
}

int main()
{
    vector<vector<pair<int, int>>> graph =
    {
        {{1, 2}, {2, 5}},       
        {{0, 2}, {3, 4}},       
        {{0, 5}, {3, 1}},       
        {{1, 4}, {2, 1}}        
    };

    prim(graph);

    return 0;
}
