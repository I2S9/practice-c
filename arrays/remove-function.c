//Universal remove function
int main()
{
    return 0;
}

void *remove(void *arr, unsigned size, unsigned idx, unsigned sourceSize )
{
    void* newArr = malloc(size - sourceSize);
    if (!newArr) return NULL;

    memcpy(newArr, arr, idx);
    memcpy((char*)newArr + idx, (char*)arr+idx+sourceSize, size-idx-sourceSize);
    return newArr;
}
