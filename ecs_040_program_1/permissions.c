// Authors: Yage Hu, Thomas Connor Campbell

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "permissions.h"

Permissions createPermissions(int umask)
{
  Permissions permissions;
  permissions.permissions = umask;

  return permissions;
} // createPermissions()

void printPermissions(Permissions *permissions)
{
	// if the read permission is set, print "r"
  if(permissions->permissions > 3)
    printf("r");
  else // if the read permission is not set, print "-"
	printf("-");

    // if the write permission is set, print "w"
  if(permissions->permissions == 2 ||
    permissions->permissions == 3 ||
	permissions->permissions == 6 ||
	permissions->permissions == 7)
    printf("w");
  else // if the write permissions is not set, print "-"
	printf("-");

    // if the execute permission is set, print "x"
  if(permissions->permissions == 1 ||
    permissions->permissions == 3 ||
	permissions->permissions == 5 ||
	permissions->permissions == 7)
	printf("x");
  else
	printf("-");

  return;
} // printPermissions()
