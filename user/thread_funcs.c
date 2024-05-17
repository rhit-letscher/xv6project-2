//Demonstrates creation of threads executing different functions.
//They each have a local var with the same name and are able to simeltaneously print their
//differing values, demonstrating that each thread has its own user stacks. 
#include "kernel/types.h"
#include "user/user.h"
int i = 10;

void thread_func_1(int *n){
  int i = 40;
  printf("Here's a child thread executing function 1. My i is %d\n",i);
  sleep(10);
  exit(0);
}

void thread_func_2(int *n){
  int i = 20;
  printf("Here's a child thread executing function 2. My i is %d\n",i);
  sleep(10);
  exit(0);
}

int
main(int argc, char *argv[])
{
  struct proc* p1 = 0;
  struct proc* p2 = 0;
  int thread1 = create_thread(p1,thread_func_1, 0);
  int thread2 = create_thread(p2,thread_func_2, 0);

  join_thread(thread1,0);
  join_thread(thread2,0);
  printf("Parent all done.\n");
  exit(0);
}

