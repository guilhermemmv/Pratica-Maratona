#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int mede_distancias(vector<vector<int>>& g, int v, vector<int>& dist) {
    int n = g.size(), maior = 0, ind_maior = 0;
    vector<bool> visitado(n);
    queue<pii> fila;
    fila.push({v, 0});
    while(!fila.empty()) {
        int u = fila.front().first;
        dist[u] = fila.front().second;
        fila.pop();
        visitado[u] = true;
        for (int w : g[u]) {
            if (visitado[w] == false) fila.push({w, dist[u]+1});
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] > maior) {
            maior = dist[i];
            ind_maior = i;
        }
    }
    return ind_maior;
}

int main() {_
    int n, a, b, v, u, centro = 0, dist_centro = INT_MAX;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> dist_v(n), dist_u(n);
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    v = mede_distancias(g, 0, dist_v);
    u = mede_distancias(g, v, dist_v);
    mede_distancias(g, u, dist_u);
    for (int i = 0; i < n; i++) {
        if (max(dist_v[i], dist_u[i]) < dist_centro) {
            centro = i;
            dist_centro = max(dist_v[i], dist_u[i]);
        }
    }
    cout << centro+1 << endl;
    return 0;
}
