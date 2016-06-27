#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    dir = opendir("../assets");
    while ((dp=readdir(dir)) != NULL)
    {
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
            // do nothing (straight logic)
        }
        else
        {
            file_name = dp->d_name; // use it
            cout << "file_name: \"" << file_name << "\"" << endl;;
        }
    }
    closedir(dir);
    return 0;
}