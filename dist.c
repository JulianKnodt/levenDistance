#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "dist.h"
#define max(a, b) a > b ? a : b

typedef unsigned int uint;
enum {bits_in_byte = 8};

static void swap(void** a, void** b) {
  void* temp = *a;
  *a = *b;
  *b = temp;
}

static uint min(uint a, uint b) {
  return a > b ? b : a;
}

uint dist(char* a, size_t sizeA, char* b, size_t sizeB, distance* dist) {
  if (!dist) dist = (distance*)malloc(sizeof(distance));
  distance failedMalloc = {0, 0, 0};
  if (!dist) dist = &failedMalloc;
  uint* aVec = (uint*)calloc(max(sizeA, sizeB), sizeof(uint));
  uint* bVec = (uint*)calloc(max(sizeA, sizeB), sizeof(uint));
  uint i = 0;
  uint j = 0;
  uint delCost; uint insCost; uint subCost; uint m;
  for (i = 0; i < sizeA; i ++) aVec[i] = i;
  for (i = 0; i < sizeB-1; i ++) {
    bVec[0] = i + 1;
    for (j = 0; j < sizeA -1; j ++) {
      delCost = aVec[j+1] + 1;
      insCost = bVec[j] + 1;
      subCost = aVec[j] + (a[i] !=  b[j]);
      m = min(delCost, min(insCost, subCost));
      if (m == delCost) dist->deletions++;
      else if (m == insCost) dist->insertions++;
      else dist->modifications++;
      bVec[j+1] = m;
    }
    swap((void**)&aVec, (void**)&bVec);
  }
  return aVec[sizeA-1];
}

