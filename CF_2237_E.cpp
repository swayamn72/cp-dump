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
        ll n; cin >> n;
        vi a(n); for(auto &x : a) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;

        vi cycle(n+1,0);
        vector<bool> vis(n+1,false);
        for(ll i=1; i<=n; i++){
            if(!vis[i]){
                int curr = i;
                vi path;
                while(!vis[curr]){
                    vis[curr] = true;
                    path.push_back(curr);
                    curr = a[curr-1];
                }
                for(auto x : path) cycle[x] = path.size();
            }
        }


        vector<bool> usedb(n+1,false);
        bool flag = true;
        queue<ll> q;
        for(ll i=0; i<n; i++){
            if(b[i]==-1) continue;
            if(usedb[b[i]]){
                flag = false;
                break;
            } 
            usedb[b[i]] = true;
            q.push(i);
        }   
        if(!flag){
            cout << "NO" << "\n";
            continue;
        }
        auto bfs = [&](){
            while(!q.empty()){
                ll index = q.front(); q.pop();
                ll aval = a[index];
                ll bval = b[index];
                if(b[aval-1]==-1){
                    ll val = a[bval-1];
                    if(usedb[val]){
                        flag = false;
                        break;
                    }
                    b[aval-1] = val;
                    usedb[val] = true;
                    q.push(aval-1);
                    }else{
                        if(b[aval-1]!=a[bval-1]){
                        flag = false;
                        break;
                    }
                }
            }
        };     
        bfs();
        if(!flag){
            cout << "NO" << "\n";
            continue;
        }
        vi next(n+1,1);
        for(ll i=0; i<n; i++){
            if(b[i]==-1){
                ll len = cycle[a[i]];
                ll v = next[len];
                while(v<=n && (usedb[v] || cycle[v]!=len)) v++;
                if(v>n){
                    flag = false;
                    break;
                }
                b[i] = v;
                usedb[v] = true;
                q.push(i);
                bfs();
            }
        }
        if(!flag){
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        for(auto x : b) cout << x << " ";
        cout << "\n";
    }
}