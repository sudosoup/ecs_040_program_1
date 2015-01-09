// Authors: Yage Hu, Thomas Connor Campbell
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "permissions.h"

typedef struct Directory
{
  char *name;
  int timeMod;
  int numSubdirectories;
  struct Directory *parentDirectory;
  struct Permissions permissions;
  struct Directory *subdirectories[];
} Directory;

#endif
