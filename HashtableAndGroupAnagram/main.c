#include <stdio.h>
#include "Hashtable.h"
int main() {
  Hashtable ht = CreateHashtable(10000);
  Readfile(ht, "words.txt");
  PrintHashtable(ht);
  DestroyHashtable(ht);
  return 0;
}
