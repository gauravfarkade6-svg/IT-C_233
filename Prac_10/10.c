#include <stdio.h>

int main() {
    FILE *fs;
    FILE *fd;
    int ch;   

    fs = fopen("file1.txt", "r");   
    fd = fopen("file2.txt", "w");

    if (fs == NULL || fd == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fs)) != EOF) {   
        fputc(ch, fd);
    }

    fclose(fs);
    fclose(fd);
    printf("Copied successfully!\n");

    return 0;
}
