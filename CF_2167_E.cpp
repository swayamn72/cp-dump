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
        ll n,k,x; cin >> n >> k >> x;
        vi arr(n); for(auto &x : arr) cin >> x;
        ll minv = *min_element(arr.begin(),arr.end());
        ll maxv = *max_element(arr.begin(),arr.end());
        if(minv!=0) arr.push_back(-minv);
        if(maxv!=x) arr.push_back(x + x - maxv);

        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());

        if(arr.size()==1){
            cout << 1 << "\n";
            cout << 0 << "\n";
            continue;
        }

        priority_queue<pair<ll,ll>> pq;
        for(ll i=1; i<arr.size(); i++){
            pq.push({arr[i]-arr[i-1], arr[i-1]});
        }
        set<ll> res;
        while(k--){
            if(pq.empty()){
                k++;
                break;
            }
            auto [diff, u] = pq.top(); pq.pop();
            ll v = u + diff;
            ll mid = u+diff/2;
            res.insert(u+diff/2);
            if(mid>u && mid<v){
                if(u>=0) pq.push({mid-u, u});
                if(v<=x) pq.push({v-mid,mid});
            }
        }
        ll index = -1;
        while(k>0){
            index++;
            if(res.count(index)){
                continue;
            }else{
                k--;
                res.insert(index);
            }
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}