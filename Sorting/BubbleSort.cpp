// WAP for bubble sorting.

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

    void bubbleSort(int *arr)
    {
        int isSorted =0,count=1;
        for (int i = 0; i < size - 1; i++)  // Number of passes
        {
            isSorted=1;
            for (int j = 0; j < size - 1 - i; j++)  // Number of comparisions in each pass
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    isSorted=0;
                }
            }
            if(isSorted){
                    cout<<"It take "<<count<<" passes to sort the array.\n";
                    return;
                }
            count++;
        }
    }
};

int main(int argc, char const *argv[])
{
    int size = 10;
    int arr[] = {54,76,34,56,87,9,12,31,45,29};
    //int arr[] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10};
    Sorting *obj = new Sorting(size);
    cout<<"Before sorting : \n";
    obj->displayArr(arr);
    obj->bubbleSort(arr);
    cout<<"After sorting : \n";
    obj->displayArr(arr);
    return 0;
}
