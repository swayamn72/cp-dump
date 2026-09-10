#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
void randomPermutation(int n) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(v.begin(), v.end(), rng);

    for (int x : v)
        cout << x << " ";
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << rng() % 2 << " ";

    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    // randomPermutation(10);
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        string s; cin >> s;

        if(s[0]=='1' || s[n-1]=='1'){
            cout << -1 << "\n";
            continue;
        }
        bool flag = true;
        for(ll i=0; i<n; i++){
            if(arr[i]==1 && s[i]=='1'){
                flag = false;
                break;
            }else if(arr[i]==n && s[i]=='1'){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }

        vi prefmax(n), prefmin(n), suffmax(n), suffmin(n);
        prefmax[0] = arr[0]; for(ll i=1; i<n; i++) prefmax[i] = max(arr[i],prefmax[i-1]);
        suffmax[n-1] = arr[n-1]; for(ll i=n-2; i>=0; i--) suffmax[i] = max(arr[i],suffmax[i+1]);
        prefmin[0] = arr[0]; for(ll i=1; i<n; i++) prefmin[i] = min(arr[i],prefmin[i-1]);
        suffmin[n-1] = arr[n-1]; for(ll i=n-2; i>=0; i--) suffmin[i] = min(arr[i],suffmin[i+1]);
        vi pos(n+1); for(ll i=0; i<n; i++) pos[arr[i]] = i;

        vector<pair<ll,ll>> res;
        for(ll i=1; i<n-1; i++){
            if(s[i]=='1'){
                if(arr[i]==prefmin[i]){
                    ll left = prefmax[i-1];
                    left = pos[left];
                    ll right = suffmin[i+1];
                    right = pos[right];
                    
                    res.push_back({left,right});

                    ll maxv = max(arr[left],arr[right]);
                    ll minv = min(arr[left],arr[right]);
                    for(ll j=left+1; j<right; j++){
                        if(arr[j]>minv && arr[j]<maxv) s[j] = '0';
                    }
                }else if(arr[i]==prefmax[i]){
                    ll left = prefmin[i-1];
                    left = pos[left];
                    ll right = suffmax[i+1];
                    right = pos[right];

                    res.push_back({left,right});

                    ll maxv = max(arr[left],arr[right]);
                    ll minv = min(arr[left],arr[right]);
                    for(ll j=left+1; j<right; j++){
                        if(arr[j]>minv && arr[j]<maxv) s[j] = '0';
                    }
                }else if(arr[i]==suffmin[i]){
                    ll left = prefmin[i-1];
                    left = pos[left];
                    ll right = suffmax[i+1];
                    right = pos[right];

                    res.push_back({left,right});

                    ll maxv = max(arr[left],arr[right]);
                    ll minv = min(arr[left],arr[right]);
                    for(ll j=left+1; j<right; j++){
                        if(arr[j]>minv && arr[j]<maxv) s[j] = '0';
                    }
                }else{
                    ll left = prefmax[i-1];
                    left = pos[left];
                    ll right = suffmin[i+1];
                    right = pos[right];
                    
                    res.push_back({left,right});

                    ll maxv = max(arr[left],arr[right]);
                    ll minv = min(arr[left],arr[right]);
                    for(ll j=left+1; j<right; j++){
                        if(arr[j]>minv && arr[j]<maxv) s[j] = '0';
                    }
                }
            }
        }
        cout << res.size() << "\n";
        for(auto [a,b] : res) cout << a+1 << " " << b+1 << "\n";
    }
} 