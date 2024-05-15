#include "kernel/types.h"
#include "user/user.h"

void thread_test(int n){
  printf("This is the child thread, my argument is %d\n",n);
  exit(0);
}

int
main(int argc, char *argv[])
{
  int arg = 10;
  int tid = 0;

  printf("This is the main thread :)\n");
  
  struct proc *mythread = 0;

  printf("About to create child thread with argument %d\n", arg);
  tid = create_thread((void*) mythread,thread_test,&arg);
  wait(0);
  printf("child thread with tid %d is done executing, returning\n", tid);
  while(1);
  return 0;
}
