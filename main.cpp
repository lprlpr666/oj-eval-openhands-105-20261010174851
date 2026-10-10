#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    int target = n - m; // remaining apples when at least m have been eaten
    double E[21] = {0.0};
    double prefix[21] = {0.0};
    for (int k = target + 1; k <= n; ++k) {
        double sumPrev = prefix[k - 1]; // sum of E[0..k-1]
        E[k] = 1.0 + sumPrev / k;
        prefix[k] = prefix[k - 1] + E[k];
    }
    cout.setf(ios::fixed);
    cout << setprecision(2) << E[n] << "\n";
    return 0;
}
