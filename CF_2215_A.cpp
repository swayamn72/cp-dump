#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k,p,q; cin >> n >> k >> p >> q;
        vi arr(n); for(auto &x : arr) cin >> x;

        vi pq(n), qp(n), best(n);
        for(ll i=0; i<n; i++){
            pq[i] = ((arr[i]%p)%q);
            qp[i] = ((arr[i]%q)%p);
            best[i] = min(pq[i],qp[i]);
        }
        ll sumbest = accumulate(best.begin(),best.end(),0LL);
        for(ll i=1; i<n; i++){
            pq[i] += pq[i-1];
            qp[i] += qp[i-1];
            best[i] += best[i-1];
        }
        // for(auto a : pq) cout << a << " ";
        // cout << "\n";
        // for(auto a : qp) cout << a << " ";
        // cout << "\n";
        // for(auto a : best) cout << a << " ";
        // cout << "\n";
        ll res = LLONG_MAX;
        
        for(ll i=k-1; i<n; i++){
            ll tominus = best[i] - (i-k>=0 ? best[i-k] : 0);
            ll toadd = pq[i] - (i-k>=0 ? pq[i-k] : 0);
            toadd = min(toadd, qp[i] - (i-k>=0 ? qp[i-k] : 0));
            res = min(res,sumbest - tominus + toadd);
        }
        cout << res << "\n";
    }
} 