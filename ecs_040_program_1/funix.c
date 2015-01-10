// Authors: Yage Hu (998450649), Thomas Connor Campbell

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "funix.h"

void cd(Funix *funix, int argCount, const char *arguments[])
{
/*  if(argCount != 2)
	printf("usage: cd directoryName\n");
  else
  {
	int i, index = -1;

	for(i = 0; i < funix->currentDirectory->numSubdirectories; i++)
	{
		// if the directory names match, set index = i
	  if(strcmp(arguments[1], funix->currentDirectory->subdirectories->name))
		index = i;
	} // search for a directory name match
  } */
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

  return;
} // getCommand()

void init(Funix *funix) // creates currentDirectory, and sets umask and time
{
  funix->currentDirectory = (Directory*) malloc(sizeof(Directory));
  funix->currentDirectory->name = (char*) malloc(sizeof(char) * COMMAND_LENGTH);
  funix->currentDirectory->subdirectories = (Directory**) malloc(sizeof(Directory*) * MAX_SUBDIRECTORIES);
  funix->currentDirectory->name[0] = '/';
  funix->currentDirectory->numSubdirectories = 0;
  funix->currentDirectory->parentDirectory = NULL;
  funix->currentDirectory->permissions.permissions = 7;
  funix->time = 0;
  funix->umask = 0;

  return;
} // init()

void ls(Funix *funix, int argCount, const char *arguments[])
{
	// if the number of arguments exceeds 2
  if (argCount > 2)
    printf("usage: ls [-l]\n");
  else
  {
    if (argCount == 2)
    {
    	// if the user input has the -l option
      if (strcmp(arguments[1], "-l"))
        printf("usage: ls [-l]\n");
      else
      {
        int i;

        for  (i = 0; i < funix->currentDirectory->numSubdirectories; i++)
        {
          printPermissions(&(funix->currentDirectory->subdirectories[i]->permissions));
          printf(" %d",funix->currentDirectory->subdirectories[i]->timeMod);
          printf(" %s\n",funix->currentDirectory->subdirectories[i]->name);
        }
      }
    }
    else
    {
      int i;

      for  (i = 0; i < funix->currentDirectory->numSubdirectories; i++)
        printf("%s\n", funix->currentDirectory->subdirectories[i]->name);
    } // else the user input is just ls
  } // else the number of arguments is either 1 or 2

  funix->time++;

  return;
} // ls()

  // calls ls() with currentDirectory as one of its parameters
void mkdir(Funix *funix, int argCount, const char *arguments[])
{
  if(argCount != 2)
  {
	printf("usage: mkdir directory_name\n");
  } // if the number of arguments in mkdir is wrong
  else if(funix->currentDirectory->numSubdirectories + 1 > MAX_SUBDIRECTORIES)
  {
	printf("mkdir: %s already contains the maximum number of directories\n",
	  funix->currentDirectory->name);
  } // if the number of subdirectories has already reached max value
  else
  {
	int i;
	if(funix->currentDirectory->subdirectories != NULL)
	{
	  for(i = 0; i < funix->currentDirectory->numSubdirectories; i++)
	  {
	    if((strcmp(arguments[1],
	      funix->currentDirectory->subdirectories[i]->name)) == 0)
	    {
		  printf("mkdir: cannot create directory '%s': File exists\n",
		    arguments[1]);
		  return;
	    } // if the user enters a existing filename
	  } // for-loop goes through each subdirectory
    } // if the directory contains subdirectories

	 // create and initialize the new directory
	funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories] =
	  (Directory*) malloc(sizeof(Directory));
	funix->currentDirectory->
      subdirectories[funix->currentDirectory->numSubdirectories]->name =
      (char*) malloc(sizeof(char));
	strcpy(funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories]->name,
	  arguments[1]);
	funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories]->
	  timeMod = funix->time;
	funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories]->
	  subdirectories = (Directory**) malloc(MAX_SUBDIRECTORIES *
	  sizeof(Directory*));
	funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories]->
	  numSubdirectories = 0;
	funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories]->
	  parentDirectory = funix->currentDirectory;
	funix->currentDirectory->
	  subdirectories[funix->currentDirectory->numSubdirectories]->
	  permissions.permissions = 7;

	  // apply umask value
	if(funix->umask > 3)
	  funix->currentDirectory->subdirectories[funix->currentDirectory->
	    numSubdirectories]->permissions.permissions -= 4;
	if(funix->umask == 2 || funix->umask == 3 || funix->umask == 6 ||
	  funix->umask == 7)
      funix->currentDirectory->subdirectories[funix->currentDirectory->
	    numSubdirectories]->permissions.permissions -= 2;
	if(funix->umask == 1 || funix->umask == 3 || funix->umask == 5 ||
	  funix->umask == 7)
      funix->currentDirectory->subdirectories[funix->currentDirectory->
	    numSubdirectories]->permissions.permissions -= 1;

	funix->currentDirectory->numSubdirectories++;
  } // if the user input is valid and the directory can be created

  return;
} // mkdir()

int processCommand(Funix *funix, char *command) // returns 0 on proper exit
{
  int argCount, i;
  char test = 'a';
  char *testptr = &test;
  char *temp = (char*) malloc((sizeof(char)) * COMMAND_LENGTH);

  strcpy(temp, command);

  for(argCount = -1; testptr != NULL; argCount++)
  {
	  // start parsing
	if(argCount == -1)
      testptr = strtok(temp, " \n");
	else // resume from last spot in the string
	  testptr = strtok(NULL, " \n");
  } // for loop tests for how many arguments there are

  const char **arguments = (const char**) malloc((sizeof(char*)) * argCount);

    // allocate memory for arguments
  for(i = 0; i < argCount; i++)
	  *(arguments + i) = (char*) malloc((sizeof(char)) * argCount);

    // parse first argument
  arguments[0] = strtok(command, " \n");

    // parse rest of the arguments
  for(i = 1; i < argCount; i++)
	arguments[i] = strtok(NULL, " \n");

    // if the user does not input anything
  if(arguments[0] == NULL)
	return 1;
  else if(strcmp(arguments[0], "mkdir") == 0)
  {
	mkdir(funix, argCount, arguments);
	return 1;
  }
  else if(strcmp(arguments[0], "ls") == 0)
  {
	ls(funix, argCount, arguments);
	return 1;
  }
  else if(strcmp(arguments[0], "cd") == 0)
  {
	cd(funix, argCount, arguments);
	return 1;
  }
  else if(strcmp(arguments[0], "umask") == 0)
  {
	umask(funix, argCount, arguments);
	return 1;
  }
  else if(strcmp(arguments[0], "exit") == 0)
	return(eXit(funix, argCount, arguments));
  else
  {
	printf("%s: Command not found.\n", arguments[0]);
	return 1;
  }

  return 0;
} // processCommand()

void run(Funix *funix) // reads and processes commands in a loop until exit
{
  int flag = 1;
  char *command = (char*) malloc((sizeof(char)) * COMMAND_LENGTH);

  init(funix);

    // loop and increment time until processCommand() returns 0
  do
  {
	getCommand(funix, command);
	funix->time++;
	flag = processCommand(funix, command);
  } while(flag != 0);
  return;
} // run()

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
