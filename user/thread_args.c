#include "kernel/types.h"
#include "user/user.h"
//Creates 5 threads with differing int arguments (initialized in an array and passed via reference) in a loop.

void thread_func_1(int *n){
  printf("This is the child thread, my argument is %d.",*n);
  sleep(50);
  exit(0);
}

int
main(int argc, char *argv[])
{
  int tid[5];
  uint64 args[5];
  struct proc* threads[5];

  printf("This is the main thread :)\n");
    
  for(int i = 0;i<5;i++){
    args[i] = i;
    tid[i] = create_thread(threads[i],thread_func_1, &args[i]);
    printf("Created child thread %d with argument %d\n", tid[i], args[i]);
    sleep(5);
  }
  
  //Wait for everyone to finish
  for(int i = 0;i<5;i++){
    join_thread(tid[i],0);
  }

  printf("Parent all done.\n");
  exit(0);
  
  return 0;
}

