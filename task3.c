#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compressFile(const char *input, const char *output) {
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char curr, prev;
    int count = 1;

    prev = fgetc(fin);
    while ((curr = fgetc(fin)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            fprintf(fout, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }
    fprintf(fout, "%c%d", prev, count); 

    fclose(fin);
    fclose(fout);
    printf("File compressed successfully!\n");
}
void decompressFile(const char *input, const char *output) {
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    int count;

    while ((ch = fgetc(fin)) != EOF) {
        if (isalpha(ch) || ispunct(ch) || isspace(ch)) {
            fscanf(fin, "%d", &count); 
            for (int i = 0; i < count; i++) {
                fputc(ch, fout);
            }
        }
    }

    fclose(fin);
    fclose(fout);
    printf("File decompressed successfully!\n");
}
int main() {
    int choice;
    char inputFile[50], outputFile[50];

    while (1) {
        printf("\n--- RLE Compression Tool ---\n");
        printf("1. Compress File\n2. Decompress File\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter input file name: ");
                scanf("%s", inputFile);
                printf("Enter output (compressed) file name: ");
                scanf("%s", outputFile);
                compressFile(inputFile, outputFile);
                break;

            case 2:
                printf("Enter compressed file name: ");
                scanf("%s", inputFile);
                printf("Enter output (decompressed) file name: ");
                scanf("%s", outputFile);
                decompressFile(inputFile, outputFile);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
