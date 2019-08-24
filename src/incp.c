#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int pid, x;

  char spid[255], r_comando[255] = " -o pid,%cpu,rss,%mem | grep -v RSS";//Linux Terminal command that shows process informations

  pid = fork(); //Fork create a copy of an actual process and get his ID  

  sprintf(spid, "%i", pid); //convert the pid value into a string

  char bash_cmd[256] = "ps -p "; //Command to see the status of process in linux terminal

  strcat(spid, r_comando); //Put the PID of the son process together with the command

  strcat(bash_cmd, spid); //Put the PID of the son process together with the commands to terminal

  if(pid < 0)//If the ID of the process is less than 0, the process wasn't created/copied
  {
    perror("pipe");
    exit(-1);
  }

  else if(pid > 0)//If the id of the process is more than 0, the process was created/copied and it's the Father process 
  {

    while(1)//While loop to print the use of memory and cpu
    {

      //strcat(spid, r_comando);

      printf("%s\n", bash_cmd);

      char buffer[1000];
      FILE *pipe;
      int len;
      pipe = popen(bash_cmd, "r"); //Creation of a file with the use data of CPU and Memory

      if (NULL == pipe) { //If pipe have NULL value, the file wasn't created
        perror("pipe");
        exit(1);
      }

      char* mem_usage = fgets(buffer, sizeof(buffer), pipe);
      len = strlen(bash_cmd);
      //bash_cmd[len-1] = '\0';
      pclose(pipe); //Close the file


      int y;

      //Shows in the terminal the use of cpu and memory as requested
      printf("PID  %%CPU  MEM(kb) %%MEM\n");

      printf("%s\n", mem_usage);
      sleep(1);
    }


  }

  else //If the ID is 0, the process was created/copied and it's the Son process
  {

    if(strcmp(argv[1], "cpu_mem") == 0)//if the main arg was "cpu_mem" it shows the percents of intensive CPU and Memory use
    {
      double n = 2;
      int x; //counter that will define when the memory allocation 

      while(1) //infinite loop that will start the cpu usage
      {

        n = n * n; // Operation using a double type, just for increasing the cpu usage

        if(x == 60) //Condition for memory allocation, that will be satisfy only when the counter is 60 
        {
          malloc(1);//Gradul memory allocation

          x = 0;//restart counter
        }
        x++;//increase counter

      }
    }

    if(strcmp(argv[1], "cpu") == 0)//if the main arg was "cpu" it shows the percents of intensive CPU use
    {
      double n = 2;

      while(1)//infinite loop that will start the cpu usage
      {
        n = n * n;// Operation using a double type, just for increasing the cpu usage

        if(x == 60)
        {
          x = 0;
        }
        x++;
      }
    }
  }
  exit(0);//end of the process
}
