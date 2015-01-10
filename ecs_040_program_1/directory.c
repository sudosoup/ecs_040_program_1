#include <stdio.h>
#include <stdlib.h>

#include "funix.h"
#include "directory.h"

void createDirectory(Directory *rootDirectory, int umask)
{
  rootDirectory = (Directory*) malloc(sizeof(Directory));
  rootDirectory->name = (char*) malloc(sizeof(char) * COMMAND_LENGTH);
  rootDirectory->subdirectories = (Directory**) malloc(sizeof(Directory*) * MAX_SUBDIRECTORIES);
  rootDirectory->name[0] = '/';
  rootDirectory->numSubdirectories = 0;
  rootDirectory->parentDirectory = NULL;
  rootDirectory->permissions.permissions = umask;

  return;
} // createDirectory()

  // recursively prints the path of current directory
void showPath(Directory *currentDirectory)
{
  if(currentDirectory->parentDirectory == NULL)
  {
    printf("/");
    return;
  }
  else
  {
	showPath(currentDirectory->parentDirectory);
    printf("%s", currentDirectory->name);
  }
  return;
} // showPath
