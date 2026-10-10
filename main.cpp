#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    int target = n - m; // remaining apples when at least m have been eaten
    vector<double> E(n + 1, 0.0);
    vector<double> prefix(n + 1, 0.0); // prefix sum of E
    // E[k] = 0 for k <= target
    for (int k = target + 1; k <= n; ++k) {
        double sumPrev = prefix[k - 1]; // sum of E[0..k-1]
        E[k] = 1.0 + sumPrev / k;
        prefix[k] = prefix[k - 1] + E[k];
    }
    cout.setf(ios::fixed);
    cout << setprecision(2) << E[n] << "\n";
    return 0;
}
