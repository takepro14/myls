#include "myls.h"
#include <dirent.h> // opendir, readdir, closedir
#include <stdio.h>
#include <stdlib.h>
#include <string.h>   // strcmp
#include <sys/stat.h> // stat

void myls(void) {
  DIR *dp;
  struct dirent *entry;

  dp = opendir(".");
  if (dp == NULL) {
    perror("opendir");
    return;
  }

  while ((entry = readdir(dp)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    struct stat st;
    if (stat(entry->d_name, &st) == -1) {
      perror("stat");
      continue;
    }

    if (S_ISDIR(st.st_mode))
      printf("%s/\n", entry->d_name);
    else
      printf("%s\n", entry->d_name);
  }

  closedir(dp);
}
