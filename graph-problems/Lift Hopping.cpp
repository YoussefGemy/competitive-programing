#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MK(u,v) make_pair(u,v)
#define PB(v) push_back(v)
//#define e "\n"
#define S second
#define F first
void Gemy() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
const int N = 1e2 + 7, OO = 0x3f3f3f3f, MOD = 1e9 + 7;
const ll OOL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>>adj[N];
ll dis[N];
void dijkstra(int src) {
	memset(dis, OOL, sizeof dis);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push(MK(0, src));
	dis[src] = 0;
	while (!pq.empty()) {
		auto tp = pq.top(); pq.pop();
		if (dis[tp.S] != tp.F)continue;
		for (auto u : adj[tp.S]) {
			if (dis[u.S] > u.F + tp.F) {
				dis[u.S] = u.F + tp.F;
				pq.push(MK(dis[u.S], u.S));
			}
		}
	}
}

int main() {
	Gemy();
	int n, tar, f;
	while (cin >> n >> tar) {
		vector<int>times(n);
		for (int& time : times)cin >> time;
		cin.ignore();
		for (int e = 0; e < n; e++) {
			string s;
			getline(cin, s);
			stringstream ss(s);
			vector<int>floors;
			while (ss >> f) {
				floors.PB(f);
			}
			for (int i = 0; i < floors.size(); i++) {
				for (int j = 0; j < floors.size(); j++) {
					if (i == j)continue;
					int u = floors[i], v = floors[j];
					int w = (abs(u - v) * times[e]) + ((u == 0) ? 0 : 60);
					adj[u].push_back(MK(w, v));
				}
			}
		}
		dijkstra(0);
		if (dis[tar] == OOL)cout << "IMPOSSIBLE\n";
		else cout << dis[tar] << '\n';
		for (int i = 0; i < 100; i++)adj[i].clear();
	}
}