# Conjuntos de señales
## Instrucciones

* Inicialmente se bloquearán todas las señales excepto la señal SIGALARM.
* Mediante una función se debe comprobar si en el directorio actual existe un subdirectorio llamado “datos”. Si éste no existe, se deberá crear; en caso contrario, se borrarán todos los archivos que contenga.
* El programa principal se encargará de instalar un gestor para la señal SIGALRM. 
* A continuación, mediante un ciclo realizará  iteraciones, en cada una de las cuales:
    * generará un nombre de archivo distinto (el primero de ellos “a0” , el siguiente “a1” y, así sucesivamente),
    * abrirá dicho archivo dentro del subdirectorio “datos” (es obligatorio utilizar descriptores de archivos),
    * establecerá un temporizador a t segundos, 
    * y, finalmente, comenzará a escribir en el archivo recién creado el carácter “x” mientras una variable global (de nombre “grabar”) valga 1. 
* Cuando el temporizador expire, se debe establecer la variable “grabar” a 0 y escribir en el archivo todas las señales que ha recibido el proceso y se encuentran pendiente por procesar y posteriormente cerrar el archivo. 
* Por último, listar en pantalla los nombres de los archivo creados y el tamaño de cada uno. 
* El número total de archivo a crear, así como el número de segundos que establece el temporizador, se pasarán como argumentos al programa.
    * -n : número de archivos 
    * -t : segundos del temporizador