# Practica del cursos Sistemas Operativos y Servicios de Red 2021-02-26

En este proyecto vamos a incluir los códigos que se vieron en el curso
Sistemas Operativos y Servicios de Red el día 2021-02-26.

---

## leer_cadena.c

Este archivo muestra como se puede en el lenguaje C leer una cadena digitada por el usuario. 

## fork_exec.c

Este archivo permite la ejecución de un comando que se ejecuta regularmente en Linux usando el esquema fork/exec.

## Directorio tcp

En este directorio se muestra como crear un par de programas sencillos, un cliente que envia una cadena de caracteres y un servidor que recibe dicha cadena.
Como compilar el `tcp.c`

```
gcc tcp.c -c
```

Como compilar el cliente

```
gcc client.c -o client tcp.o
```

Como compilar el servidor

```
gcc server.c -o server tcp.o

```

Para ejecutarlo, en una terminal ejecute el servidor de la siguiente manera:

```
./server 12358
```

En otra terminal ejecute el cliente de la siguiente manera:

```
./client localhost 12358
```
