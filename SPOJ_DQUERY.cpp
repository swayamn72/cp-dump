#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
vi freq(1e6 + 5, 0);
ll res = 0; ll blocksize;
bool compare(const vector<ll>& a, const vector<ll>& b) {
    ll blocka = a[0]/blocksize;
    ll blockb = b[0]/blocksize;
    if(blocka!=blockb)return blocka < blockb;
    if(blocka%2==0)return a[1]<b[1];
    return a[1]>b[1];
}
void add(ll val) {
    if(freq[val]++ == 0)
        res++;
}
void subtract(ll val) {
    if(freq[val]-- == 1)
        res--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vi arr(n); for(auto &x : arr) cin >> x;
    ll q; cin >> q;
    blocksize = max(1LL, (ll)sqrt(n));
    vector<vector<ll>> queries;
    for(ll i=0; i<q; i++){
        ll l, r; cin >> l >> r;
        l--; r--;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end(), compare);
    vi ans(q); ll curl = 0; ll curr = -1;
    for(auto &a : queries){
        ll l = a[0], r = a[1];
        while(curl>l) {
            curl--;
            add(arr[curl]);
        }
        while(curr<r) {
            curr++;
            add(arr[curr]);
        }
        while(curl<l) {
            subtract(arr[curl]);
            curl++;
        }
        while(curr>r) {
            subtract(arr[curr]);
            curr--;
        }
        ans[a[2]] = res;
    }

    for(auto x : ans) cout << x << '\n';
}