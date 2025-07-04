#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];
    fp = fopen("myfile.txt", "w");  // "w" mode creates a file if it doesn't exist
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }
    printf("Enter data to write to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written successfully.\n");
    fp = fopen("myfile.txt", "a");  // "a" mode opens file for appending
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return 1;
    }
    printf("Enter data to append to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended successfully.\n");
    fp = fopen("myfile.txt", "r");  // "r" mode opens file for reading
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("Reading data from file:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }
    fclose(fp);

    return 0;
}
