#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
using namespace std;

int main (int argc, char **argv) {
    struct stat fileStats;
    char* file = argv[1];
    int fd = open(argv[1], O_RDONLY);
    int ret = fstat(fd, &fileStats);

    if (fd == -1){
        perror("fstat");
        system("pause");
        exit(1);
    }
    if (ret < 0){
        return 1;
    }
    //int inode = get_inode(fd);
    int inode = fileStats.st_ino;
    int size = fileStats.st_size;
    int fileType = fileStats.st_mode;


    printf("Inode number: %d\n",inode);
    printf("Total Size: %d\n",size);
    cout << "File Type: %d\n" << fileType;
    return 0;
 }