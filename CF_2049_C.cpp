#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,x,y; cin >> n >> x >> y;
        vi res(n,0);
        if(abs(x-y)==1 || abs(x-y)==n-1){
            if(n%2==0){
                for(ll i=0; i<n; i++){
                    if(i&1)res[i] = 0;
                    else res[i]=1;
                }
            }else{
                res[n-1] = 2;
                for(ll i=0; i<n-1; i++){
                    if(i&1) res[i] = 1;
                    else res[i] = 0;
                }
            }
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        vector<vector<ll>> adj(n);
        adj[0].push_back(1); adj[0].push_back(n-1);
        adj[n-1].push_back(0); adj[n-1].push_back(n-2);
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
        for(ll i=1; i<n-1; i++){
            adj[i].push_back(i+1);
            adj[i].push_back(i-1);
        }
        while(true){
            bool change = false;

            for(ll i=0; i<n; i++){
                vector<bool> temp(4,false);
                for(auto a : adj[i]){
                    temp[res[a]] = true;
                }
                ll mex = 0;
                while(temp[mex])mex++;
                if(mex!=res[i]){
                    res[i] = mex;
                    change = true;
                }
            }

            if(!change) break;
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}