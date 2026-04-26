#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n; vi arr(n); for(ll i=0; i<n; i++) cin >> arr[i];
    vi indegree(n);
    vector<vector<ll>> adj(n);
    for(ll i=0; i<n-1; i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    ll root = -1;
    for(ll i=0; i<n; i++){
        if(indegree[i]==0){
            root = i;
            break;
        }
    }
    vector<bool> vis(n, false);
    queue<ll> q;
    q.push(root);
    set<ll> s;
    ll val = q.size();
    set<ll> tempset;
    while(!q.empty()){
        ll node = q.front();
        q.pop(); val--; 
        for(auto a : adj[node]){
            q.push(a); tempset.insert(a);
        }
        if(val==0){
            val = q.size();
            for(auto a : tempset){
                if(s.find(a)!=s.end()){
                    vis[a] = true;
                }
            }
            for(auto a : tempset) s.insert(a);
            tempset.clear();
        }
    }
    for(auto a : vis){
        if(a) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}