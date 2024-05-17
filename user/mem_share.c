#include "kernel/types.h"
#include "user/user.h"
//Demonstrates threads' ability to share memory by declaring global variable i, having 5 threads increment
//it simeltaneously, and ensuring that it's 5 greater from the parent after they are all done executing.
int i = 10;

void thread_func_1(int *n){
  printf("This is the child thread number %d. I'm going to increment i.\n",n);
  i++;
  printf("Child thread %d done, i is %d\n",getpid(),i);
  exit(0);
}

int
main(int argc, char *argv[])
{
  int tid[5];
  uint64 args[5];
  struct proc* threads[5];

  printf("This is the main thread :) Global variable i is %d\n",i);

  for(int i = 0;i<5;i++){
    args[i] = i;
    tid[i] = create_thread(threads[i],thread_func_1, &args[i]);
  }

  sleep(10);
  
  for(int i = 4;i>=0;i--){
    join_thread(tid[i],0);
  }

  printf("Parent all done. If we're sharing memory correctly i should be 15. It's %d\n",i);
  exit(0);
  
  return 0;
}

