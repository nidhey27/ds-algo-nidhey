#include <stdio.h>

int ceiling(int nums[], int target, int n) {
  int s = 0;
  int e = n - 1;

  while (s <= e) {
    int m = (s + e) / 2;
    if (target < nums[m]) {
      e = m - 1;
    } else if (target > nums[m]) {
      s = m + 1;
    } else {
      return m;
    }
  }

  return s;
}

int floor_num(int nums[], int target, int n) {
  int s = 0;
  int e = n - 1;

  while (s <= e) {
    int m = (s + e) / 2;
    if (target < nums[m]) {
      e = m - 1;
    } else if (target > nums[m]) {
      s = m + 1;
    } else {
      return m;
    }
  }

  return e;
}

int main() {

  int nums[] = {10, 20, 25, 60, 99, 102, 276};
  int len = sizeof(nums) / sizeof(nums[0]);
  int target = 22;

    printf("Ceil of %d is %d\n", target, nums[ceiling(nums, target, len)]);
    printf("Floor of %d is %d\n", target, nums[floor_num(nums, target, len)]);

  return 0;
}