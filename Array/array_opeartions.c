#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("Array Elements are: ");
    for(i=0;i<arr.length;i++) {
        printf("%d ",arr.A[i]);
    }
}

void Add(struct Array *arr,int x) {
    if(arr ->size > arr -> length) {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr,int index, int x) {
    int i;
    if(index >=0 || index <= arr->length) {
        for(i=arr->length;i>index;i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) {
    int i,x=0;
    if(index >=0 || index <= arr->length) {
        x = arr->A[index];
        for(i = index; i < arr->length-1;i++) {
            arr->A[i] = arr ->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int Get(struct Array arr, int index) {
    if(index >=0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if(index >= 0 && index < arr->length) {
        arr->A[index] = x;
    }
}

int max(struct Array arr) {
    int max_val = arr.A[0];
    for(int i=1;i<arr.length;i++) {
        if(arr.A[i] > max_val) {
            max_val = arr.A[i];
        }
    }
    return max_val;
}

int min(struct Array arr) {
    int min_val = arr.A[0];
    for(int i=1;i<arr.length;i++) {
        if(arr.A[i] < min_val) {
            min_val = arr.A[i];
        }
    }
    return min_val;
}

int Sum(struct Array arr) {
    int total = 0, i;
    for(i=0;i<arr.length;i++) {
        total+=arr.A[i];
    }
    return total;
}

float Average(struct Array arr) {
    return (float)Sum(arr)/arr.length;
}

int Linear_search(struct Array arr,int key) {
    int i;
    for(i=0; i<arr.length;i++) {
        if(arr.A[i] == key) return i;
    }
    return -1;
}

int Binary_search(struct Array arr,int key) {
    int mid,low=0,high=arr.length-1;
    while (low <= high){
        mid = (low+high)/2 ;
        if(arr.A[mid] == key) return mid;
        else if(arr.A[mid] > key) {
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return -1;
}

void Reverse(struct Array *arr) {
    int i,j,temp;
    for(i=0,j=arr->length-1;i<j;i++,j--) {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void left_rotation(struct Array *arr) {
    int i,x = arr->A[0];
    for(i=0;i<arr->length-1;i++) {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = x;
}

int main()
{
    struct Array arr = {{13,54,11,67,34,27,92,5},20,8};
    left_rotation(&arr);
    Display(arr);
    return 0;
}
