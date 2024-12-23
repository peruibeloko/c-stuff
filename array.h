typedef struct {
  int* arr;
  int size;
} Array;

typedef struct {
  int* arr;
  int startIndex;
  int endIndex;
  int size;
} ArraySlice;

void swap(ArraySlice* l, int leftIndex, ArraySlice* r, int rightIndex);

void initArray(int size, Array* arr);

ArraySlice* toSlice(Array* arr);
ArraySlice* take(ArraySlice* arr, int startIndex, int count);
ArraySlice* join(ArraySlice* arr1, ArraySlice* arr2);
int sliceGet(ArraySlice* arr, int pos);