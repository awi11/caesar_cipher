#include <stdio.h>
#include <string.h>
#include <getopt.h>

int main (int argc, char * argv[]) {
    int f;
    char * OPTSTRING = "h";

// 65 - 122 alphabetical
  while ((f = getopt(argc, argv, OPTSTRING)) != -1) {
      if(f == 'h') {
         printf("Enter the appropriate flag\n");
      } 
  }

  if (argc < 2 || argc > 3) {
      printf("Wrong num of args\n");
      return 1;
  }
  char * userInput = argv[optind];
  int len = strlen(userInput);
  int i;

  // rotate every character left by 10
  for (i = 0; i < len; i++) {
      char c = userInput[i];
      c -= 10;
      if (c < 65) c = 'z' - ('A' - c);
      userInput[i] = c;
  }
  printf("%s\n", userInput);
  return 0;
}