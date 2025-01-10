#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double solve(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return solve(nums2, nums1); 
    }
    
    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;
    
    while (low <= high) {
        int patX = (low + high) / 2;
        int patY = (x + y + 1) / 2 - patX;
        
        int maxX = (patX == 0) ? INT_MIN : nums1[patX - 1];
        int minX = (patX == x) ? INT_MAX : nums1[patX];
        
        int maxY = (patY == 0) ? INT_MIN : nums2[patY - 1];
        int minY = (patY == y) ? INT_MAX : nums2[patY];
        
        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
            } else {
                return (double)max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = patX - 1; 
        } else {
            low = patX + 1; 
        }
    }
    
    throw invalid_argument("Input arrays are not valid.");
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> M(m), N(n);
    
    for (int i = 0; i < m; ++i) {
        cin >> M[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> N[i];
    }
    
    double median = solve(M, N);
    printf("%.5f\n", median);
    return 0;
}
