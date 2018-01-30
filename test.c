#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include "dist.h"

int main(void) {
  printf("%u\n", dist("test", 5, "test", 5, NULL));
  printf("%u\n", dist("testa", 6, "test", 5, NULL));
  printf("%u\n", dist("12345678", 9, "", 1, NULL));
  printf("%u\n", dist("", 1, "", 1, NULL));
}

