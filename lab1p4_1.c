
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{

  char str_arr[500][500]; //"string" in C max words is 500
  FILE *fptr;
  FILE * f_close;
  int words =0; //counter
  printf("%d", words);
  fptr = fopen("c_test1.txt", "r");
  if(!fptr){
    perror("fopen");//for permission
  }
  if(fptr==NULL){
    printf("File does not exist");
  }

  while(!feof(fptr)){ //reading from file to an arry with while loop bc word count is unknown
    fscanf(fptr,"%s",str_arr[words]);
  //remove all non alphanumeric characters from the array that I just read in (I used an internet reference)
  for(int i=0,j;str_arr[words][i]!='\0';++i){
    //goes to loop if not alphabetical or NULL
    while(!(str_arr[words][i]>='a' && str_arr[words][i]<='z')&&!(str_arr[words][i]>='A'&&str_arr[words][i]<='Z')&& !(str_arr[words][i]=='\0')){
      //if not in the alphabet move
      for(j=i;str_arr[words][j]!='\0';++j){
        str_arr[words][j]=str_arr[words][j+1];
      }
      str_arr[words][j]='\0';
    }
  }
  words++;
}
fclose(fptr);
  //using many for loops because the array is 2D
  f_close = fopen("out.txt","w");
  fprintf(f_close,"%d",words-1);
  fclose(f_close);

    return 0;
}
