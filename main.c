#include <stdio.h>
#include <stdlib.h>
int MAXSIZE = 64;          
int top = -1;            

int init()
{
 int n;
 printf("Podaj wielkość stosu, maksymalna wielkość to 64\n");
 scanf("%d",&n);
 if(n > 64)
 {
   printf("Podano za dużą wielkość stosu");
 return -1;
 }
 else{
   return n;
 }
}

int isEmpty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isFull(int k) {

   if(top == k)
      return 1;
   else
      return 0;
}

char pop(char stack[]) {
   char data;
   if(!isEmpty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Nie moge pobrać litery, stos jest pusty.\n");
   }
}

char push(char data, char stack[], int k) {

   if(!isFull(k)) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Nie mogę dodac więcej liter, stos jest pełny.\n");
   }
}

void finish(char *stack){
  free(stack);
}

int main(void) {

  int k = init();
  char *stack = malloc( sizeof(*stack) * k );
  //char stack[k];
  int i;
  char arrayOfWords[] = "axolotl";
  int elements_in_arr = sizeof(arrayOfWords) / sizeof(arrayOfWords[0]); 
  for(i = 0; i< elements_in_arr; i++)
  {
    push(arrayOfWords[i], stack, k);
  }

   while(!isEmpty()) {
      char data = pop(stack);
      printf("%s\n",&data);
   }
   printf("Czy stos jest pełny : %s\n" , isFull(k)?"Tak":"Nie");
   printf("Czy stos pusty : %s\n" , isEmpty()?"Tak":"Nie");
   finish(stack);
   return 0;
}
