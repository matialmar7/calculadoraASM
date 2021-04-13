/*
implementar una Calculadora programada en lenguaje C. 
Cada una de las operaciones deben estar programadas en lenguaje ASM en archivos separados, utilizando la pila para convocar, enviar parámetros y devolver resultados. 
La Calculadora debe permitir sumar y restar enteros y binarios, presentar el resultado de la suma, borrar lo ingresado y finalizar su ejecución.
*/
#include <stdio.h>
#include <stdlib.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
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

int main(int argc, char const *argv[])
{
    int a, b;
    unsigned int outconf;
    printf("Calculadora all in one, suma y resta de numeros de 6 bits. Operaciones a realizar A + B y A - B.\n");
    printf("Ingresa A: ");
    scanf("%i", &a);
    printf("Ingresa B: ");
    scanf("%i", &b);
    opcion:
    printf("Especifique el formato de salida:\n \t0- Decimal  \n\t1- Hexadecimal \n\t2- Binario\nIngrese su opcion: ");
    scanf("%i",&outconf);

    if(outconf>2) goto opcion;

    printf("Los numeros ingresados son A: %d, B: %d \n",a,b);
    int suma = _sumar(a,b);
    int resta = _restar(a,b);
    switch (outconf)
    {
    case 0:
        printf("A + B = %d y A - B = %d\n",suma,resta);
        break;
    case 1:
        printf("A + B = %X y A - B = %X\n",suma,resta);
    break;
    case 2:
        printf("A + B = "BYTE_TO_BINARY_PATTERN" y A - B = "BYTE_TO_BINARY_PATTERN"\n",BYTE_TO_BINARY(suma>>24),BYTE_TO_BINARY(suma>>16),BYTE_TO_BINARY(suma>>8),BYTE_TO_BINARY(suma),BYTE_TO_BINARY(resta>>24),BYTE_TO_BINARY(resta>>16),BYTE_TO_BINARY(resta>>8),BYTE_TO_BINARY(resta));
        break;
    }


    return 0;
}
