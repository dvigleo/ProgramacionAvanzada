# Ejercicios de concurrencia
## Instrucciones

### Ejercicio 1

Blancanieves y los siete enanitos viven en una casa donde solo existen cuatro sillas, que los enanitos utilizan para comer.

1. Cuando un enanito vuelve de trabajar en la mina, comprueba si hay una silla libre para sentarse.
2. Si existe una silla libre, entonces indica a Blancanieves que ya está sentado, y espera pacientemente su turno a que le sirvan.
3. Cuando le ha servido, Blancanieves le indica que puede empezar a comer.
4. El enanito come y cuando acaba, deja la silla libre y vuelve a la mina.
5. Por su parte, Blancanieves cuando no tiene ningún enanito pendiente de servirle, se va a dar una vuelta.

### Ejercicio 2

En el Distrito Federal está a punto de inaugurarse el primer centro comercial en el que la compra la realizan robots en lugar de personas.

* El centro comercial está compuesto por N (un número fijo) secciones adyacentes, donde por problemas estructurales, cada sección solo puede soportar un peso máximo (Ps).
* Los compradores envían sus listas de compra a un sistema, y cada lista se asigna a un robot diferente.
* Cuando un robot recibe su asignación, inicia el recorrido entrando en la sección 0. Avanzan a la sección adyacente (0, 1, . . .) cuando han acumulado los productos requeridos de esa sección y terminan saliendo de la sección N − 1.
* Debido al peso de los robots y las limitantes estructurales de centro comercial, cuando un robot con un determinado peso (pi) quiere avanzar a la siguiente sección, debe esperar hasta que el incremento de peso que provoca no ponga en peligro la estructura (un robot con peso pi no puede avanzar si peso actual de la sección + pi > Ps).
* Tenga en cuenta que debido a la demanda existente en el centro comercial y la poca disponibilidad de robots con que se cuenta inicialmente, se desea que si un robot  se encuentra esperando para entrar en una sección (debido a restricción de sobrepeso), en cuanto se libere peso en dicha sección se le notifique al robot en espera para que intente avanzar.