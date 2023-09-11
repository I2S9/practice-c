#define SIZE 5
// Exercise : Write a function that receives an array. 
//The function should count and print the frequencyy of each of the array's elements

void printValueFrequency(int *arr, int size)
{
    int i, j;
    int leftFlag = 0; 
    int countValue;
    for(i=0;i<size;i++)
    {
        countValue = 1;
        leftFlag = 0;
        // Left Part
        for(j=0;j<i;j++)
        {
            if(arr[j]== arr[i])
            {
                leftFlag = 1;
                break;
            }
        }
        if(leftFlag == 1)
            continue;
            // Right part
            for(j=i+1;j<size;j++) 
            {
                if(arr[j]==arr[i])
                    countValue++;
            }
            //Print the actual frequency
            //Value at arr[i] appears countValue times
    }
}


int main()
{
    return 0;
}
