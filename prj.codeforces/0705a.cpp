#include <stdio.h>
#include <string.h>
int main() {
  int n;
  scanf("%d", &n);
  char a[] = "I hate it";
  char b[] = "I love it";
  char c[] = "I hate that ";
  char d[] = "I love that ";
  char r[10000] = "";

  for (int i = 1; i < n; i++) {
    if ((i) % 2) {
      strcat(r, "I hate that ");
    } else {
      strcat(r, "I love that ");
    }
  }
  if ((n - 1) % 2 == 0) {
    strcat(r, "I hate it");
  }
  if ((n - 1) % 2 != 0) {
    strcat(r, "I love it");
  }
  printf("%s", r);
  return 0;
}