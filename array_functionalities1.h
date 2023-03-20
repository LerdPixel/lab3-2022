#ifndef ARRAY_FUNCTIONALITIES1
#define ARRAY_FUNCTIONALITIES1
#include <stdlib.h>

int *insertElementById(int index, int element, int *array, int *len) {
    if (index < 0) {
        return NULL;
    }
    if (index > *len) {
        index = *len;
    }
    ++*len;
	array = (int *)realloc(array, *len * sizeof(int));
	if (array == NULL) {
		puts("No memomy\n");
		return NULL;
	}
	for (int i = *len - 1; i > index; --i) {
		array[i] = array[i - 1];
	}
	array[index] = element;
	return array;
}

int *deleteElementById(int index, int *array, int *len) {
    if (index >= *len || index < 0) {
        return NULL;
    }
	for (int i = index; i < *len - 1; ++i) {
		array[i] = array[i + 1];
	}
	--*len;
    array = (int *)realloc(array, *len * sizeof(int));
    if (array == NULL) {
        puts("No memomy\n");
        return NULL;
    }
    return array;
}

int *dataProcessing(int **array1, int **array2, int arrayRes, int *len1, int *len2, int *resLen) {
    arrayRes = (int *)malloc(sizeof(int) * (*len1 + *len2)); // result array with max length
    if (arrayRes == NULL) {
        puts("no memory\n");
        return NULL;
    }
    int flag = 0;
    *resLen = 0;
    for (int i = 0; i < *len1; ++i) {
        for (int j = 0; j < *resLen; ++j) {
            if (*array1[i] == arrayRes[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            arrayRes[*resLen] = *array1[i];
            ++*resLen;
            *array1 = deleteElementById(i, *array1, len1);
            --i;
        }
        else
            flag = 0;
    }
    for (int i = 0; i < *len2; ++i) {
        for (int j = 0; j < *resLen; ++j) {
            if (*array2[i] == arrayRes[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            arrayRes[*resLen] = *array2[i];
            ++*resLen;
            *array2 = deleteElementById(i, *array2, len2);
            --i;
        }
        else
            flag = 0;
    }
    arrayRes = (int *)realloc(arrayRes, sizeof(int) * *resLen);
    if (arrayRes == NULL) {
        puts("No memomy\n");
        return NULL;
    }
    return arrayRes;
}

void freeArrays(int **arrays) {
    for (int i = 0; i < ARRAY_AMOUNT; ++i) {
        free(arrays[i]);
    }
}

#endif
