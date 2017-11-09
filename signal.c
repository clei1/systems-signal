#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

void append(){
  int fd = open("foo", O_CREAT | O_WRONLY | O_APPEND, 0666);
  char msg[] = "Exited due to SIGINT";
  write(fd, msg, sizeof(msg));
  close(fd);
}

static void sighandler(int signo){
  if(signo == SIGUSR1){
    printf("This is my PPID: %d\n", getppid());
  }
  else if(signo == SIGINT){
    append();
    exit(1);
  }
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while(1){
    printf("This is my PID: %d\n", getpid());
    sleep(1);
  }
  
  return 0;
}
