#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solve (int n, vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());

    long long alex_sum = 0, bob_sum = 0;
    int alex_last = -1, bob_last = -1;
    
    int a_ptr = 0, b_ptr = 0;
    vector<bool> taken(n, false);

    while (true) {
        bool moved = false;

        while (a_ptr < n) {
            if (!taken[a_ptr] && arr[a_ptr] != alex_last) {
                alex_sum += arr[a_ptr];
                alex_last = arr[a_ptr];
                taken[a_ptr] = true;
                moved = true;
                break;
            }
            a_ptr++;
        }

        while (b_ptr < n) {
            if (!taken[b_ptr] && arr[b_ptr] != bob_last) {
                bob_sum += arr[b_ptr];
                bob_last = arr[b_ptr];
                taken[b_ptr] = true;
                moved = true;
                break;
            }
            b_ptr++;
        }

        if (!moved) break;
    }

    return (alex_sum > bob_sum) ? "Alex" : "Bob";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        string result = solve(n, arr);
        cout << result << "\n";
    }
    
    return 0;
}