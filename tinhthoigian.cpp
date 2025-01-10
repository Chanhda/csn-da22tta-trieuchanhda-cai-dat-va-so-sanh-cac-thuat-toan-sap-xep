#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> sizes = {20000, 50000, 100000};
    srand(time(0));

    for (int n : sizes) {
        cout << "So luong phan tu: " << n << endl;
        vector<int> arr(n);
        for (int& num : arr) num = rand() ;

        // Bubble Sort
        vector<int> bubbleArr = arr;
        auto start = high_resolution_clock::now();
        bubbleSort(bubbleArr);
        auto end = high_resolution_clock::now();
        cout << "Bubble Sort: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;

        // Heap Sort
        vector<int> heapArr = arr;
        start = high_resolution_clock::now();
        heapSort(heapArr);
        end = high_resolution_clock::now();
        cout << "Heap Sort: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;

        // Quick Sort
        vector<int> quickArr = arr;
        start = high_resolution_clock::now();
        quickSort(quickArr, 0, quickArr.size() - 1);
        end = high_resolution_clock::now();
        cout << "Quick Sort: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;

        // Merge Sort
        vector<int> mergeArr = arr;
        start = high_resolution_clock::now();
        mergeSort(mergeArr, 0, mergeArr.size() - 1);
        end = high_resolution_clock::now();
        cout << "Merge Sort: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;

        cout << endl;
    }

    return 0;
}
