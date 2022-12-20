#include <stdio.h>

int binary_search(int arr[], int len, int target){
    int s = 0;
    int e = len - 1;

    while(s <= e){
        int m = (s + e) / 2;

        if(target < arr[m]){
            e = m - 1;  
        }else if(target > arr[m]){
            s = m + 1;
        }else if(target == arr[m]){
            return m;
        }
       
    }
     return -1;
}
int main() {

  int arr[] = { 1, 2, 4, 6, 12, 18 };
  int target = 15;
  int len = sizeof(arr)/sizeof(arr[0]);

printf("The Elemet Found at index: %d\n",binary_search(arr, len, target));
}

