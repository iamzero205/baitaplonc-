#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int first = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return first;
}

int findLast(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int last = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last = mid;
            left = mid + 1; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return last;
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    int start = findFirst(arr, target);
    int end = findLast(arr, target);

    if (start == -1 || end == -1) {
        cout << "-1 -1" << endl;
    } else {
        cout << start << " " << end << endl;
    }

    return 0;
}
