#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi pos, neg;
    for(ll i=0; i<n; i++){
        ll x; cin >> x;
        if(x>=0) pos.push_back(x);
        else neg.push_back(x);
    }
    sort(pos.rbegin(),pos.rend());
    sort(neg.begin(),neg.end());
    ll res = 0;
    ll curr = 0;
    while(!pos.empty() || !neg.empty()){
        if(pos.empty()){
            res += abs(neg.back()-curr);
            curr = neg.back();
            neg.pop_back();
        }else if(neg.empty()){
            res += abs(pos.back()-curr);
            curr = pos.back();
            pos.pop_back();
        }else{
            ll pos1 = neg.back(), pos2 = pos.back();
            ll dist1 = abs(curr-pos1), dist2 = abs(curr-pos2);
            if(dist1<=dist2){
                res += dist1;
                curr = pos1;
                neg.pop_back();
            }else{
                res += dist2;
                curr = pos2;
                pos.pop_back();
            }
        }
    }
    cout << res;
}