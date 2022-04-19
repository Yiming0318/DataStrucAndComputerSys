#include <stdio.h>
#include "Hashtable.h"
int main() {
  Hashtable ht = CreateHashtable(10);
  Readfile(ht, "simplewords.txt");
  PrintHashtable(ht);
  DestroyHashtable(ht);
  return 0;
}

