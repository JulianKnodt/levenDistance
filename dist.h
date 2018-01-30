#ifndef levDistance
#define levDistance
typedef struct {
  unsigned int insertions;
  unsigned int deletions;
  unsigned int modifications;
} distance;

unsigned int dist(char* a, size_t sizeA, char* b, size_t sizeB, distance* dist);
#endif

