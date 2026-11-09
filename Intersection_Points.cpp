#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Fenwick{
    ll n; vi bit;
    Fenwick(ll n){
        this->n = n;
        bit.resize(n+1,0);
    }
    void add(ll i, ll d){
        for(; i<=n; i+=i&-i) bit[i]+=d;
    }
    ll query(ll i){
        ll sum = 0;
        for(; i>0; i-=i&-i) sum += bit[i];
        return sum;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vi> v;
        for(ll i=0; i<n; i++){
            ll x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
            if(y1==y2){
                if(x1>x2) swap(x1,x2);
                v.push_back({y1,2,x1,x2});
            }else{
                if(y1>y2) swap(y1,y2);
                v.push_back({y1,1,x1,1});
                v.push_back({y2,3,x1,1});
            }
        }
        sort(v.begin(),v.end());
        ll offset = 1e6+5;
        Fenwick ft(2*offset+5);
        ll res = 0;
        for(auto e : v){
            ll type = e[1];
            ll x1 = e[2]+offset;
            ll x2 = e[3]+offset;
            if(type==1){
                ft.add(x1,1);
            }else if(type==2){
                res += ft.query(x2) - ft.query(x1-1);
            }else if(type==3){
                ft.add(x1, -1);
            }
        }
        cout << res;
    }
}