// Authors: Yage Hu, Thomas Connor Campbell
#ifndef DIRECTORY_H
#define DIRECTORY_H

#define COMMAND_LENGTH 80
#define MAX_SUBDIRECTORIES 3

#include "permissions.h"

typedef struct Directory
{
  char *name;
  int timeMod;
  int numSubdirectories;
  struct Directory *parentDirectory;
  struct Permissions permissions;
  struct Directory **subdirectories;
} Directory;

void showPath(Directory *currentDirectory);

#endif
