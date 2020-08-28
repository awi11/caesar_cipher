#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <errno.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
  int f;
  const char *OPTSTRING = "hde";
  const char *alphabet[] = {"abcdefghijklmnopqrstuvwxyz",
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; 
  int decrypt = 0;

  while ((f = getopt(argc, argv, OPTSTRING)) != -1) {
    switch (f) {
      case 'h':
       printf("Enter the appropriate flag\n");
       break;
     case 'd':
       decrypt = 1;
       printf("Decrypting..\n");
       break;
     case 'e':
       printf("Encrypting..\n");
    }
  }

  char *endptr;
  int key;

  // after parsing flags, should be two arguments, key and pw
  if ((argc - optind == 2) && decrypt) {
    key = strtoul(argv[optind], &endptr, 10);
    optind++;
    printf("Key is: %i\n", key);
  } else {
    fprintf(stderr, "Wrong num args\n");
    return EXIT_FAILURE;
  }

  char *userInput = argv[optind];
  int shift = key % 26;
  int len = strlen(userInput);
  int i;

  for (i = 0; i < len; i++) {
      char c = userInput[i];
      if (isupper(c)) {
        c = c - 'A';
        userInput[i] = alphabet[1][(((c - shift) + 26) % 26)];
      } else {
        c = c - 'a';
        userInput[i] = alphabet[0][(((c - shift) + 26) % 26)];
      }
  }
  printf("%s\n", userInput);
  return 0;
}
