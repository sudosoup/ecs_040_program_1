#include <stdio.h>
#include <stdlib.h>

#include "funix.h"
#include "directory.h"

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
    printf("%s/", currentDirectory->name);
  }
  return;
} // showPath
