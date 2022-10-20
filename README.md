# Heuristic-Algorythm-Implemented
Heuristic Algorythm writed in C++
Objetivo

Entendiendo que ya no es posible encontrar una solución óptima (respecto al monto total del bono) para un número tan grande de familias; es que proponemos encontrar la mejor solución posible, en un tiempo apropiado.

Debemos mantener las mismas consideraciones que en el caso anterior: todas las familias deben poder visitar el parque en alguno de los días que indicaron como preferidos, y cada familia será invitada un único día.

La técnica de resolución aplicada en la primera temporada ya no es aplicable a este nuevo contexto.

Datos de entrada

Se anotaron 5000 familias para visitar el parque, cada una eligió entre 8 días de los disponibles en el orden en que prefieren realizar la visita.

Se sabe que el parque estará abierto 100 días consecutivos y que la disponibilidad diaria es de 340 personas.

El bono compensatorio se aplica únicamente a la familia que no es asignada en el primer día elegido como prioritario y se calcula utilizando la siguiente fórmula:

bono = U$S 25 + (U$S 10 * Grupo Familiar) + (U$S 5 * Dia asignado)


Características de la solución

Se considera válida a una solución si:

No supera el tope de capacidad diaria para ninguno de los días disponibles.

Cada familia es asignada a un único día para realizar la visita.

Todas las familias son asignadas para realizar la visita en algunos de sus días preferidos.

Se considera óptima a una solución si:

Es una solución válida.

Se consigue obtener el mínimo costo total del bono compensatorio.

Se sabe que, para el caso de prueba provisto, el mínimo costo total del bono compensatorio es 29035.


Consigna

Implementar un programa que obtenga una solución válida al problema planteado, resultando en el cronograma de familias por día y calcule el monto total a disponer en bonos compensatorios.

Realizar un proceso que, a partir de una solución válida, intente mejorar esa solución mediante alguna transformación local cuyo costo computacional no supere una función cuadrática - O (N^2).

Realizar un breve informe que contenga: 

Las ideas que se consideraron para obtener una solución válida (incluyendo aquellas que fueron descartando en el proceso).

Una explicación del algoritmo que se utilizó para obtener una solución válida, justificando su elección.

Las transformaciones aplicadas a la solución válida, justificando su elección.

Aclaración: se puede considerar como una solución válida (para el inciso 2) a una asignación que, inicialmente, deja menos de 10 familias sin asignar. Luego, como parte del proceso de transformación (o previo a él) se deberán asignar esas familias para respetar las restricciones iniciales del problema.
