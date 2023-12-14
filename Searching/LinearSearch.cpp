 // WAP for linear searching.
 
 #include<iostream>
using namespace std;

class Searching {
public:
    int size;
    int *arr;

    Searching(int size) {
        this->size = size;
        arr = new int[size];
    }

    int linearS(int val, int *arr) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val)
                return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    int size = 7;
    int arr[] = {34, 56, 87, 45, 90, 21, 16};
    Searching *s = new Searching(size);
    int i = s->linearS(45, arr);
    if (i >= 0) {
        cout << "Element found at index: " << i;
    } else {
        cout << "Element not found.";
    }
    return 0;
}
