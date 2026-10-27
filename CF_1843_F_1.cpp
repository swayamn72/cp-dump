#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> adj(n);
        vi arr(n+1);
        ll curr = 0;
        
        vi pref(n+1), maxpref(n+1), minpref(n+1);
        vi maxsub(n+1), minsub(n+1);

        pref[0] = 1; maxpref[0] = 1; minpref[0] = 0;
        maxsub[0] = 1; minsub[0] = 0;

        for(ll i=0; i<n; i++){
            char ch; cin >> ch;
            if(ch=='+'){
                ll v,x; cin >> v >> x; v--;
                curr++;
                adj[v].push_back(curr);
                pref[curr] = pref[v]+x;
                maxpref[curr] = max(maxpref[v],pref[curr]);
                minpref[curr] = min(minpref[v],pref[curr]);

                maxsub[curr] = max(maxsub[v],pref[curr]-minpref[curr]);
                minsub[curr] = min(minsub[v],pref[curr]-maxpref[curr]);
            }else{
                ll u,v,k; cin >> u >> v >> k; u--; v--;
                if(k==0){
                    cout << "YES" << "\n";
                    continue;
                }
                ll a = minsub[v], b = maxsub[v];
                if(k>=a && k<=b) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
        }
    }
}