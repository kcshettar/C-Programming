#ifndef status_h
#define status_h

#include <stdlib.h>
#include <stdio.h>

enum status 
{ 
	FAILURE, SUCCESS
};
typedef enum status Status;

enum boolean 
{ 
	FALSE, TRUE 
};
typedef enum boolean Boolean;

enum position 
{ 
	LEFT, RIGHT 
};
typedef enum position Position;

#endif