/*
implementar una Calculadora programada en lenguaje C. 
Cada una de las operaciones deben estar programadas en lenguaje ASM en archivos separados, utilizando la pila para convocar, enviar parámetros y devolver resultados. 
La Calculadora debe permitir sumar y restar enteros y binarios, presentar el resultado de la suma, borrar lo ingresado y finalizar su ejecución.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
bool binarioIn = false, binarioOut = false;

void process(char *operacion);
long decimalToBinary(int decimalnum);
int scanBin();

int main(int argc, char const *argv[])
{
    char *operacion = (char *)malloc(sizeof(char *));

main:
    printf("Este programa soporta operaciones con y entre numeros binarios y decimales de no mas de 10 bits.\n");
    printf("1- Ingresar operacion \n2- Ingreso de los numeros\n3- Muestra del resultado\n");
    printf("Eleccion: ");
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
        printf("Prefiere ingresar los numeros en:\n 0- Decimal\n 2- Binario\n");
        printf("Eleccion: ");
        scanf("%d", &eleccion);
        binarioIn = (eleccion == 2) ? true : false;
        goto main;
        break;
    case 3:
    configuracion:
        printf("Mostrar resultados en:\n 1- Decimal\n 2-Binario\n");
        printf("Eleccion: ");
        scanf("%d", &eleccion);
        binarioOut = (eleccion == 2) ? true : false;
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
        printf("SUMA.\n");
        /* asm code */
        resultado = sumar(operandoA, operandoB);
        if (binarioOut)
            printf("El equivalente en binario es: %ld \n", decimalToBinary(resultado));
        printf("El resutaldo de la suma es: %d\n", resultado);
        break;
    case RESTA:
        printf("RESTA.\n");
        /* asm code */
        resultado = restar(operandoA, operandoB);
        if (binarioOut)
            printf("El equivalente en binario es: %ld \n", decimalToBinary(resultado));
        printf("El resutaldo de la suma es: %d\n", resultado);
        break;
    }
}

/*https://beginnersbook.com/2017/09/c-program-to-convert-decimal-number-to-binary-number/ */

long decimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decimalnum != 0)
    {
        rem = decimalnum % 2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem * temp;
        temp = temp * 10;
    }
    return binarynum;
}