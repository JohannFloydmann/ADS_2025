#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge &o) const { return w < o.w; }
};

struct DSU {
    vector<int> parent, rnk;

    DSU(int n) : parent(n+1), rnk(n+1,0) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        return (parent[x] == x ? x : parent[x] = find(parent[x]));
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a,b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    struct Segment { int l, r; long long c; };
    vector<Segment> seg(m);

    for (int i = 0; i < m; i++)
        cin >> seg[i].l >> seg[i].r >> seg[i].c;

    sort(seg.begin(), seg.end(), [](auto &a, auto &b){
        return a.c < b.c;
    });

    DSU dsu(n);
    DSU nxt(n);

    long long total = 0;

    for (auto &s : seg) {
        int l = s.l;
        int r = s.r;
        long long cost = s.c;

        int x = nxt.find(l);

        while (x < r) {
            if (dsu.unite(x, x + 1)) {
                total += cost;
            }

            nxt.parent[x] = x + 1;

            x = nxt.find(x);
        }
    }

    cout << total << "\n";
    return 0;
}