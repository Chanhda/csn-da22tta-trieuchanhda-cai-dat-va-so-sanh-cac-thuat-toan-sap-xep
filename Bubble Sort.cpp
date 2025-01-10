#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  
using namespace std;

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

    bubbleSort(arr);

    cout << "Mang sau khi sap xep: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
