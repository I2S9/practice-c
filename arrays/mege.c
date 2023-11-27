#define N 4
#define M 3


// Merge #1

void merge2SortedeArrays(int a*, int b*, int b, int b, int *c)
{
    int i=0, j=0, k=0;

    while(i<N && j < M)
    {
        if(a[i] < b[j])
            c[k++] = a[i];
        else
            c[k++] = b[j++];
    }
    // Copying all the elements of array a..
    while(i<N)
        c[k++] = a[i++];
    // Copying all the elements of array b..
    while(j<M)
        c[k++] = b[j++];
}

// Merge #2

int* merge2SortedeArraysOpt2(int a*, int b*, intn , int m)
{
    int i=0, j=0, k=0;

    int *c;
    // Dynamic Memory Allocation (m+n) size

    while(i<N && j < M)
    {
        if(a[i] < b[j])
            c[k++] = a[i];
        else
            c[k++] = b[j++];
    }
    // Copying all the elements of array a..
    while(i<N)
        c[k++] = a[i++];
    // Copying all the elements of array b..
    while(j<M)
        c[k++] = b[j++];
    return c;
}

int main()
{
    int a[N] = {1,3,4,6};
    int b[M] = {2,5,7};
    int c[M + N];
    /* int c[M + N]; */
    // merge2SortedeArrays(a, b, N, M, c);    

    int*c = merge2SortedeArraysOpt2(a, b, N, M);

    // From this point array "c" already have all relevant elements 
    // Delete Dynamically Allocated Memory
    return 0;
}
