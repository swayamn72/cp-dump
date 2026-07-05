#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
struct DSU{
	vi size,parent;
	ll components;
	DSU(ll n){
		parent.resize(n);
		size.resize(n,1);
		components = n;
		for(ll i=0; i<n; i++) parent[i] = i;
	}
	ll find(ll i){
		if(i==parent[i]){
			return i;
		}
		return parent[i] = find(parent[i]);
	}
	bool unite(ll i, ll j){
		ll rooti = find(i);
		ll rootj = find(j);
		if(rooti!=rootj){
			if(size[rooti]<size[rootj]){
				swap(rooti,rootj);
			}
			parent[rootj] = rooti;
			size[rooti]+=size[rootj];
			components--;
			return true;
		}
		return false;
	}
	bool same(ll i, ll j){
		return find(i)==find(j);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		ll n,m1,m2; cin >> n >> m1 >> m2;
		DSU g1(n), g2(n);
		vector<pair<ll,ll>> e;
		while(m1--){
			ll u,v; cin >> u >> v; u--; v--;
			e.push_back({u,v});
		}

		while(m2--){
			ll u,v; cin >> u >> v; u--; v--;
			g2.unite(u,v);
		}
		ll res = 0;
		for(auto [u,v] : e){
			if(!g2.same(u,v)){
				res++;
			}else{
				g1.unite(u,v);
			}
		}
		res += g1.components - g2.components;
		cout << res << "\n";
	}
}