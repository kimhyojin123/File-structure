#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 66

int main(void){
   int i, j, k, temp;
   int data[MAX_SIZE];
   int run[MAX_SIZE];
   int buffer[6];
   int frozen[6]; 

   for (i = 0; i < MAX_SIZE; i++) {
      scanf("%d", &data[i]);
   }

   for (i = 0; i < 6; i++) {
      frozen[i] = 1;
   }

   printf("================================\n");
   
    
   for (i = 0; i < 6; i++) {
      buffer[i] = data[i];
   }


   for (i = 0; i < MAX_SIZE; i++) {
      if (!frozen[0] && !frozen[1] && !frozen[2] && !frozen[3] && !frozen[4] && !frozen[5]) {  
         for (j = 0; j < 6; j++) {
         	frozen[j] = 1;
		 }
      }
	temp = INT_MAX;
      for (j = 0; j < 6; j++) {  
         if (!frozen[j]) {
         	continue;
		 } 
         if (temp > buffer[j]) {
            temp = buffer[j];
            k = j;
         }
      }
	run[i] = buffer[k];
      if (i + 6 >= MAX_SIZE) {
         frozen[k] = 0;
         continue;
      }

      if (buffer[k] > data[i + 6]) { 
         buffer[k] = data[i + 6];
         frozen[k] = 0;
      }
      else {
         buffer[k] = data[i + 6]; 
      }
   }

   j = 1;
   for (i = 0; i < MAX_SIZE; i++) {
      if (i == 0){
	  	printf("\n ·± %d\t: ", j++);
	  	
      }
      if (i != 0 && run[i] < run[i - 1]) {
        printf("\n ·± %d\t: ", j++);
      }
      printf("%d ", run[i]);
   }

   scanf("%d", &data[i]);
}
