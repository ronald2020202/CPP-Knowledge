#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>

using namespace std;

struct Node {
    int num;
    long long dist;
    friend bool operator<(const Node& n1, const Node& n2) {
        return n1.dist > n2.dist;
    }
};

struct Edge {
    int u;
    int v;
    long long l;
    long long w;
    friend bool operator<(const Edge& e1, const Edge& e2) {
        if (e1.l == e2.l) {
            return e1.w > e2.w;
        }
        else {
            return e1.l > e2.l;
        }
    }
};

void dijkstra(const vector<vector<Node>>& adj, int n, int start,
    vector<long long>& dist) {
    dist[start] = 0;
    priority_queue<Node> pq;
    for (int i = 0; i < n; i++) {
        pq.push({ i, dist[i] });
    }

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.num;
        long long curDist = current.dist;

        for (Node next : adj[u]) {
            int v = next.num;
            long long nextDist = dist[u] + next.dist;
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push({ v, nextDist });
            }
        }
    }
}

void dijkstra(const vector<vector<Node>>& adj, int start,
    vector<long long>& dist) {
    dist[start] = 0;
    priority_queue<Node> pq;
    // Only push the start node
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.num;
        long long curDist = current.dist;

        if (curDist > dist[u]) {
            // Don?t check neighbors if the popped node distance is already bigger
            continue;
        }
        for (Node next : adj[u]) {
            int v = next.num;
            long long nextDist = dist[u] + next.dist;
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push({ v, nextDist });
            }
        }
    }
}

void dijkstraFrom(const vector<vector<Node>>& adj, int start,
    vector<long long>& dist, vector<int>& from) {
    dist[start] = 0;
    from[start] = start;
    priority_queue<Node> pq;
    // Only push the start node
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.num;
        long long curDist = current.dist;

        if (curDist > dist[u]) {
            // Don?t check neighbors if the popped node distance is already bigger
            continue;
        }
        for (Node next : adj[u]) {
            int v = next.num;
            long long nextDist = dist[u] + next.dist;
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push({ v, nextDist });
                from[v] = u;
            }
        }
    }
}

long long uniformCostSearch(const vector<vector<Node>>& adj, int start, int end,
    vector<long long>& dist) {
    dist[start] = 0;
    priority_queue<Node> pq;
    // Only push the start node
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.num;
        long long curDist = current.dist;

        if (u == end) {
            return curDist;
        }

        if (curDist > dist[u]) {
            // Don?t check neighbors if the popped node distance is already bigger
            continue;
        }
        for (Node next : adj[u]) {
            int v = next.num;
            long long nextDist = dist[u] + next.dist;
            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push({ v, nextDist });
            }
        }
        
    }
    return LLONG_MAX;
}

int bellmanFord(const vector<vector<int>>& edges, int n, int start, int end) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++) {
        vector<int> temp = dist;
        for (vector<int> e : edges) {
            if (temp[e[0]] != INT_MAX) {
                temp[e[1]] = min(temp[e[1]], temp[e[0]] + e[2]);
            }
            if (temp[e[1]] != INT_MAX) {
                temp[e[0]] = min(temp[e[0]], temp[e[1]] + e[2]);
            }
        }
        dist = temp;
    }
    return dist[end] == INT_MAX ? -1 : dist[end];
}

int main() {

    int n, m; cin >> n >> m;

    long long totalCost = 0;

    vector<vector<Node>> adj(n+1);
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        long long l, c;
        cin >> u >> v >> l >> c;
        adj[u].push_back({ v, l });
        adj[v].push_back({ u, l });
        edges.push_back({ u, v, l, c });
        totalCost += c;
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; i++) {
        long long length = edges[i].l;
        int u = edges[i].u;
        int v = edges[i].v;
        for(int j = 0; j < adj[u].size(); j++) {
            if (adj[u][j].num == v && adj[u][j].dist == length) {
                adj[u].erase(adj[u].begin() + j);
                break;
            }
        }
        for (int j = 0; j < adj[v].size(); j++) {
            if (adj[v][j].num == u && adj[v][j].dist == length) {
                adj[v].erase(adj[v].begin() + j);
                break;
            }
        }
        vector<long long> dist(n+1, LLONG_MAX);
        long long shortest = uniformCostSearch(adj, edges[i].u, edges[i].v, dist);
        if (length >= shortest) {
            totalCost -= edges[i].w;
        }
        else {
            adj[u].push_back({ v, length });
            adj[v].push_back({ u, length });
        }
    }

    cout << totalCost << endl;
    
    return 0;
}