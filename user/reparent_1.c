#include "kernel/types.h"
#include "user/user.h"
int i = 10;

void thread_func(int x){
  printf("Child %d running forever....\n",x);
  while(1);
}

//Spawns 3 threads that run forever.
int
main(int argc, char *argv[])
{
  int tid[3];
  int args[5];
  struct proc* threads[5];

  printf("I am main thread pid %d\n",getpid());
    
  for(int i = 0;i<5;i++){
    args[i] = i;
    tid[i] = create_thread((void*) threads[i],thread_func,&args[i]);
    printf("Spawning child with PID %d", tid[i]);
    sleep(10);
  }

  printf("Currently running processes:\n");
  ps();
  printf("Gonna die now and all my children should die too!\n");
  exit(0);
}