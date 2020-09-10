# Administración de un SO
## Instrucciones

### Ejercicio 1.

Realice un programa en C donde simule el comportamiento del algoritmo de planificación por pandilla. El programa debe permitir al usuario entrar por teclado el número total de procesos a planificar, el tiempo de CPU que se requiere para cada uno, la relación que existe entre los procesos (grupos) y el número de CPUs. Los grupos de procesos deben ir planificándose según el criterio que Ud. defina (puede ser Round Robin, FIFO, etc.), garantizando siempre un máximo aprovechamiento de todas las CPUs.

Nota: Para simular que un proceso consume tiempo de CPU, puede utilizar la función sleep()

Favor de revisar el Capítulo 8. Multiprocesadores,  Sección 8.1.4. Calendarización de multiprocesadores, del libro Sistemas Operativos Modernos de Andrew S. Tanenbaum (Enlaces a un sitio externo.)

 

### Ejercicio 2.

Escriba un programa en C que parta de un directorio dado y descienda por el árbol de archivos registrando los tamaños de todos los archivos que encuentre. Cuando termine, deberá imprimir un histograma de los tamaños de archivo, utilizando una anchura de urna especificada como parámetro ( por ejemplo, para un valor de urna de 1024, todos los archivos con tamaño entre 0 y 1023 se colocan en una urna, los de 1024 a 2047 en otra y así sucesivamente).

Debe utilizar llamadas al sistema (system calls). Por favor, verifique las llamadas al sistema para manipulación de archivos y directorios que a aparecen en la última clase.