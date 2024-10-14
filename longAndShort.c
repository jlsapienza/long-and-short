#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Please supply one file to read from and two files to write to");
        exit(1);
    }

    char line [SIZE];

    int countS = 0;
    int countL = 0;
    

    FILE *in = fopen(argv[1], "r");
    FILE *sh = fopen(argv[2], "w");
    FILE *lo = fopen(argv[3], "w");

    while (fgets(line, SIZE, in) != NULL)
    {
        size_t length = strlen(line);
        //printf("%lu\n", length);

        if(line[length - 1] == '\n')
        {
            length--;
        }


        if (length < 20)
        {

            for (int i = 0; line[i]!='\0'; i++) 
            {
                if(line[i] >= 'a' && line[i] <= 'z') 
                {
                    line[i] = line[i] - 32;
                }
            }
            fprintf(sh,"%s", line);
            countS++;
        }
        else
        {
            for (int i = 0; line[i]!= '\0'; i++)
            {
                if(line[i] >= 'A' && line[i] <= 'Z') 
                {
                    line[i] = line[i] + 32;
                }
            }
            
            fprintf(lo,"%s", line);
            countL++;
        }
    }
    printf("%d lines written to short.txt\n", countS);
    printf("%d lines written to long.txt\n", countL);

    fclose(in);
    fclose(sh);
    fclose(lo);
}