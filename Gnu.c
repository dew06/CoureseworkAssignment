#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to convert CSV to TSV format
void csv_to_tsv(const char* input_file, const char* output_file) {
    FILE* in_file = fopen(input_file, "r");
    FILE* out_file = fopen(output_file, "w");
    char line[MAX_LINE_LENGTH];

    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    while (fgets(line, sizeof(line), in_file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            fprintf(out_file, "%s\t", token);
            token = strtok(NULL, ",");
        }
        fprintf(out_file, "\n");
    }

    fclose(in_file);
    fclose(out_file);
}

int main() {
    const char* input_file ;
    const char* output_file = "output.tsv";
    printf("Enter the csv file you want to convert: ");
    scanf("%s",input_file);

    csv_to_tsv(input_file, output_file);
    printf("File converted successfully!.\nThe new file will be saved as %s",output_file);

    return 0;
}
