#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define e "\n"
void Gemy() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
const int N = 2e5 + 10, OO = 0x3f3f3f3f;
vector<pair<ll, int>>vi[N];
ll dis[N], n, m;

void dijkstra() {
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater < pair<ll, int>>>pq;
	for (int i = 1; i <= n; i++) pq.push({ dis[i],i });
	while (!pq.empty()) {
		auto q = pq.top();
		pq.pop();
		ll F = q.first;
		int S = q.second;
		if (F != dis[S])continue;
		for (auto node : vi[S]) {
			if (dis[node.second] > F + node.first) {
				dis[node.second] = node.first + F;
				pq.push({ dis[node.second] ,node.second });
			}
		}
	}
}
int main() {
	Gemy();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		vi[u].push_back({ 2 * c,v });
		vi[v].push_back({ 2 * c,u });
	}
	for (int i = 1; i <= n; i++) cin >> dis[i];
	dijkstra();
	for (int i = 1; i <= n; i++)cout << dis[i] << " \n"[i == n];
}