#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
bool ask(ll i, ll j){
    cout << "? " << i << " " << j << endl;
    string s; cin >> s;
    if(s[0]=='Y') return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll res = 0;
    
    ll curr = 1;
    for(ll i=1; i<=n; i++){
        curr = max(curr,i);
        while(curr+1<=n && ask(i,curr+1)){
            curr++;
        }
        res += (curr-i);
    }
    cout << "! " << res << endl;

}