#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

  int i=0;
  int p=0;// palabras
  int l=0;// letras
  int o=0;// oraciones
  int L=0;// cantidad de letras cada 100 palabras
  int S=0;// cantidad de oraciones cada 100 palabras 
while (text[i] != '\0')   
  
  if (isalpha(text[i])) {
      l++;
  }
  if(isspace(text[i])) {
      p++;
  }
  
  if(text[i]=='.'||text[i]=='!'||text[i]=='?') {
      o++;


  }
  
  i++;

     L=(l* 100) /p;
     S=(o*100) /p; 
    
    index = 0.0588 * L - 0.296 * S - 15.8
    round(index);
    if (index<1) {
        printf("Before Grade 1");
    }
    else if (index>16) {
        printf("Grade 16+");
    }
    if (index<1 && index>16)
    {  
        printf("Before Grade" index);
    }
    return 0;
}


int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
