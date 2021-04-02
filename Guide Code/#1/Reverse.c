#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    // FILE *fp = fopen("file.txt", "r");
    int fp1 = open("file.txt", O_RDONLY, 0);
    int fp2 = open("newfile.txt", O_WRONLY, 0);

    fseek(fp1, 0L, SEEK_END);
    int sz = ftell(fp1);

    char buffer[sz];
    char buffer2[sz];
    int a = 0;

    read(fp1, buffer, sz);

    printf("%d", sz);

    for (int i = sz - 1; i > -1; i--)
    {

        buffer2[a++] = buffer[i];
    }

    printf("file1: %s\n", buffer);
    printf("file2: %s\n", buffer2);

    write(fp1, buffer2, sizeof(fp1));

    return 0;
}

// int main(int argc, char *argv[])
// {

//     FILE *fp = fopen("file.txt", "r");
//     int fp1 = open("file.txt", O_RDONLY, 0);
//     int fp2 = open("newfile.txt", O_WRONLY, 0);
//     //printf("%d", sizeof(fp1));

//     char buffer[1000] = {NULL};
//     char buffer2[1000] = {NULL};
//     int a = 0;
//     //printf("%d\n", sizeof(buffer));
//     read(fp1, buffer, sizeof(buffer));

//     fseek(fp, 0L, SEEK_END);
//     int sz = ftell(fp);

// //srand(time(NULL));

// //for(int x = 0; x < 10; x++){

//     //int r1 = 0;
// //}
//      //printf("%d\n", sizeof(buffer) - 2);

//     for(int i = sz; i > -1; i-- ){
//         int r1 = rand()%1000;
//         printf("%d\n", r1);
//         buffer2[r1] = buffer[i];
//         //printf("%d", a);

//     }

//     write(fp1, buffer2, sizeof(fp1));

// return 0;
// }