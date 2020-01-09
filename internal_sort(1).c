#include <stdio.h>
#define MAX_SIZE 66

int list[MAX_SIZE];

int main(void)
{
   int i, j, k, key;
   int run;
   int record;
   int cnt = 0;
   int memory[6][11] = { 0, };
   for (i = 0; i < MAX_SIZE; i++) {
      scanf("%d", &list[i]);
   }
   printf("=================================================\n");
   for (run = 0, record = 0; run < 6; run++) {
      printf("·± %d : ", run + 1);

      while (memory[cnt] != NULL && record != 11) {
        memory[run][record] = list[cnt];
         cnt = cnt + 1;
         record = record + 1;
      }

      for (j = 1; j < 11; j++) {
         key = memory[run][j];
         for (k = j - 1; k >= 0 && memory[run][k] > key; k--) {
            memory[run][k + 1] = memory[run][k];
         }
         memory[run][k + 1] = key;
      }

      for (record = 0; record < 11; record++) {
         printf("%4d", memory[run][record]);
      }

      printf("\n");
      record = 0;

   }
   scanf("%d", &list);
}
