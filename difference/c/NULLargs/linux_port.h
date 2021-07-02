/*
 * linux porting header
 *
 */

#ifndef _LINUX_PORT_H

#define _LINUX_PORT_H 1

/*
 * fix for NULL argument of systemcall
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define atoi(a)   ((a) == NULL ? 0 : atoi((a)))
#define atol(a)   ((a) == NULL ? 0 : atol((a)))
#define atoll(a)   ((a) == NULL ? 0 : atoll((a)))
#define strcpy(a, b)  (strcpy((a), (b) == NULL ? "" : (b)))
#define strncpy(a, b, c) (strncpy((a), (b) == NULL ? "" : (b), (c)))
#define strlen(a)   ((a) == NULL ? 0 : strlen((a)))
#define memcpy(a,b,c) ((b) == NULL ? memset((a), 0, (c)) : memcpy((a),(b),(c)))
#define strcmp(a, b) (strcmp((a) == NULL ? "" : (a), (b) == NULL ? "" : (b)))
#define strncmp(a, b, c)  (strncmp((a) == NULL ? "" : (a), (b) == NULL ? "" : (b), (c)))
#define memcmp(a, b, c)  (memcmp((a) == NULL ? "" : (a), (b) == NULL ? "" : (b), (c)))
#define memset(a, b, c)   ((a) == NULL ? NULL : memset((a), (b), (c)))
#define strcat(a,b) (strcat((a), (b) == NULL ? "" : (b)))
#define strncat(a,b,c) (strncat((a), (b) == NULL ? "" : (b), (c)))
#define strchr(a,b) ((a) == NULL ? NULL : strchr((a),(b)))
#define strrchr(a,b) ((a) == NULL ? NULL : strrchr((a),(b)))
#define strstr(a,b) (((a) == NULL || (b) == NULL) ? (a) : strstr(a,b) )
#define feof(a) ((a) == NULL ? 0 : feof((a)))
#define ferror(a) ((a) == NULL ? 0 : ferror((a)))
#define fileno(a) ((a) == NULL ? 0 : fileno((a)))
#define fseek(a,b,c) ((a) == NULL ? -1 : fseek((a),(b),(c)))
#define readdir(a) ((a) == NULL ? NULL : readdir((a)))

extern int _linux_port_fclose(FILE **);
#define fclose(a) _linux_port_fclose(&(a))

#endif /* _LINUX_PORT_H */
