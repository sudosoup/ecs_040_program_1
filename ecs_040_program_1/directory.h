// Authors: Yage Hu, Thomas Connor Campbell
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "permissions.h"

#define COMMAND_LENGTH 80
#define MAX_SUBDIRECTORIES 3

typedef struct Directory
{
  char *name;
  int timeMod;
  int numSubdirectories;
  struct Directory *parentDirectory;
  struct Permissions permissions;
  struct Directory *subdirectories[];
} Directory;

void createDirectory(Directory *rootDirectory, int umask);
void showPath(Directory *currentDirectory);

#endif
