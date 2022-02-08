#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{
  char str_arr[500][500]; //"string" in C max words is 500
  FILE *fptr;
  FILE *f_close;
  int words =0; //counter
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
        for(int j=i;str_arr[words][j]!='\0';++j){
          str_arr[words][j]=str_arr[words][j+1];
        }
        str_arr[words][j]='\0';
      }
    }
    words++;
}
fclose(fptr);

  //using many for loops because the array is 2D

  //I want all the letters to be in the same case so it can regognize the same words
  //for(int i=0;i<words;i++){
  //  for(int j =0; strlen(str_arr[i]);j++){
    //  str_arr[i][j]=tolower(str_arr[i][j]);
  //  }
//  }

//THIS MADE A SEGMENATION FAULT


  //count words and check for the same ones

char different_words[words][500];//new char array
//goes thorugh and checks each word using a flag and strcasecmp
int unique =0;

for(int i=0; i<words;i++){
  int flag =1;
  for(int k=0; k<unique;k++){
    if(strcasecmp(str_arr[i],different_words[k])==0){//comaprison
      flag =0;
    }
  }
  if(flag){//unique word found, put into string array
    snprintf(different_words[unique],500,"%s",str_arr[i]);
    unique++;//this is printed to file

  }

}

//finally print to file
f_close = fopen("out_better.txt","w");
fprintf(f_close,"%d",unique-1);
fclose(f_close);




    return 0;
}
