#include "kernel/types.h"
#include "user/user.h"

void thread_test(int n){
  printf("This is a test of threads, my number is %d\n",n);
}

int
main(int argc, char *argv[])
{
  int arg = 10;
  int tid = 0;

  printf("This is the main thread :)\n");
  
  struct proc *mythread = 0;

  tid = create_thread((void*) mythread,thread_test,&arg);
  printf("Created thread %d\n", tid);
  return 0;
}
