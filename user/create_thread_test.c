#include "kernel/types.h"
#include "user/user.h"
int i = 10;

void thread_test(int n){
  printf("This is the child thread, my argument is %d. I'm going to increment i.\n",n);
  sleep(10);
  i++;
  printf("Child thread %d done, i is %d\n",getpid(),i);
  exit(0);
}

int
main(int argc, char *argv[])
{
  int tid;
  int args[5];
  struct proc* threads[5];

  printf("This is the main thread :)\n");
    
  for(int i = 0;i<5;i++){
    args[i] = i;
    tid = create_thread((void*) &threads[i],thread_test,&args[i]);
    printf("Created child thread %d with argument %d\n", tid, args[i]);
  }
  
  for(int i = 0;i<5;i++){
    int n = wait(0);
    printf("child thread with tid %d is done executing\n", n);
  }

  printf("Parent all done. If we're sharing memory correctly i should be 15. It's %d\n",i);
  
  while(1);
  return 0;
}
