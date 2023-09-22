// Recursion Practice 
// Develop a recursive function that receives an integer value "n"
// The function should print the value of "n" in binary-Representation (base 2)
// For example "n" = 4 --> 100, "n" = 6 --> 110

void printInBInary(int n)
{
  if(n<=1)
    printf("%d", n);
  else {
    printInBinary(n/2);
    printf("%d", n % 2);
  }
  
}

int main()
{
  printInBinary(0);
  return 0;
}
