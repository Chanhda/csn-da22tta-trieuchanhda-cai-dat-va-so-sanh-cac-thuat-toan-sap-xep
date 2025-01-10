#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
using namespace std;

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

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> arr(n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 2000; 
    }

    cout << "Mang truoc khi sap xep: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Mang sau khi sap xep: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
