#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersect(vector<int>& a, vector<int>& b) {
    vector<int> result;

    sort(b.begin(), b.end());

    for (int num : a) {
        auto it = lower_bound(b.begin(), b.end(), num);

        if (it != b.end() && *it == num) {
            result.push_back(num);  
            b.erase(it);         
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> result = intersect(a, b);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
