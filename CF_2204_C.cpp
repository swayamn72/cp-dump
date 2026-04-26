#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll a,b,c,m; cin >> a >> b >> c >> m;
        
        ll singlea = (m/a)*6;
        ll singleb = (m/b)*6;
        ll singlec = (m/c)*6;

        ll doubleab = lcm(a,b) * 3;
        ll doublebc = lcm(b,c) * 3;
        ll doubleac = lcm(a,c) * 3;

        ll tripleabc = lcm(a,b); tripleabc = lcm(tripleabc,c);
        tripleabc *= 2;

        ll resa = singlea - doubleab - doubleac + tripleabc;
        cout << resa << "\n";
    }
}