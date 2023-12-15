#include <iostream>
using namespace std;

class Sorting {
public:
    int size;

    Sorting(int size) {
        this->size = size;
    }

    void displayArr(int *arr) {
        cout << "Array Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void selectionSort(int *arr) {
        int i, j, minIndex, temp;
        for (i = 0; i < size - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
};

int main() {
    int size = 10;
    int arr[] = {54, 76, 34, 56, 87, 9, 12, 31, 45, 29};
    Sorting *obj = new Sorting(size);

    cout << "Before sorting:\n";
    obj->displayArr(arr);

    obj->selectionSort(arr);

    cout << "After sorting:\n";
    obj->displayArr(arr);

    delete obj;
    return 0;
}
