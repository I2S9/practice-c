//Implementing Insert Operation
//arr is the address of the first byte that we need to copy
//size = source fo total bytes

void* insert(void* arr, unsigned size, unsigned idx, void* source, unsigned sourceSize);

void* insert(void* arr, unsigned size, unsigned idx, void* source, unsigned sourceSize)
{
    void* newArr = malloc(size+sourceSize);
    if(!newArr) return NULL;
    memcpy(newArr, arr, idx);
    memcpy((char*)newArr + idx + sourceSize, (char*)arr + idx, size - idx);
    return newArr;
}

int main()
{
    return 0;
}
