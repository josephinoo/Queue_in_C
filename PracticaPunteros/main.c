#include <stdlib.h>
#include <string.h> 
#include <stdio.h> 

int main(int argc, char ** argv){
  char * ptr = NULL;
  ptr = malloc(13);
  if (argc>1)
     strcpy(ptr,"Hello World!");
  ptr[12]=0;
  printf("%s\n",ptr);
  return 0;
}