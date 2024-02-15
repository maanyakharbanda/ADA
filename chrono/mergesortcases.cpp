#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
void merge(int arr[], int low, int mid, int high) {
    int temp[10];
    int index = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp[index++] = arr[left++];
        }
        else {
            temp[index++] = arr[right++];
        }
    }
    while (left <= mid) {
        temp[index++] = arr[left++];
    }
    while (right <= high) {
        temp[index++] = arr[right++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergesort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    else {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    // best case
    int arrb[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int low = 0;
    int high = 9; // index of the last element
    auto start = high_resolution_clock::now();
    mergesort(arrb, low, high);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for the best case: " << duration.count() << " microseconds" << endl;

    // average case
    int arra[10] = {2, 4, 6, 5, 10, 8, 1, 7, 9, 3};
    start = high_resolution_clock::now();
    mergesort(arra, low, high);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for the average case: " << duration.count() << " microseconds" << endl;

    // worst case
    int arrw[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    start = high_resolution_clock::now();
    mergesort(arrw, low, high);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken for the worst case: " << duration.count() << " microseconds" << endl;

    return 0;
}
