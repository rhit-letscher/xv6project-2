#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"

//NOTE: set NPROC to 1000 before executing
//Spawns a bunch of threads to test for memory leaks
void thread_func(int x){
  printf("I'm child %d",getpid());
  exit(0);
}

int
main(int argc, char *argv[])
{
  int tid[NPROC];
  int args[NPROC];
  struct proc* threads[NPROC];

  printf("I am main thread pid %d\n",getpid());
    
  for(int i = 0;i<NPROC;i++){
    args[i] = i;
    //printf("tid[i] is empty rn, value is %d\n", tid[i]);
    tid[i] = create_thread((void*) threads[i],thread_func,&args[i]);
    if(tid[i]!=-1){
    printf("Spawning child with PID %d\n", tid[i]);
    }
  }

  for(int i = 0;i<NPROC;i++){
    if(tid[i]!=-1){
    join_thread(tid[i],0);
    printf("Joining child with PID %d\n", tid[i]);
    }
  }
  printf("Done\n");
  exit(0);
}