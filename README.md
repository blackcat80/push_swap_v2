# push_swap

![Image text](https://github.com/blackcat80/push_swap_v2/blob/main/push_swap.png)

**push_swap** es un proyecto de algoritmo de la escuela 42 donde debemos ordenar una lista dada de números aleatorios con un conjunto limitado de instrucciones, utilizando el menor número posible de acciones.

## Uso
1. Clona el repositorio con `Git` y navega hacia él con `cd`.
2. Luego usa `make` para compilar.

Luego ejecútalo con:
```
./push_swap <números>
```

Los números proporcionados pueden ser enteros positivos o negativos. No debe haber duplicados. Por ejemplo:
```
./push_swap 9 0 -217 2147483647 -2147483648
```

Si los argumentos son válidos, el programa mostrará la lista de acciones más eficiente para ordenar la lista.

El programa puede ser verificado con el programa de comprobación proporcionado, de esta manera:
```
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```


## Reglas y calificación de Push_Swap
El programa solo tiene permitido dos pilas para trabajar, pila A y pila B. Todos los números se agregan inicialmente a la pila A, y la pila B está vacía.

Las acciones posibles son:

- `pa` (push A): Toma el primer elemento en la parte superior de B y colócalo en la parte superior de A. No hace nada si B está vacía.
- `pb` (push B): Toma el primer elemento en la parte superior de A y colócalo en la parte superior de B. No hace nada si A está vacía.
- `sa` (swap A): Intercambia los primeros 2 elementos en la parte superior de la pila A. No hace nada si hay solo un elemento o ningún elemento.
- `sb` (swap B): Intercambia los primeros 2 elementos en la parte superior de la pila B. No hace nada si hay solo un elemento o ningún elemento.
- `ss`: `sa` y `sb` al mismo tiempo.
- `ra` (rotate A): Desplaza todos los elementos de la pila A hacia arriba en 1 posición. El primer elemento se convierte en el último.
- `rb` (rotate B): Desplaza todos los elementos de la pila B hacia arriba en 1 posición. El primer elemento se convierte en el último.
- `rr`: `ra` y `rb` al mismo tiempo.
- `rra` (reverse rotate A): Desplaza todos los elementos de la pila A hacia abajo en 1 posición. El último elemento se convierte en el primero.
- `rrb` (reverse rotate B): Desplaza todos los elementos de la pila B hacia abajo en 1 posición. El último elemento se convierte en el primero.
- `rrr`: `rra` y `rrb` al mismo tiempo.

La calificación depende de la eficiencia del proceso de ordenación del programa.

- Ordenar 3 valores: no más de 3 acciones.
- Ordenar 5 valores: no más de 12 acciones.
- Ordenar 100 valores: calificación de 1 a 5 puntos según el número de acciones:
  - 5 puntos para menos de 700 acciones.
  - 4 puntos para menos de 900 acciones.
  - 3 puntos para menos de 1100 acciones.
  - 2 puntos para menos de 1300 acciones.
  - 1 punto para menos de 1500 acciones.
- Ordenar 500 valores: calificación de 1 a 5 puntos según el número de acciones:
  - 5 puntos para menos de 5500 acciones.
  - 4 puntos para menos de 7000 acciones.
  - 3 puntos para menos de 8500 acciones.
  - 2 puntos para menos de 10000 acciones.
  - 1 punto para menos de 11500 acciones.

Validar el proyecto requiere al menos 80/100.




