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
  writePrompt(funix);
  fgets(command, COMMAND_LENGTH, stdin);

   // eliminate trailing newline chracter
  if(strlen(command))
    strtok(command, "\n");

  return;
} // getCommand()

void init(Funix *funix) // creates currentDirectory, and sets umask and time
{
  funix->time = 0;
  funix->umask = 0;
  createDirectory(funix, funix->umask);

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
} // processCommand()

void run(Funix *funix) // reads and processes commands in a loop until proper exit
{
  char command[COMMAND_LENGTH];
  init(funix);

  do
  {
	getCommand(funix, command);
	processCommand(funix, command);
	printf("%s\n", command);
  } while(strcmp(command, "exit") != 0);
  return;
}

void umask(Funix *funix, int argCount, const char *arguments[])
{
  return;
}

  // prints the prompt
void writePrompt(Funix *funix)
{
  showPath(funix->currentDirectory);
  printf(" # ");

  return;
} // writePrompt();
