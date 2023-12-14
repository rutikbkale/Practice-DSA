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

    int binaryS(int val, int *arr) {
        int low=0,high=size-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==val){
                return mid;
            }
            else if(arr[mid]<val){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    int size = 7;
    int arr[] = {12,32,45,67,90,125,664};
    Searching *s = new Searching(size);
    int i = s->binaryS(67, arr);
    if (i >= 0) {
        cout << "Element found at index: " << i;
    } else {
        cout << "Element not found.";
    }
    return 0;
}
