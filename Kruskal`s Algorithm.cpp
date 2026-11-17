#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    char u, v;
    int weight;
};
char findParent(char parent[], char x) {
    if (parent[x - 'A'] == x)
        return x;

    return parent[x - 'A'] =
        findParent(parent, parent[x - 'A']);
}
void kruskal(vector<Edge> edges, int V) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    char parent[26];

    for (int i = 0; i < 26; i++)
        parent[i] = 'A' + i;

    vector<Edge> mst;
    int cost = 0;

    for (Edge e : edges) {

        char p1 = findParent(parent, e.u);
        char p2 = findParent(parent, e.v);

        if (p1 != p2) {

            mst.push_back(e);
            cost += e.weight;

            parent[p1 - 'A'] = p2;
        }
    }

    cout << "Minimum Spanning Tree:\n";

    for (Edge e : mst) {
        cout << e.u << " - " << e.v
             << " : " << e.weight << endl;
    }

    cout << "Minimum Cost = " << cost << endl;
}

int main() {

    int V = 4;

    vector<Edge> edges = {
        {'A', 'B', 2},
        {'B', 'C', 3},
        {'A', 'D', 1},
        {'C', 'D', 4},
        {'B', 'D', 5}
    };

    kruskal(edges, V);

    return 0;
}
