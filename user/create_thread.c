#include "kernel/types.h"
#include "user/user.h"
int i = 10;

void thread_func_1(int n){
  printf("%d",n);
  printf("This is the child thread, my argument is %d. I'm going to increment i.\n",n);
  sleep(50);
  i++;
  printf("Child thread %d done, i is %d\n",getpid(),i);
  exit(0);
}

int
main(int argc, char *argv[])
{
  int tid[5];
  int args[5];
  struct proc* threads[5];

  printf("This is the main thread :)\n");
    
  for(int i = 0;i<5;i++){
    args[i] = i;
    tid[i] = create_thread((void*) &threads[i],thread_func_1,&args[i]);
    printf("Created child thread %d with argument %d\n", tid[i], args[i]);
    //sbrk(514);
    //printf("Increasing memory by 4 bytes...\n");
    sleep(10);
  }
  
  //So, this is going to halt the execution of our main process until each
  //Except the loop is running in reverse order, so it starts with the last created thread and counts down, and since
  //there was a delay of 10 between creating each thread, there's going to be a delay of 10 here as we wait for each to finish well
  for(int i = 4;i>=0;i--){
    int n = join_thread(tid[i],0);
    printf("child thread with tid %d is done executing\n", n);
  }

  printf("Parent all done. If we're sharing memory correctly i should be 15. It's %d\n",i);
  
  while(1);
  return 0;
}

