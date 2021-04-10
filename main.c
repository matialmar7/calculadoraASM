/*
implementar una Calculadora programada en lenguaje C. 
Cada una de las operaciones deben estar programadas en lenguaje ASM en archivos separados, utilizando la pila para convocar, enviar parámetros y devolver resultados. 
La Calculadora debe permitir sumar y restar enteros y binarios, presentar el resultado de la suma, borrar lo ingresado y finalizar su ejecución.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int asm_io();
extern int asm_main();

typedef enum Salida{
    HEX, DEC, BIN
    }Salida;

typedef enum Operacion{
    SUMA, RESTA
    }Operacion;


Salida salida = DEC;
Operacion op = SUMA;
unsigned int eleccion;
int32_t output;

void process(char * operacion);

int main(int argc, char const *argv[])
{
    char * operacion = (char *)malloc(sizeof(char *));

    asm_main(); //-> Aca invocamos la funcion de assembler, para implementar despues.
    
    main:
    printf("Este programa soporta operaciones con y entre numeros hexadecimales y decimales\n");
    printf("1- Ingresar operacion \n2- Configuracion\n");
    scanf("%d", &eleccion);

    switch (eleccion)
    {
    case 1:
        /* code */
        printf("Ingrese la operacion sin espacios: ");
        scanf("%s", operacion);
        process(operacion);
        break;
    case 2:
    configuracion:
        printf("Mostrar resultados en:\n 0- Hexadecimal\n 1- Decimal\n 2-Binario\n");
        scanf("%d", &eleccion);

        if (eleccion < 3) {
            salida = (Salida)eleccion; 
            goto main;
        }
        else goto configuracion;
        break;
    default:
        goto main;
    }

    

    free(operacion);
    return 0;
}

void process(char * operacion){

    const char * delim = "+"; 

    if(strchr(operacion, '+') != NULL)
    {
        delim = "+";
        op = SUMA;
    }
    else if(strchr(operacion, '-') != NULL)
    {
        delim = "-";
        op = RESTA;
    }
    else{
        printf("Operacion no soportada.\n"); 
        return;
    } 

    char *token;

    char * A = strtok(operacion, delim);
    char * B = strtok(NULL, delim);

    int32_t operandoA = strtol(A,NULL,0);
    int32_t operandoB = strtol(B,NULL,0);

    switch (op)
    {
    case SUMA:
        printf("SUMA.");
        /* asm code */
        break;
    case RESTA:
        printf("RESTA.");
        /* asm code */
        break;
    }
}