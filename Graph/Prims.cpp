#include <bits/stdc++.h>
using namespace std;

typedef struct prims {
    int key, parent, index;
} vertex;

typedef vector<pair<int, int>> vii; // Adjacency list type: pair<neighbor, weight>

struct cmp {
    bool operator()(const vertex &a, const vertex &b) {
        return a.key > b.key; // Min-heap comparison
    }
};

vector<vertex> prims(vector<vii> &g, int src, int v) {
    vector<vertex> res(v);
    vector<bool> inMST(v, false); // Tracks vertices already in the MST

    for (int i = 0; i < v; i++) {
        res[i].key = INT_MAX;
        res[i].parent = -1;
        res[i].index = i;
    }

    res[src].key = 0; // Start vertex with key 0

    // Priority queue for selecting minimum weight edge
    priority_queue<vertex, vector<vertex>, cmp> pq;
    pq.push(res[src]);

    while (!pq.empty()) {
        vertex current = pq.top();
        pq.pop();

        int u = current.index;

        if (inMST[u]) continue; // Skip if already in MST
        inMST[u] = true;

        // Explore neighbors
        for (auto &neighbor : g[u]) {
            int v = neighbor.first;   // Neighbor node
            int weight = neighbor.second; // Edge weight

            if (!inMST[v] && weight < res[v].key) {
                res[v].key = weight;
                res[v].parent = u;
                pq.push(res[v]); // Push updated vertex into priority queue
            }
        }
    }

    return res;
}

int main(void) {
    int n, e;
    cin >> n >> e;
    int s, d, w;
    vector<vii> g(n);

    // Input graph as adjacency list
    for (int i = 0; i < e; i++) {
        cin >> s >> d >> w;
        g[s].push_back(make_pair(d, w));
        g[d].push_back(make_pair(s, w));
    }

    vector<vertex> res = prims(g, 0, n); // Run Prim's algorithm from node 0

    // Print the MST edges
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < n; i++) {
        if (res[i].parent != -1) { // Exclude the source node
            cout << "Edge: " << res[i].parent << " - " << i << ", Weight: " << res[i].key << endl;
        }
    }

    return 0;
}
