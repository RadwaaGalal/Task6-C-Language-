#include <stdio.h>
#include <stdlib.h>
//function to read from the file
void Reading(char *sample[])
{
    FILE *f = fopen("sample.txt" , "r");
    printf("File opened successfully \n\nString input from file: ");
    while(!feof(f))
    {
        fgets(sample, 100, f);
        puts(sample);
    }
}
//function to reverse the words from file and print it
void Reversing(char sample[])
{
    Reading(sample);
    int i;
    printf("\nReversed string: ");
    for(i=12 ; i>=0 ; i--)
    {
       printf("%c",sample[i]);
    }
}
//function to print the reverse into the file
void Writing(char sample[])
{
    Reversing(sample);
    FILE *f = fopen("sample.txt" , "w");
    int i;
    for(i =0; i<=12 ;i++)
    {
      fprintf(f, "%c", sample[i]);
    }

    for(i =12; i>=0 ;i--)
    {
      fprintf(f, "%c", sample[i]);
    }
    printf("\n\nthe reversing string is added to the file successfully\n");
}

int main()
{
    FILE *f = fopen("sample.txt" , "r");
    char *sample[12] = {0};

    Writing(sample);//function calling Reading,Reversing and writing function


    fclose(f);
    return 0;
}
