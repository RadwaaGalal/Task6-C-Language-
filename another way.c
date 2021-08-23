#include <stdio.h>
#include <stdlib.h>
//function to read from the file
void Reading(char sample[])
{
    FILE *f = fopen("file.txt" , "r");
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
    char *first , *last ,temp;
    first = &sample[0];
    last = &sample[4];
    int i;
    printf("\nReversed string: ");
    while(first != last)
    {
       temp = *last;
       *last = *first;
       *first = temp;
       first++;
       last--;
    }
    printf("%s",sample);
}
//function to print the reverse into the file
void Writing(char sample[])
{
    Reversing(sample);
    FILE *f = fopen("file.txt" , "w");
    int i=0;
    while(i<5)
    {
      fprintf(f, "%c", sample[i]);
      i++;
    }
    printf("\n\nthe reversing string is added to the file successfully\n");
}

int main()
{
    FILE *f = fopen("file.txt" , "r");
    char sample[5] = {0};
    Writing(sample);//function calling Reading,Reversing and writing function


    fclose(f);
    return 0;
}
