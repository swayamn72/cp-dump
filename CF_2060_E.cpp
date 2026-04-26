#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll t; cin >> t;
	while(t--){
	    ll n,m1,m2; cin >> n >> m1 >> m2;
	    set<pair<ll,ll>> s1, s2;
	    while(m1--){
	        ll u,v; cin >> u >> v;
	        if(v<u)swap(u,v);
	        s1.insert({u,v});
	    }
	    while(m2--){
	        ll u,v; cin >> u >> v;
	        if(v<u) swap(u,v);
	        s2.insert({u,v});
	    }
	    ll res = 0;
	    for(auto a : s1) if(s2.find(a)==s2.end()){
            res++; s2.insert(a);
        } 
	    for(auto a : s2) if(s1.find(a)==s1.end()){
            res++; s1.insert(a);
        }
	    cout << res << "\n";
	}
}
