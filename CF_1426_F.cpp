#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7l;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    string s; cin >> s;
    ll res = 0;
    ll a = 0, ab = 0;
    ll ways = 1;
    for(auto x : s){
        ll nexta = a;
        ll nextab = ab;
        ll nextres = res;
        ll nextways = ways;
        if(x=='a'){
            nexta = (a+ways)%mod;
        }else if(x=='b'){
            nextab = (ab+a)%mod;
        }else if(x=='c'){
            nextres = (res+ab)%mod;
        }else{
            nexta = (a*3 + ways)%mod;
            nextab = (ab*3 + a)%mod;
            nextres = (res*3 + ab)%mod;
            nextways*=3; nextways%=mod;
        }
        ways = nextways;
        a = nexta;
        ab = nextab;
        res = nextres;
    }
    cout << res << "\n";
}