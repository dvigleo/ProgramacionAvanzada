# Procesos
## Instrucciones
Implemente un programa en C que realice lo siguiente:

1. Recibe como argumento en la línea de comandos el número de procesos hijos a crear (opción -n). El programa debe validar que el valor especificado sea un número entero. 
2. Crea los n procesos hijos siempre y cuando no existan errores. Si al crear un proceso hijo se genera un error, entonces debe mostrar un mensaje indicando el número de procesos hijos creados hasta ese momento y no debe intentar crear más procesos hijos.
3. Espera a que terminen todos los procesos hijos en el mismo orden en que se crearon.
4. A medida que los procesos hijos van terminando, debe ir guardando el valor de retorno de cada proceso hijo.
5. Una vez que terminen todos los procesos hijos, el proceso padre debe mostrar una tabla en el siguiente formato:
``` c
PID Hijo	Promedio	Histograma
20	20	********************
10	15	**************
50	35	*****************************
60	40	**************************************
```

Por su parte, cada proceso hijo debe:

* Calcular el promedio entre su PID y el PID de su padre.
* Imprimir un mensaje que diga: "Soy el proceso hijo con PID = $pid y mi promedio es = $promedio".
    * $pid debe sustituirse por el valor del PID del proceso hijo.
    * $promedio debe sustituirse por el resultado de calcular el promedio entre el PID del proceso hijo y el PID del proceso padre.
* Al terminar, debe regresar el promedio calculado como valor de retorno  al proceso padre.
