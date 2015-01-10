// Authors: Yage Hu, Thomas Connor Campbell

#ifndef PERMISSIONS_H
#define	PERMISSIONS_H

typedef struct Permissions
{
  short permissions;
} Permissions;

Permissions createPermissions(int umask);

#endif
