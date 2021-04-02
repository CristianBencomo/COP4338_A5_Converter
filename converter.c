#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>

#define MAX_ROW 1000//input file will have less than or equal to 1000 lines
#define MAX_LEN 1000
#define MAX_TOKEN 100
#define TRUE 1
#define FALSE 0
#define INPUT_LENGTH 100

// Function that scans input dynamically to a pointer
char *dynamicScan(char *str)
{
    int ch; //character
    str = malloc(sizeof(char)); //allocate str

    for(int i = 0; i < INPUT_LENGTH && (ch = getchar()) != '\n'; i++)
    {
        str = realloc(str, (i+2)*sizeof(char)); //reallocate as characters are taken in
        str[i] = (char) ch;
        str[i+1] = '\0';
    }

    return str; //return final string
}

char *fileExtension(const char *fileType)
{
    int length = strlen(fileType);

    return (char *)&fileType[length - 3];
}

char* trim(char* token) 
{
	if (!token)//error checking
		return NULL;
	int i = 0;
	while (*token == ' ')//remove leading spaces
		token++;
	for (i = strlen(token) - 1; i >= 0 && token[i] == ' '; i--);//remove trailing spaces
		token[i + 1] = '\0';
	return token;
}


void csvToTl5(FILE *input, FILE *output)
{
	int dataIndex = 0;
	char* data[MAX_ROW];// will store the file content
	char* token;
	char line[MAX_LEN];//temporary placeholder for a line input from the file
	
	for (int i = 0; fscanf(input, "%[^\n]\n", line) != EOF; i++) 
    {
		data[dataIndex] = (char*)malloc(strlen(line) + 1);//+1 for \0
		strcpy(data[dataIndex++], line);
	}
	
	for (int i = 0; i < dataIndex; i++) 
	{
		token = strtok(data[i], ",");//tokenizes the ith row stored in data[i] and trims it
		fprintf(output, "%-5.5s", token);
		while (token = trim(strtok(NULL,",")))
			fprintf(output, "|%-5.5s", token);
		fprintf(output, i == dataIndex - 1 ? "" : "\n");
	}
}

void tl5ToCsv(FILE *input, FILE *output)
{
    int dataIndex = 0;
    char *data[MAX_ROW];
    char *token;
    char line[MAX_LEN];

    for(int i=0; fscanf(input, "%[^\n]\n", line) != EOF; i++)
    {
        data[dataIndex] = (char*)malloc(strlen(line) + 1);
        strcpy(data[dataIndex++], line);
    }

    for (int i = 0; i<dataIndex; i++)
    {
        token = trim(strtok(data[i], "|"));
        fprintf(output, "%-5s", token);
        while (token = trim(strtok(NULL, "|")))
            fprintf(output, ",%-5s", token);
        fprintf(output, i == dataIndex - 1 ? "" : "\n");
    }
}


main() 
{
	FILE *finput;
	FILE *foutput;

	int wantToExit = FALSE;
    
    
    do
    {
        
        printf("Please enter a command...\nExample:\n");
        printf("xxxx.ext yyyy.ext\n");
        char *input;
        char *str;
        input = dynamicScan(str);
        // free(str);

        // Initiating token
        char *token = strtok(input, " \0");

        char *filename_in, *filename_out;


        filename_in = token;
        token = strtok(NULL, " \0");
        filename_out = token;


        char *infile_ext = fileExtension(filename_in);
        char *outfile_ext = fileExtension(filename_out);
        
        if(strcasecmp(infile_ext, "csv") == 0 && strcasecmp(outfile_ext, "tl5") == 0) // csv to tl5
        {
            finput = fopen(filename_in, "r");
            foutput = fopen(filename_out, "w+");
            printf("Converting from .csv to .tl5\n");
            csvToTl5(finput, foutput);
            printf("Conversion finished\n\n");
        }
        else if(strcasecmp(infile_ext, "tl5") == 0 && strcasecmp(outfile_ext, "csv") == 0)
        {
            finput = fopen(filename_in, "r");
            foutput = fopen(filename_out, "w+");
            printf("Converting from .tl5 to .csv\n");
            tl5ToCsv(finput, foutput);
            printf("Conversion finished\n\n");
        }
        else
        {
            printf("Incorrect command, please enter a valid command\n");
        }

    fclose(finput);
    fclose(foutput);

        // Ask user if they want to run the program again
    } while (!wantToExit);    

}
