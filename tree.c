#include <dirent.h> 
#include <string.h>
#include <stdio.h> 

void walker(char* name) {

    DIR *d;

    struct dirent *dir;
    
    d = opendir(name);
    
    if (d) {
    
        while ((dir = readdir(d)) != NULL) {

        if(dir->d_type == 4 && strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name, "..") != 0) {

            printf("%s/%s\n", name, dir->d_name);

            char folder_name[1024];

            sprintf(folder_name, "%s/%s",name,dir->d_name);

            walker(folder_name);
        }
    }
    closedir(d);
  }
}

int main(int argc, char* argv[]) {

    walker(".");

    return 0;
}
