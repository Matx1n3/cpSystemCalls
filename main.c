#include <sys/fcntl.h>
#include <unistd.h>


void print(char text[], int size){
    write(STDOUT_FILENO, text, size);
}


int main(int argc, char *argv[]) {

    //  If argc != 3 reject
    if (argc != 3) {
        print("Please enter the file you want to copy and the file where you want to copy it\n", 78);
        return 0;
    }

    //  Open the file copyFrom
    int copyFrominodeNum = open(argv[1], O_RDONLY);

    //  Open the file copyTo
    int copyToinodeNum = open(argv[2], O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

    //  Make sure that the copyFrom file exists
    if (copyFrominodeNum == -1) {
        print("The specified file doesn't exist\n", 33);
        return 0;
    }

    //  Make sure there hasn't been any problem with copyTo
    if (copyToinodeNum == -1){
        print("Something went wrong\n", 21);
        return 0;
    }

    //  Copy the data
    char ch;
    while (read(copyFrominodeNum, &ch, 1)) {
        write(copyToinodeNum, &ch, 1);
    }

    // Close files
    close(copyFrominodeNum);
    close(copyToinodeNum);

    //  Successful message
    print("Successfull\n", 12);
}

