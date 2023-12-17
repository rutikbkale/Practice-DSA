// WAP for insertion sorting.

#include <iostream>
using namespace std;

class Sorting
{
public:
    int size;
    Sorting(int size)
    {
        this->size = size;
    }

    void displayArr(int *arr)
    {
        cout << "Array Elements : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertionSort(int *arr)
    {
        for (int i = 1; i < size; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

int main(int argc, char const *argv[])
{
    int size = 10;
    int arr[] = {54, 76, 34, 56, 87, 9, 12, 31, 45, 29};
    // int arr[] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10};
    Sorting *obj = new Sorting(size);
    cout << "Before sorting : \n";
    obj->displayArr(arr);
    obj->insertionSort(arr);
    cout << "After sorting : \n";
    obj->displayArr(arr);
    delete obj;
    return 0;
}
