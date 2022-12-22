// 744. Find Smallest Letter Greater Than Target
// Problem Link
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <stdio.h>

char nextGreatestLetter(char letters[], int lettersSize, char target) {

  int s = 0;
  int e = lettersSize - 1;

  while (s <= e) {
    int mid = (s + e) / 2;
    if (target < letters[mid])
      e = mid - 1;
    else
      s = mid + 1;
  }

  return letters[s % lettersSize];
}

int main() {
  char letters[] = {'c', 'f', 'j'};
  int letterSize = sizeof(letters) / sizeof(letters[0]);
  char target = 'a';

  printf("Smallest Letter Greater Than %c is %c\n", target,
         nextGreatestLetter(letters, letterSize, target));

  return 0;
}
