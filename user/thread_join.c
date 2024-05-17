#include "kernel/types.h"
#include "user/user.h"
//Demonstrates join_thread

void thread_func_1(){
  printf("This is the child thread %d\n",getpid());
  sleep(50);
  exit(0);
}

int
main(int argc, char *argv[])
{
  int tid[5];
  struct proc* threads[5];

  printf("This is the main thread :)\n");
    
  for(int i = 0;i<5;i++){
    tid[i] = create_thread(threads[i],thread_func_1, 0);
    printf("Created child thread %d", tid[i], 0);
    sleep(10);
  }
  
  //Join is going to halt the execution of our main process until each of our specified threads finish
  //Note the loop is running in reverse order, so it starts with the last created thread and counts down, and since
  //there was a delay of 10 between creating each thread, there's going to be a delay of 10 here as we wait for each to finish well
  for(int i = 4;i>=0;i--){
    int t = join_thread(tid[i],0);
    printf("Child thread with tid %d is done executing\n", t);
  }

  printf("Parent all done.\n");
  exit(0);
  
  return 0;
}

