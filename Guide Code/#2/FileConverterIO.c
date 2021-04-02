#include <stdio.h>
#include <string.h>

int i;
char c[50];
char d;
char a[5];

char *fileExtension(const char *fileType)
{
    int length = strlen(fileType);

    return (char *)&fileType[length - 3];
}

void csvToTL5(FILE *fp1, FILE *fp2)
{

    while (1)
    {

        fscanf(fp1, "%[^\n,]", c);
        d = fgetc(fp1);
        strncpy(a, c, 5);
        for (i = 0; a[i] != '\0'; i++)
        {
            if (a[i] == ' ')
            {

                for (int j = i; a[j] != '\0'; j++)
                    a[j] = a[j + 1];
                i--;
            }
        }

        if (feof(fp1))
            break;
        else
        {

            //printf("Word: %s Length: %d\n", a, strlen(a));
            fprintf(fp2, "%s", a);

            if (strlen(a) < 5)
            {
                for (i = 0; i < 5 - strlen(a); i++)
                {
                    fprintf(fp2, " ");
                }
            }

            if (d == ',')
                fprintf(fp2, "|");
            else
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    return;
}

void tl5ToCSV(FILE *fp1, FILE *fp2)
{
    while (1)
    {
        fscanf(fp1, "%[^\n|]", c);

        d = fgetc(fp1);

        if (feof(fp1))
            break;
        else
        {
            strncpy(a, c, 5);
            //printf("Word: %s Length: %d\n", a, strlen(a));
            fprintf(fp2, "%s", a);

            if (d == '|')
                fprintf(fp2, ",");
            else
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    return;
}

void tr9ToCSV(FILE *fp1, FILE *fp2)
{

    while (1)
    {

        fscanf(fp1, "%[^\n|]", c);
        d = fgetc(fp1);

        strcpy(a, c);

        if (feof(fp1))
        {

            break;
        }
        else
        {

            fprintf(fp2, "%s", a);

            if (d == '|')
                fprintf(fp2, ",");
            else
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    return;
}

void tr9ToTL5(FILE *fp1, FILE *fp2)
{
    while (1)
    {
        fscanf(fp1, "%[^\n|]", c);

        d = fgetc(fp1);
        strncpy(a, c, 5);
        //printf("%s", a);

        for (i = 0; a[i] != '\0'; i++)
        {
            if (a[i] == ' ')
            {

                for (int j = i; a[j] != '\0'; j++)
                    a[j] = a[j + 1];
                i--;
            }
        }

        if (feof(fp1))
            break;
        else
        {

            fprintf(fp2, "%s", a);

            if (strlen(a) < 5)
            {
                for (i = 0; i < 5 - strlen(a); i++)
                {
                    fprintf(fp2, " ");
                }
            }

            if (d == '|')
                fprintf(fp2, "|");
            else
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);

    return;
}
void csvToTR9(FILE *fp1, FILE *fp2)
{
    while (1)
    {

        fscanf(fp1, "%[^\n,]", c);
        d = fgetc(fp1);
        strncpy(a, c, 9);

        if (feof(fp1))
            break;
        else
        {

            if (strlen(a) < 9)
            {
                for (i = 0; i < 9 - strlen(a); i++)
                {
                    fprintf(fp2, " ");
                }
            }

            fprintf(fp2, "%s", a);

            if (d == ',')
                fprintf(fp2, "|");
            else
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);

    return;
}
void tl5ToTR9(FILE *fp1, FILE *fp2)
{
    int x = 0;
    while (1)
    {

        fscanf(fp1, "%[^\n|]", c);
        d = fgetc(fp1);

        strncpy(a, c, 9);

        for (i = strlen(a) - 1; i > 0; i--)
        {
            if (a[i] == ' ')
            {

                for (int j = i; j > 0; j--)
                {
                    a[j] = a[j - 1];
                }
                a[x] = ' ';

                i++;
            }
            else
                break;
        }

        if (feof(fp1))
            break;
        else
        {
           

            if (strlen(a) < 9)
            {
                for (i = 0; i < 9 - strlen(a); i++)
                {
                    fprintf(fp2, " ");
                }
            }

            fprintf(fp2, "%s", a);

            if (d == '|')
                fprintf(fp2, "|");
            else
                fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    return;
}

int main(int argc, char *argv[])
{

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w+");

    char *fileName1 = argv[1];
    char *fileName2 = argv[2];

    printf("%s\n", fileExtension(fileName1));
    printf("%s\n", fileExtension(fileName2));
    char *a = fileExtension(fileName1);
    char *b = fileExtension(fileName2);

    //Conversion from CSV to TL5
    if (a[0] == 'c' && a[1] == 's' && a[2] == 'v' && b[0] == 't' && b[1] == 'l' && b[2] == '5')
    {
        csvToTL5(fp1, fp2);
    }
    //Conversion from TL5 to csv
    else if (a[0] == 't' && a[1] == 'l' && a[2] == '5' && b[0] == 'c' && b[1] == 's' && b[2] == 'v')
        tl5ToCSV(fp1, fp2);

    //Conversion from TR9 to CSV
    else if (a[0] == 't' && a[1] == 'r' && a[2] == '9' && b[0] == 'c' && b[1] == 's' && b[2] == 'v')
        tr9ToCSV(fp1, fp2);

    //Conversion from TR9 to TL5
    else if (a[0] == 't' && a[1] == 'r' && a[2] == '9' && b[0] == 't' && b[1] == 'l' && b[2] == '5')
        tr9ToTL5(fp1, fp2);

    //Conversion from CSV to TR9
    else if (a[0] == 'c' && a[1] == 's' && a[2] == 'v' && b[0] == 't' && b[1] == 'r' && b[2] == '9')
        csvToTR9(fp1, fp2);

    //Conversion from  TL5 to TR9
    else if (a[0] == 't' && a[1] == 'l' && a[2] == '5' && b[0] == 't' && b[1] == 'r' && b[2] == '9')
        tl5ToTR9(fp1, fp2);

    //print on console to check converted file
    
    rewind(fp2);

    fclose(fp2);
    printf("The File Conversion is Successful!");
    return 0;
}
