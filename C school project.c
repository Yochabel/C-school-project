#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Funciones
void loopMenu();
int menu();
void getTxt();
void statistics();
void pronombres();
void capLtr();
void ndoVerb();
void search();
void swap();
void min(char* txt);

char paragraph[255];

int main(){
    printf("\nBienvenido al programa\n");
    loopMenu();
    return 0;
}
//Desplegar el menu
void loopMenu(){
    char array[255];
    int opc;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                getTxt();
                break;
            case 2:
                statistics();
                break;
            case 3:
                pronombres();
                break;
            case 4:
                capLtr();
                break;
            case 5:
                ndoVerb();
                break;
            case 6:
                search();
                break;
            case 7:
                swap();
                break;
            case 8:
                printf("Gracias por usar el programa");
                break;
            default:
                printf("\nEsta opcion no es valida, vuelva a intentarlo.\n");
                break;
        }
    } while (opc != 8);
}
//Menu del programa
int menu(){
    int opc;

    printf("\nSeleccione una opcion valida:\n"
            "1)Introducir texto (hasta 255 caracteres)\n"
           "2)Desplegar estadisticas\n"
           "3)Desplegar los pronombres encontrados\n"
           "4)Desplegar todas las palabras que comienzan con mayusculas\n"
           "5)Desplegar los verbos en gerundio\n"
           "6)Buscar una palabra en el texto\n"
           "7)Intercambiar mayusculas y minusculas\n"
           "8)Salir\n"
           "\n"
           "Opcion: ");
    scanf("%d", &opc);
    return opc;
}
//Función para imprimir el texto ingresado
void getTxt(){
    printf("Ingrese el texto (limite de hasta 255 caracteres): ");
    fgets(paragraph,255,stdin);
    fgets(paragraph,255,stdin);
    printf("El texto que ingresaste es: ");
    printf("%s",paragraph);
}
//Funión para imprimir la cantidad de vocales, espacios y parrafos
void statistics(){
    char caracter[255];

    strcpy(caracter, paragraph);

    int longitud = strlen(caracter);
    int cantidadvocales=0,contadorespacios=0,contadorparrafos=0;
    int i,letras,consonantes;

    for(i=0;i<=longitud;i++){
        if(caracter[i]==' ') contadorespacios++;
        if(caracter[i]=='a'||caracter[i]=='e'||caracter[i]=='i'||caracter[i]=='o'||caracter[i]=='u') cantidadvocales++;
        if(caracter[i]== '.') contadorparrafos++;
    }
    letras = longitud - contadorespacios;
    consonantes = letras - cantidadvocales;
    printf("Cantidad de letras: %d",letras);
    printf("\nCantidad de vocales: %d",cantidadvocales);
    printf("\nCantidad de consonantes: %d",consonantes);
    printf("\nCantidad de parrafos: %d",contadorparrafos);
}
//Función para encontrar la cantidad de pronombres
void pronombres(){
    char pal[255];

    strcpy(pal, paragraph);

    min(pal);
    const char* arr[]={"yo","tu","el","ella","nosotros","nosotras","ustedes","vosotros","vosotras","ellos","ellas"};char *res= NULL;
    int pro=0;
    const char s[2] = " ";
    char *token;

    token = strtok(pal, s); //divide la cadena str en una serie de tokens

        while( token != NULL ) {
            for(int i=0 ; i < 11 ; i++){
                res = strstr(token,arr[i]);
                if(res){
                    printf(token);
                    printf("\n");
                    pro++;
                }
            }
            token = strtok(NULL, s);
        }
        printf("\nEl numero de pronombres es de: %i\n",pro);
    }
//Función para mostrar las palabras que empiecen en mayusculas
void capLtr(){
    char array[255];

    strcpy(array, paragraph);

    const char s[2] = " ";
    char *token;

    token = strtok(array, s);

    while( token != NULL ) {
        if((token[0] <= 90) && (token[0]>= 64)){
            printf( " %s\n", token );
        }
        token = strtok(NULL, s);
    }
}
//Función para mostrar los verbos en gerundio
void ndoVerb(){
    char array[255];

    strcpy(array, paragraph);

    const char s[2] = " ";
    char *token;

    token = strtok(array, s);

    while( token != NULL ) {
        if((token[strlen(token)-1] == 'o' ) && (token[strlen(token)-2] == 'd') && (token[strlen(token)-3] == 'n')){
            printf( " %s\n", token );
        }
        token = strtok(NULL, s);
    }

}
//Función para buscar una palabra
void search(){
    char array[255];

    strcpy(array, paragraph);

    char buscar[255];

    int longitud = strlen(array);
    int palabra = strlen(buscar);
    int i,j,contadorpalabra=0;
    printf("Palabra a buscar: ");
    fgets(buscar,255,stdin);
    fgets(buscar,255,stdin);
    for(i=0;i<=longitud;i++){
        if(array[i]==buscar[j]){
            contadorpalabra++;
        }
    }
    printf("La palabra se encuentra %d veces",contadorpalabra);
}
//Función para intercambiar mayúsculas y minúsculas
void swap(){
    char array[255];

    strcpy(array, paragraph);


    for (int i = 0; i < strlen(array)-1; ++i) {
            if(array[i] == 32){
                printf("%c", 32);
                i+=1;
            }
        printf("%c", array[i] ^= 1 << 5);
    }
}

void min(char* txt){
    for(int i;txt[i]!='\0';++i){
        txt[i]=tolower(txt[i]);
    }
}
