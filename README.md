# calculadoraASM
Calculadora TP1 Sistemas de Computacion

## Funcionamiento :wrench:

Calculadora que permite sumar numeros en decimal con la opcion de mostrarlos en hexadecimal, binario o decimal.
Es de facil utilizacion, tan simple como correr primero un *make*, para que el Makefile haga lo suyo y genere el programa y luego por ejemplo:
  > ./main.o c 3 + 3 
  
Es una de las opciones permitidas.
Esta calculadora suma como dijimos numeros decimales e imprime dependiendo la opcion que ingresemos, para su correcto uso, antes de la operacion a ejecutar se debe ingresar el caracter que determinara el lenguaje que queremos que se muestre. Pueden ser:
  1. d -> decimal
  2. b -> binario
  3. x -> hexadecimal 


## A tener en cuenta :mag:
  1. *NO* se puede introducir otra cosa que no sean numeros
  2. *NO* intenten poner a sumar en binario, porque asumira que son decimales
  4. *NO* se puede escribir letras al final, *SOLO* al comienzo, y las permitidas
        > x
        > 
        > b
        > 
        > d
  5. Si no sigue el formato del ejemplo, le saldra algun mensaje de error.
  6. Si algo mas hiciste, te va a salir un error.
  7. Se pueden sumar con numeros que esten en el rango de _16 bit signed_  (-32,768 a 32,767), sino tirara error.
