#include <stdlib.h>

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

void initArray(int size, Array* arr) {
  arr = malloc(sizeof(Array));
  arr->arr = calloc(size, sizeof(int));
  arr->size = size;
}

ArraySlice* initArraySlice(int* arr, int startIndex, int endIndex) {
  ArraySlice* out = malloc(sizeof(ArraySlice));

  out->arr = arr;
  out->size = 1 + endIndex - startIndex;
  out->startIndex = startIndex;
  out->endIndex = endIndex;

  return out;
}

ArraySlice* toSlice(Array* arr) {
  return initArraySlice(arr->arr, 0, arr->size - 1);
}

int sliceGet(ArraySlice* arr, int pos) {
  return arr->arr[arr->startIndex + pos];
}

void sliceSet(ArraySlice* arr, int pos, int val) {
  arr->arr[arr->startIndex + pos] = val;
}

void swap(ArraySlice* l, int leftIndex, ArraySlice* r, int rightIndex) {
  int temp = sliceGet(l, leftIndex);
  sliceSet(l, leftIndex, sliceGet(r, rightIndex));
  sliceSet(r, rightIndex, temp);
}

ArraySlice* take(ArraySlice* arr, int startIndex, int count) {
  return initArraySlice(arr->arr, startIndex, startIndex + count);
}

ArraySlice* join(ArraySlice* arr1, ArraySlice* arr2) {
  ArraySlice* out = malloc(sizeof(ArraySlice));

  out->arr = arr1->arr;
  out->size = arr1->size + arr2->size;
  out->startIndex = arr1->startIndex;
  out->endIndex = arr2->endIndex;

  return out;
}