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

  // after parsing flags, should be two arguments, key and string 
  if ((argc - optind == 2) && decrypt) {
    key = strtoul(argv[optind], &endptr, 10);
    optind++;
    printf("Key is: %i\n", key);
  } else {
    fprintf(stderr, "Wrong num args\n");
    return EXIT_FAILURE;
  }

  char *m = argv[optind];
  int shift = key % 26;
  int l = strlen(m);

  int i;
  for (i = 0; i < l; i++) {
    if (!isalpha(m[i])) continue; 
    if (isupper(m[i])) {
      m[i] = alphabet[1][(((tolower(m[i]) - 'a') + shift) % 26)];
    } else {
      m[i] = alphabet[0][(((tolower(m[i]) - 'a') + shift) % 26)];
    }
  }
  printf("%s\n", m);
  return 0;
}
