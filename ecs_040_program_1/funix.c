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

  // writes prompt and reads command
void getCommand(Funix *funix, char *command)
{
  printf("# ");

  fgets(command, COMMAND_LENGTH, stdin);
  strtok(command, "\n");
  return;
} // getCommand()

void init(Funix *funix) // creates currentDirectory, and sets umask and time
{
  funix->currentDirectory->name = "/";
  funix->time = 0;
  funix->umask = 0;

  return;
} // init()

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
  return 0;
}
void run(Funix *funix) // reads and processes commands in a loop until proper exit
{
  char command[COMMAND_LENGTH];
  init(funix);

  do
  {
	getCommand(funix, command);
	printf("%s\n", command);
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
