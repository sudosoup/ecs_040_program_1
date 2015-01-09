// Authors: Yage Hu, Thomas Connor Campbell

#include <stdio.h>
#include <string.h>
#include "funix.h"

void cd(Funix *funix, int argCount, const char *arguments[])
{
  return;
}

  // calls cd() with currentDirectory as one of its parameters
int eXit(Funix *funix, int argCount, const char *arguments[])
{
  int value = 0;

  return value;
}

  // checks "exit" command, returns 0 on proper exit
void getCommand(Funix *funix, char *command) // writes prompt and reads command
{
  return;
}

void init(Funix *funix) // creates currentDirectory, and sets umask and time
{
  return;
}

void ls(Funix *funix, int argCount, const char *arguments[])
{
  return;
}

  // calls ls() with currentDirectory as one of its parameters
void mkdir(Funix *funix, int argCount, const char *arguments[])
{
  return;
}

  // calls mkdir() with currentDirectory as one of its parameters
int processCommand(Funix *funix, char *command) // returns 0 on proper exit
{
  int value = 0;

  return value;
}
void run(Funix *funix) // reads and processes commands in a loop until proper exit
{
  char command[COMMAND_LENGTH];
  char *newline;
  do
  {
	printf("# ");
    fgets(command, COMMAND_LENGTH, stdin);
	newline = strchr(command, '\n');
	if(newline)
	  *newline = 0;

	if(strcmp(command, "cd") == 0)
	{
	  printf("%s", command);
	}
  } while(strcmp(command, "exit") != 0);
  return;
}

void umask(Funix *funix, int argCount, const char *arguments[])
{
  return;
}

  // checks "umask" command and executes it if it is proper
void writePrompt(Funix *funix)
{
  return;
}
