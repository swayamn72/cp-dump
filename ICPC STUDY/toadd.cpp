#include <vector>
using namespace std;
using ll = long long;
using vi = vector<ll>;
// --- ARITHMETIC PROGRESSION DIFFERENCE ARRAY CHEAT SHEET ---
// Goal: Add a linear sequence to range [L, R] in O(1) time.
// Every index j in [L, R] gets: constdiff[j] + j * slopediff[j]
//
// 1. Add flat 'val' (val, val, ..., val) on [L, R]:
//    constdiff[L] += val;       constdiff[R + 1] -= val;
//
// 2. Add increasing (1, 2, 3, ..., R - L + 1) on [L, R]:
//    Formula for index j is: j - (L - 1)
//    constdiff[L] -= (L - 1);   constdiff[R + 1] += (L - 1);
//    slopediff[L] += 1;         slopediff[R + 1] -= 1;
//
// 3. Add decreasing (R - L + 1, ..., 3, 2, 1) on [L, R]:
//    Formula for index j is: (R + 1) - j
//    constdiff[L] += (R + 1);   constdiff[R + 1] -= (R + 1);
//    slopediff[L] -= 1;         slopediff[R + 1] += 1;
// -----------------------------------------------------------

vi constdiff(n + 3, 0), slopediff(n + 3, 0);

// ... do your range updates here using (1), (2), or (3) ...

// Rebuild with prefix sums:
for (ll j = 1; j <= n; j++) {
    constdiff[j] += constdiff[j - 1];
    slopediff[j] += slopediff[j - 1];
}

// Final value at index j:
for (ll j = 1; j <= n; j++) {
    ll val = constdiff[j] + j * slopediff[j];
}