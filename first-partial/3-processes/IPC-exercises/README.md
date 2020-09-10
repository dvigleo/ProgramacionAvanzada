# Ejercicios de Pipes y FIFO

## Ejercicio 1
Escriba un programa en C que reciba por teclado números y cada vez que recibe un número, se lo envíe a un proceso hijo a través de un pipe para que este calcule e imprima el factorial de ese número. Solo debe existir un hijo que calcula. 

## Ejercicio 2
Escriba un programa en C que genere dos procesos. El primer proceso lee números enteros del teclado y los envía a un pipe para que los lea el otro proceso. El segundo proceso recibirá los números del pipe sumándolos. Cuando se entre el número 0, el proceso hijo debe mostrar el resultado de la suma y ambos procesos deben terminar. 

## Ejercicio 3
Modifique el ejercicio 1 para que el hijo no imprima el factorial, sino que en su lugar, utilizando otro pipe, se lo comunique al padre y sea este quien imprima los resultados.
*Nota*: Recuerde que para la comunicación bidireccional debe utilizar dos pipes. 

## Ejercicio 4
Resuelva el problema 1 utilizando FIFO, donde los procesos no tengan relación de parentesco. 
*Nota*: Para lo anterior debe crear dos procesos diferentes: uno que escribe el número en
el FIFO y otro que lo lee para calcular el factorial e imprimir el resultado. 
