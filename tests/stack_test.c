#include <check.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *buf = malloc(128 * sizeof(char));

  for (int i = 0; i < argc; i++) {
    sprintf(buf, "%s\n", argv[i]);
    fprintf(stdout, "%s", buf);
  }

  free(buf);
}
