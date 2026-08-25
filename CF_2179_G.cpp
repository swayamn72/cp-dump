#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto ask = [](ll i, ll j)->ll{
        cout << "? " << i << " " << j << endl;
        ll d; cin >> d;
        return d;
    };
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll,vi> mp;
        for(ll i=2; i<=n*n; i++){
            ll d = ask(1,i);
            mp[d].push_back(i);
        }
        
        ll one = mp.rbegin()->second[0];
        vi d1map(n*n+1,0);
        ll opp = one;
        for(ll i=1; i<=n*n; i++){
            if(i==one) continue;
            d1map[i] = ask(one,i);
            if(d1map[i]>d1map[opp]) opp = i;
        }
        ll neighbour = -1;
        for(ll i=1; i<=n*n; i++){
            if(d1map[i]==1){
                neighbour = i;
                break;
            }
        }
        ll two = -1;
        for(ll i=1; i<=n*n; i++){
            if(d1map[i]==n-1){
                if(ask(neighbour,i)==n){
                    two = i;
                    break;
                }
            }
        }

        vector<vi> res(n,vi(n));
        res[0][0] = one; res[0][n-1] = two;

        for(ll i=1; i<=n*n; i++){
            if(i==one || i==two) continue;
            ll d1 = d1map[i];
            ll d2 = ask(two,i);

            ll sum = d1+d2;
            sum -= (n-1);
            ll row = sum/2;
            ll col = d1 - row;
            res[row][col] = i;

        }
        cout << "!" << "\n";
        for(auto &a : res){
            for(auto &b : a){
                cout << b << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
} 