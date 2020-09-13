#include<stdio.h>
#include<stdlib.h>

void oneRound(int** A, int *list, int *id, int *id11, int *id12, int *id21, int *id22)
{
    int i;
    if(*id11<*id12 && *id21<*id22)
    {
        for(i = *id21; i < *id22; i++)
        {
            list[(*id)++] = A[*id11][i];
        }
        (*id11)++;
    }
    
    if(*id11<*id12 && *id21<*id22)
    {
        for(i = *id11; i < *id12; i++)
        {
            list[(*id)++] = A[i][*id22-1];
        }
        (*id22)--;
    }
    if(*id11<*id12 && *id21<*id22)
    {
        for(i = *id22-1; i >= *id21; i--)
        {
            list[(*id)++] = A[*id12-1][i];
        }
        (*id12)--;
    }
    if(*id11<*id12 && *id21<*id22)
    {
        for(i = *id12-1; i >= *id11; i--)
        {
            list[(*id)++] = A[i][*id21];
        }
        (*id21)++;
    }
}

int* spiralOrder(int** A, int n11, int n12, int *len1) {
    int *list = (int*) malloc(*len1*sizeof(int));
    *len1 = n11*n12;
    int *id = (int*) malloc(sizeof(int));
    int *id11 = (int*) malloc(sizeof(int));
    int *id12 = (int*) malloc(sizeof(int));
    int *id21 = (int*) malloc(sizeof(int));
    int *id22 = (int*) malloc(sizeof(int));
    *id = 0; *id11 = 0; *id12 = n11; *id21 = 0; *id22 = n12;
    while(*id11<*id12 && *id21<*id22)
    {
        oneRound(A, list, id, id11, id12, id21, id22);
        // (*id11)++; (*id12)--;s
        }
    return(list);
}

void test(int* i)
{
    *i = 10;
    printf("%d\n", *i);
}

int main()
{
    int len, k = 0, *list;
    int **A = (int**) malloc(2*sizeof(int*));
    for(int i = 0; i<2; i++)
    {
        A[i] = (int*) malloc(2*sizeof(int));
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            A[i][j] = ++k;
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d ", A[i][j]);;
        }
        printf("\n");
    }

    list = spiralOrder(A, 1, 2, &len);
    for(int i = 0; i < len; i++)
        printf("%d ", list[i]);
    return 0;
}



A : 
[
  [6, 185, 7, 3, 53, 131, 354, 174, 177, 233, 129]
  [358, 70, 173, 48, 353, 224, 321, 304, 353, 317, 369]
  [76, 119, 259, 364, 217, 367, 168, 310, 2, 281, 292]
  [218, 64, 294, 283, 172, 210, 308, 220, 101, 248, 213]
  [243, 336, 298, 255, 334, 351, 100, 112, 345, 329, 78]
  [95, 305, 190, 388, 274, 203, 25, 66, 363, 290, 113]
  [213, 224, 27, 178, 330, 8, 202, 179, 135, 130, 114]
  [166, 319, 171, 254, 213, 180, 274, 273, 151, 260, 344]
  [394, 326, 180, 241, 279, 63, 184, 164, 51, 219, 371]
]

Typed input
9 11 6 185 7 3 53 131 354 174 177 233 129 358 70 173 48 353 244 321 304 353 317 369 76 199 249 364 217 367 168 310 2 281 292 218 64 294 283 172 210 308 220 101 248 213 143 336 298 255 334 351 100 112 345 329 78 95 305 190 388 274 203 25 66 262 290 113 213 224 27 178 330 8 202 179 135 130 114 166 319 171 254 213 190 274 273 151 260 344 394 326 180 241 279 63 184 164 51 219 371

Expected output
6 185 7 3 53 131 354 174 177 233 129 369 292 213 78 113 114 344 371 219 51 164 184 63 279 241 180 326 394 166 213 95 243 218 76 358 70 173 48 353 224 321 304 353 317 281 248 329 290 130 260 151 273 274 180 213 254 171 319 224 305 336 64 119 259 364 217 367 168 310 2 101 345 363 135 179 202 8 330 178 27 190 298 294 283 172 210 308 220 112 66 25 203 274 388 255 334 351 100 


Output
6 185 7 3 53 131 354 174 177 233 129 369 292 213 78 113 114 344 371 219 51 164 184 63 279 241 180 326 394 166 213 95 143 218 76 358 70 173 48 353 244 321 304 353 317 281 248 329 290 130 260 151 273 274 190 213 254 171 319 224 305 336 64 199 249 364 217 367 168 310 2 101 345 262 135 179 202 8 330 178 27 190 298 294 283 172 210 308 220 112 66 25 203 274 388 255 334 351 100 


Error:
Runtime Error. Your submission stopped because of a runtime error. ex: division by zero, array index out of bounds, uncaught exception You can try testing your code with custom input and try putting debug statements in your code.
solution: malloc.c:2374: sysmalloc: Assertion `(old_top == (((mbinptr) (((char *) &((av)->bins[((1) - 1) * 2])) - __builtin_offsetof (struct malloc_chunk, fd)))) && old_size == 0) || ((unsigned long) (old_size) >= (unsigned long)((((__builtin_offsetof (struct malloc_chunk, fd_nextsize))+((2 *(sizeof(size_t))) - 1)) & ~((2 *(sizeof(size_t))) - 1))) && ((old_top)->size & 0x1) && ((unsigned long) old_end & pagemask) == 0)' failed.
Aborted











9 11 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98
