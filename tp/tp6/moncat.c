#include <stdio.h>

int main(int argc, char * argv[]){
  FILE * d;
  char c;
  if(d!=NULL){
    char c = fgetc(d);
  }
  d = fopen("/etc/passwd.txt", "r");
  while(feof(d)!=1){
    c = fgetc(d);
    putchar(c);
  }
  fclose(d);
 }
