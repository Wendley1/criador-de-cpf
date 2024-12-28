int* SumTwoPointersArray(int* arr1, int* arr2, int bufferSize){
    int* r = malloc(bufferSize);

    for (int i = 0; i < bufferSize; i++)
    {
        r[i] = arr1[i] + arr2[i];
    }

    return r;
}

int* MultTwoPointersArray(int* arr1, int* arr2, int bufferSize) {
    int* r = malloc(bufferSize * sizeof(int));

    for (int i = 0; i < bufferSize; i++) {
        r[i] = arr1[i] * arr2[i];
    }

    return r;
}

int SumPointerArray(int* arr, int bufferSize){
    int sum = 0;

    for (int i = 0; i < bufferSize; i++)
    {
        sum += arr[i];
    }

    return sum;
}