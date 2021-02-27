#include <stdio.h>    // puts(), printf(), perror(), getchar()
#include <stdlib.h>   // exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>   // getpid(), getppid(),fork()
#include <sys/wait.h> // wait()

void child() {
  char *const argv[] = {"cat", "leer_cadena.c", NULL};

  fflush(stdout);

  execvp(argv[0], argv);

  perror("execvp");
  exit(EXIT_FAILURE);
}

void parent(pid_t pid) {
  int status;

  wait(&status);

  if (WIFEXITED(status)) {
    printf("PARENT <%ld> Child with PID = %ld and exit status = %d terminated.\n",
           (long) getpid(), (long) pid, WEXITSTATUS(status));
  }

  exit(EXIT_SUCCESS);
}


int main(void) {

  pid_t pid;
  pid = fork();

  if (pid == -1) {
    // On error fork() returns -1.
    perror("fork failed");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    // On success fork() returns 0 in the child.
    child();
  } else {
    // On success fork() returns the pid of the child to the parent.
    parent(pid);
  }
}
