#include <stdio.h>
#include <stdbool.h>

bool addFile(const char *filename, int *sum)
{
   // You cannot assume *sum is zero. Thus, *sum needs to be set 0
   *sum = 0; 
   // open a file whose name is filename for reading
   FILE *file = fopen(filename, "r");
   // if fopen fails, return false. Do NOT fclose
   if (!file) 
   {
      return false;
   }

   // if fopen succeeds, read integers using fscanf (do not use fgetc)
   int num;
   while (fscanf(file, "%d", &num) == 1) 
   {
      *sum += num;
   }

   // *sum stores the result of adding all numbers from the file
   // When no more numbers can be read, fclose, return true
   fclose(file);
   return true;
}

bool writeSum(const char *filename, int sum)
{
   // open a file whose name is filename for writing
   FILE *file = fopen(filename, "w");
   // if fopen fails, return false
   if (!file) 
   {
     return false;
   }

   // if fopen succeeds, write sum as an integer using fprintf
   // fprintf should use one newline '\n'
   fprintf(file, "%d\n", sum);
   // fclose, return true
   fclose(file);
   return true;
}
