#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int calcoli_figlio1() {
  int k;
  printf("Elab. Parallela processo figlio \n");
  k = 3 + 2;
  return k;
}

int calcoli_padre1() {
  int k;
  printf("Elab. Parallela processo padre \n");
  k = 6 - 2;
  return k;
}

int calcoli_padre2(int a, int b) {
  int k;
  printf("Elab. Finale padre \n");
  k = a + b;
  return k;
}

int glob = 4;

int main() {
  int x, y, z, status, pid;
  x = -200;
  int zero = 0;
 
  printf("Prima del fork: Sono il padre con PID =  %d, x = %d, glob = %d\n ", getpid(), x, glob);
  pid = fork();
  if(pid == 0) {
    
    x = calcoli_figlio1(); 
    // x=x/zero;
    exit(x);
    

  }
  else {
     y = calcoli_padre1();

  }

   //sleep(50); // to show that the child becomes a zombie if it's not read by the father // uncomment it, open a terminal: top or ps aux

  wait(&status);
  printf(" Join \n");
  if WIFEXITED(status) {
    x = WEXITSTATUS(status);
    z = calcoli_padre2(x,y);
    printf("%d + %d = %d\n", x, y, z);
    }
    else {
        printf("The child did NOT terminate normally: exit status of the child was %d\n",  status);
    }
  
  return 0;
}
