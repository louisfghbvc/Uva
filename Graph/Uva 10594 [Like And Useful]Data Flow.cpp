#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

template<size_t N, typename C=int, typename W=int>
struct mcmf {
    struct edge {
        int v, v_id;
        C c; // flow
        W w; // weight
        edge (int v, int v_id, C c, W w) : v(v), v_id(v_id), c(c), w(w) {}
    };

    vector<edge> g[N];
    typename vector<edge>::iterator idx[N];
    int pre[N]; // parent
    W d[N], h[N]; // dis, prime-dual alg
    bool visit[N];
    int n;
    mcmf (int n) : n(n) {}

    void add_edge(int x, int y, C c, W w) {
        g[x].emplace_back(y, g[y].size(), c, w);
        g[y].emplace_back(x, g[x].size() - 1, 0, -w);
    }

    bool dijkstra(int s, int t) {
        priority_queue<pair<W, int>, vector<pair<W, int>>, greater<pair<W, int>>> pq; // weight, u
        fill(pre, pre+n, -1);
        fill(d, d+n, numeric_limits<W>::max() / 2);
        d[s] = 0;
        pq.push({d[s], s});
        while (pq.size()) {
            auto [dd, u] = pq.top(); pq.pop();
            if (d[u] != dd) continue;
            for (auto it = g[u].begin(); it != g[u].end(); ++it) {
                if (it->c && d[it->v] + h[it->v] > d[u] + it->w + h[u]) {
                    d[it->v] = d[u] + it->w + h[u] - h[it->v]; // note: w + h[u] - h[v] >= 0
                    pre[it->v] = u;
                    idx[it->v] = it;
                    pq.push({d[it->v], it->v});
                }
            }
        }
        return pre[t] >= 0;
    }

    pair<C, W> solve(int s, int t) { 
        pair<C, W> res;
        fill(h, h + n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += pre[i] < 0 ? 0 : d[i];
            C aug = numeric_limits<C>::max() / 2;
            for (int i = t; pre[i] != -1; i = pre[i]) {
                aug = min(aug, idx[i]->c);
            }
            W sum = 0; 
            for (int i = t; pre[i] != -1; i = pre[i]) {
                idx[i]->c -= aug;
                g[idx[i]->v][idx[i]->v_id].c += aug;
                sum += idx[i]->w * aug; 
            }
            res.first += aug;
            res.second += sum;
        }
        return res;
    }
};


void solve() {
    int n, m;
    while (cin >> n >> m) {
        mcmf<105, LL, LL> flow(n+1);
        vector<array<LL, 3>> edge(m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> edge[i][j];

        LL d, c; // data, capacity
        cin >> d >> c;
        for (auto &e: edge) {
            LL u = e[0], v = e[1], w = e[2]; 
            flow.add_edge(u, v, c, w);
            flow.add_edge(v, u, c, w);
        }
        flow.add_edge(0, 1, d, 0); // 0 is super-node
        auto res = flow.solve(0, n);
        if (res.first == d) {
            cout << res.second << "\n";
        }
        else {
            cout << "Impossible.\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    solve();
}
