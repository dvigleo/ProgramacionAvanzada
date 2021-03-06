# Cajeros automáticos
## Instrucciones

* Hay 8 cajeros para atención de clientes / usuarios:
    * 5 cajeros atienden operaciones generales. El tiempo promedio de atención es entre 3 y 5 segundos.
    * 3 cajeros atienden operaciones empresariales. Este tipo de cajeros, cuando no hay ningún cliente empresarial, pueden atender clientes con operaciones generales.
    * Todos los cajeros toman un receso de 3 segundos cada vez que atienden 5 clientes.
* Cuando un cajero está atendiendo a un usuario se imprime:
    * Id del cajero
    * Id del cliente
    * Tipo de operación realizada (general/empresarial).
* Cuando un cajero está descansando se imprime un mensaje para indicar al cliente que detiene sus operaciones / actividades.
* Simula la llegada de 150 usuarios:
    * 100 usuarios van a realizar operaciones generales. El tiempo de llegada de estos usuarios es entre 5 y 22 segundos.
    * 50 usuarios desean realizar operaciones empresariales. El tiempo promedio de llegada de estos usuarios es entre 9 y 34 segundos.
* Cada vez que llega un cliente se forma en una fila de espera e imprime lo siguiente:
    * Identificador del cliente
    * Tipo de operación a realizar (empresarial o general)