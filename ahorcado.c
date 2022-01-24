#include<stdio.h>
#include<string.h>

int main() {
    char frase[60],rep[100],temporal[100],nombre[100],letras[100];
    char pal;
    int longitud,i,j,inicial,acertado=0,temp=0,oportunidades=6,intentos=0;
    int repetido=0,gano=0;
   
    printf("\t Ahorcado :) \n");
    printf("Introduzca la palabra a adivinar: ");
    gets(frase);
   
    system("cls");
   
    longitud = 0;
    inicial = 0;
    j = 0;
   
    rep[0] = ' ';
    rep[1] = '\0';

    printf("Ingrese su nombre: \n");
    scanf("%s",nombre);

   
    do {
                system("cls");
        temp=0;
        intentos++;
        
       
   
        if(inicial == 0) {
         for(i=0;i<strlen(frase);i++) {
          if(frase[i] == ' ') {
            temporal[i] = ' ';
             longitud++;
          }
          else {
             temporal[i] = '_';       
             longitud++;
          }
         }
        }
   
        inicial = 1;
       
        temporal[longitud] = '\0';
       
        for(i=0;i<strlen(rep);i++) {
           if(rep[i] == pal) {
            repetido = 1;
            break;
          }
          else {
           repetido = 0;
         }
        }
       
        if(repetido == 0) {
         for(i=0;i<strlen(frase);i++) {
                    if(frase[i] == pal) {
             temporal[i] = pal;
              acertado++;
              temp=1;
            }
          }
        }
       
        if(repetido ==0 ) {
         if(temp == 0) {
           oportunidades = oportunidades - 1;
         }
        }
        else {
         printf("Ya se ha introducido esta letra ");
         printf("\n\n");
        }
       
        printf("\n");
       
        for(i=0;i<strlen(temporal);i++) {
         printf(" %c ",temporal[i]);
        }
       
        printf("\n");
       
        if(strcmp(frase,temporal) == 0) {
            gano = 1;
            break;
        }
       
        printf("\n");
        printf("Letras Acertadas: %d",acertado);
        printf("\n");
        printf("vidas: %d",oportunidades);
        printf("\n");
   
        rep[j] = pal;
        j++;
       
        if (oportunidades==0)
        {
           break;
        }
     
        printf("Introduzca una letra:");
        scanf("\n%c",&pal);
        
    }while(oportunidades != 0);
   
   
    if(gano) {
    	
		FILE *FileWrite =fopen("Ahorcado.txt","a");
		fprintf(FileWrite,"Nombre: %s Resultado: %s palabra: %s Intentos: %d \n",nombre,"gano",frase,intentos-1);
		fclose(FileWrite);
    	printf("\n\n");
        printf("¡FELICITACIONES,GANASTE!");
        
    }
    else {
    	
    	FILE *FileWrite =fopen("Ahorcado.txt","a");
		fprintf(FileWrite,"Nombre: %s Resultado: %s palabra: %s Intentos: %d \n",nombre,"perdio",frase,intentos-1);
		fclose(FileWrite);
        printf("\n\n");
        printf("¡ OH NO HAS PERDIDO !, INTENTALO DE NUEVO");
    }
   
    printf("\n\n");
    system("PAUSE");
    return 0;

} 
