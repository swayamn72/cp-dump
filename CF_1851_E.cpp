#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
void dfs(ll node, vector<vector<ll>>&mixing, vector<ll>&arr, vector<bool>&vis){
    vis[node] = true;
    if(mixing[node].size()==0) return;
    ll newcost = 0;
    for(auto a : mixing[node]){
        if(!vis[a]) dfs(a,mixing,arr,vis);
        newcost += arr[a];
    }
    arr[node] = min(arr[node],newcost);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi p(k); for(auto &x : p) cin >> x;
        for(auto a : p) arr[a-1] = 0;
        vector<vector<ll>> mixing(n);
        for(ll i=0; i<n; i++){
            ll num; cin >> num;
            mixing[i].assign(num,0);
            for(ll j=0; j<num; j++){
                cin >> mixing[i][j];
                mixing[i][j]--;
            } 
        }
        vector<bool> vis(n,false);
        for(ll i=0; i<n; i++) dfs(i,mixing,arr,vis);
        for(auto a : arr) cout << a << " ";
        cout << "\n";
    }
}