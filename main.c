/*
implementar una Calculadora programada en lenguaje C. 
Cada una de las operaciones deben estar programadas en lenguaje ASM en archivos separados, utilizando la pila para convocar, enviar parámetros y devolver resultados. 
La Calculadora debe permitir sumar y restar enteros y binarios, presentar el resultado de la suma, borrar lo ingresado y finalizar su ejecución.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdecl.h"

extern int sumar(int x, int y);
extern int restar(int x, int y);

typedef enum Salida
{
    HEX,
    DEC,
    BIN
} Salida;

typedef enum Operacion
{
    SUMA,
    RESTA
} Operacion;

Salida salida = DEC;
Operacion op = SUMA;
unsigned int eleccion;
int32_t output;

void process(char *operacion);

int main(int argc, char const *argv[])
{
    char *operacion = (char *)malloc(sizeof(char *));

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

        if (eleccion < 3)
        {
            salida = (Salida)eleccion;
            goto main;
        }
        else
            goto configuracion;
        break;
    default:
        printf("Eleccion no reconocida\n");
        goto main;
    }

    free(operacion);
    return 0;
}

void process(char *operacion)
{

    const char *delim = "+";
    int resultado = 0;

    if (strchr(operacion, '+') != NULL)
    {
        delim = "+";
        op = SUMA;
    }
    else if (strchr(operacion, '-') != NULL)
    {
        delim = "-";
        op = RESTA;
    }
    else
    {
        printf("Operacion no soportada.\n");
        return;
    }

    char *token;

    char *A = strtok(operacion, delim);
    char *B = strtok(NULL, delim);

    int operandoA = (int)(strtol(A, NULL, 0));
    int operandoB = (int)(strtol(B, NULL, 0));

    switch (op)
    {
    case SUMA:
        printf("SUMA.");
        /* asm code */
        resultado = sumar(operandoA, operandoB);
        printf("El resutaldo de la suma es: %d\n", resultado);
        break;
    case RESTA:
        printf("RESTA.");
        /* asm code */
        resultado = restar(operandoA, operandoB);
        printf("El resutaldo de la suma es: %d\n", resultado);
        break;
    }
}