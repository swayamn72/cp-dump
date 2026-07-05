#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    string s; cin >> s;
    deque<ll> dq;
    bool reversed = false;
    for(ll i=1; i<=n; i++){
        if(reversed) dq.push_back(i);
        else dq.push_front(i);
        char ch = s[i-1];
        if(ch=='o') reversed = !reversed;
    }
    vi res;
    for(auto a : dq) res.push_back(a);
    if(!reversed) reverse(res.begin(),res.end());
    for(auto a : res) cout << a << " ";
    cout << "\n";
}