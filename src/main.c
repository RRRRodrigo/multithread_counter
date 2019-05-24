#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int prim = 0;

int isprime(unsigned long long num){
  unsigned long long r = 2;
  if(num == 1)
    return 0;
  if(num == 0)
   return 0;
  while(num % r && r < num)
    r++;
  if(r == num){
    prim++;
    return 1;
  }
  else
    return 0;
}

void *thread_work(void* entra){
  if(isprime(*((unsigned long long*)entra)))
    return entra;
  return NULL;
}

unsigned long long entrada[5000];

int main(){
  pthread_t workers[5000];
  unsigned long long thread_id[5000];
  int x = 0, i = 0;

  scanf("%llu", &(entrada[x]));

  while(scanf("%llu", &(entrada[++x])) == 1){}

  for(i=x;i<5000;i++)
      entrada[i] = 0;

  for(i=0;i<x;i++){ 
    pthread_create(&(workers[i]), NULL, thread_work, (void*)(&entrada[i]));
  }

  for(i=0; i<x; i++){
    pthread_join(workers[i], NULL);
  }

  printf("%d\n", prim);
  return 0;
}
