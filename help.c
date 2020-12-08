#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
struct edge
{
    int to;
    int cost;
};

int main()
{
    int n, s, f, tmp;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<vector<edge>> graph;
    vector<int> dist(n, INFINITY);
    vector<int> parent(n, -1);
    set<pair<int, int>> isMarked;
    graph.resize(n);
    dist[s] = 0;
    isMarked.insert(make_pair(0, s));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp > 0) {
                edge fmp;
                fmp.to = j;
                fmp.cost = --tmp;
                graph[i].push_back(fmp);
            }
        }
    }
    while (!isMarked.empty())
    {
        int v = isMarked.begin()->second;
        cout << v;
        isMarked.erase(make_pair(dist[v], v));
        for (auto u : graph[v]) {
            if (dist[u.to] > dist[v] + u.cost) {
                isMarked.erase(make_pair(dist[u.to], u.to));
                dist[u.to] = dist[v] + u.cost;
                isMarked.insert(make_pair(dist[u.to], u.to));
                parent[u.to] = v;
            }
        }
    }
    vector<int> ans;
    if (parent[f] != -1) {
        int cur = f;
        while (cur != s)
        {
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end());
    for (auto u : ans) {
        cout << u << " ";
    }
}