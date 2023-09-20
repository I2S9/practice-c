// Write a recursive function that :
  - Receives an array of floating point numbers (>0) and its size
  - Returns "1" if :
      - For any two adjacent elements in the array the "integer parts" are sorted in ascending order,
        and the "fractional parts" are sorted in descending order
  - Returns "0", othewise

int isSpecialFloatingSorted(double* arr, int size)
{
  int leftElementInteger, rightElementInteger;
  double leftElementFractional, rightElementFractional;
  if(size==1)
    return 1;
  leftEementInteger = (int)arr[0];
  rightElementniteger = (int)arr[1];

  leftElementFractional = arr[0] - leftElementInteger;
  rightElementFractional = arr[1] - rightElementInteger;

  if(leftElementInteger <= rightElementInteger && leftElementFractional >= rightElementFractional)
    return isSpecialFloatingSorted(arr + 1, size - 1);
  else
    return 0;
}






  
  
}
