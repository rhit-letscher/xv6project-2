#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  printf("Currently running processes:\n");
  ps();
  exit(0);
}