#include<bits/stdc++.h>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int HR(vector<int>&arr, int m, int n, int x) {
    if (m == n) {
        return arr[m];
    }
    return (HR(arr, m, n + 1, x)) * x + arr[n];
}

void evaluate(vector<pair<int, int>>& store) {
    for (int i = 10; i < 1e4; i += 1000) {
        vector<int>arr(i);
        generate_n(arr.begin(),i,rand);
        int t = 0;
        int avg = 0;
        for (int m = 0; m < 10; m++) {
            auto start = high_resolution_clock::now();
            HR(arr, i, 0, 10000);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 10;
        store.push_back({ i, avg });
    }
}

int main() {
    vector<pair<int, int>> store;
    evaluate(store);
    cout << "Number of Inputs" << " " << "Time" << endl;
    for (auto i : store) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
