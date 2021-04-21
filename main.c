/*
implementar una Calculadora programada en lenguaje C. 
Cada una de las operaciones deben estar programadas en lenguaje ASM en archivos separados, utilizando la pila para convocar, enviar parámetros y devolver resultados. 
La Calculadora debe permitir sumar y restar enteros y binarios, presentar el resultado de la suma, borrar lo ingresado y finalizar su ejecución.
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define INT_MAX 32767
#define INT_MIN -32768

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

extern int _sumar(int A, int B);
extern int _restar(int A, int B);

void printResult(int resultado, char opt);

int main(int argc, char const *argv[]){

    if(argc == 1 || argc > 5){
        printf("incorrect expression.\nUse ./main.o <d,x,b> A <+,-> B\n");
        return -1;
    }

    errno = 0;

    char printOpt = argv[1][0];

    int a = strtol(argv[2],NULL,10);
    if (errno != 0) {perror("Error while parsing A");exit(EXIT_FAILURE);}
    if(a < INT_MIN || a > INT_MAX){perror("A must be an 16 bit signed int\n");exit(EXIT_FAILURE);}

    int b = strtol(argv[4],NULL,10);
    if (errno != 0) {perror("Error while parsing B");exit(EXIT_FAILURE);}
    if(b < INT_MIN || b > INT_MAX) {perror("B must be an 16 bit signed int\n");exit(EXIT_FAILURE);}
    
    char op = argv[3][0];

    int suma, resta;

    switch (op)
    {
    case '+':
        suma = _sumar(a,b);
        printResult(suma, printOpt);
        break;
    case '-':
        resta = _restar(a,b);
        printResult(resta, printOpt);
        break;
    default:
        printf("incorrect operation");
        return -1;
    }

    return 0;
}

void printResult(int resultado, char opt){
    switch (opt)
    {
        case 'd':
            printf("%d\n",resultado);
            break;
        case 'x':
            printf("%X\n",resultado);
            break;
        case 'b':
            printf(BYTE_TO_BINARY_PATTERN"\n",BYTE_TO_BINARY(resultado>>8),BYTE_TO_BINARY(resultado));
            break;
        default:
            printf("print error\n");
            break;
    }
}