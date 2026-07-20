#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;

        vector<bool> pos(n,true); 
        vector<vector<ll>> v;
        for(ll i=0; i<m; i++){
            ll a,b,c; cin >> a >> b >> c;
            b--; c--;
            if(b==c){
                if(a==2) pos[b] = false;
            }else{
                v.push_back({a,b,c});
            }
        }
        vector<vector<ll>> adj(n);
        vi indegree(n);
        bool flag = true;
        for(auto a : v){
            ll op = a[0], x = a[1], y = a[2];
            if(pos[x]==pos[y]){
                if(pos[x]&&op==2){
                    flag = false;
                }else if(!pos[x] && op==1){
                    flag = false;
                }
                continue;
            }
            if(op==1){
                if(pos[x]){
                    adj[y].push_back(x);
                    indegree[x]++;
                }else{
                    adj[x].push_back(y);
                    indegree[y]++;
                }
            }else{
                if(pos[x]){
                    adj[x].push_back(y);
                    indegree[y]++;
                }else{
                    adj[y].push_back(x);
                    indegree[x]++;
                }
            }
        }
        if(!flag){
            cout << "NO" << "\n";
            continue;
        }
        vi res(n,LLONG_MAX);
        ll val = 1;
        queue<ll> q;
        for(ll i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            ll node = q.front(); q.pop();
            res[node] = val++;
            for(auto v : adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(val<=n){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        for(ll i=0; i<n; i++){
            if(!pos[i]) res[i] = -res[i];
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}