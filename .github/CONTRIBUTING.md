# Guía de estilo
## Estructura del programa
La estructura básica de un programa de un sólo módulo está compuesta por una cabecera, directivas `#include`, directivas `#define`, `typedef`, prototipos, y la función `main`. Con este orden se garantiza la coherencia de todas las definiciones, mientras que utilizar un orden diferente sólo sería válido en algunas situaciones particulares.
```c
/*******************************************************************
* Programa: Ejemplo Clase X­
*
* Objetivo:
	Ingresar datos de 1 persona e imprimirlos.
	nombre[32]
	edad
*
* Version: 0.1 del 06 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/
#include<stdio.h>
#include<stdlib.h>

structS_Person
{
	char name[20];
	int age;
};
typedef structS_Person Person;

int enterPerson(Person* p);
void printPerson(Person* p);

int main(int argc, char *argv[])
{
	...
}
```
## Variables
1. Escribir los nombres de variables en minúsculas y si el nombre es compuesto, utilizar mayuscula en la primer letra de la nueva palabra, este estilo lleva el nombre de _`lowerCamelCase`_.
	```
	auxiliarInt
	```
1. Es conveniente que el nombre de las variables tenga sentido, para ayudar a entender el programa y que el mismo se encuentre en inglés.
1. Es habitual utilizar algún criterio para identificar el tipo de variable por su nombre, por ejemplo que todos los punteros a entero utilicen nombres de variables empezando con __“p”__ por ejemplo __“`pCounter`”__.
1. Es muy recomendable añadir un comentario al lado de la declaración para explicar mejor su significado. Declarar muchas variables en una sola línea impide escribir el comentario.
1. Evitar utilizar variables globales. Sólo en casos muy especiales tiene sentido utilizar variables globales; en esos casos hay que documentar en cada función qué variables globales se utilizan.
1. Es recomendable inicializar variables justo delante del bucle que requiere la inicialización. Esto facilita la revisión del programa, evita que la inicialización se pueda perder antes de llegar al bucle, y facilita la reutilización de fragmentos de código.
	```c
	int i = 9;

	while(i > 0)
	{
		...
	}
	```
1. Las variables para el control de iteraciones (de tipo entero) podrán tener nombres cortos como `i`, `j` ó `k`.
## Funciones
1. Escribir los nombres de las funciones con la primera letra minúscula y si el nombre es compuesto, utilizar mayúscula en la primer letra de las nuevas palabras.
	```c
	getFloat(char mensaje[])
	```
1. Resulta más claro utilizar nombres de acción para nombres de funciones.
1. Utilizar nombres en Inglés para las funciones, esto permitirá obtener un código que podrá ser interpretado por cualquier programador en el mundo.
1. Evitar escribir funciones con mucho código. Es conveniente dividir una función larga en varias funciones pequeñas para facilitar la comprensión del programa y la depuración, aunque dichas funciones sólo se llamen una vez.
1. Cada función debe llevar su propia cabecera de descripción, que es equivalente al manual de referencia (utilizar el estilo __Doxygen__). __Doxygen__ es un generador de documentación para _C++_, _C_, _Java_, _Objective-C_, _Python_, _IDL_ (versiones _Corba_ y _Microsoft_), _VHDL_ y en cierta medida para _PHP_, _C#_ y _D_. Dado que es fácilmente adaptable, funciona en la mayoría de sistemas _Unix_ así como en _Windows_ y _Mac OS X_.
	```c
	/**
	* \brief Solicita un número al usuario y devuelve el resultado
	* \param mensaje Es el mensaje a ser mostrado
	* \return El número ingresado por el usuario
	*
	*/
	float getFloat(char mensaje[])
	{
		float auxiliar;
		printf("%s", mensaje);
		scanf("%f", &auxiliar);
		return auxiliar;
	}
	```
1. Los parámetros de una función representan datos de entrada, de salida o de entrada-salida.
	* Los datos de entrada deben pasarse a la función por valor.
	* Los datos de entrada-salida deben pasarse a la función por referencia.
	* Si la función sólo tiene un dato de salida, éste será el valor de retorno de la misma.
1. Si la función debe modificar dos o más datos se debe emplear obligatoriamente el paso por referencia. En este caso se recomienda crear una función tipo `void` y pasar todos los parámetros de salida por referencia.
1. En una función todas las variables deben declararse como parámetros o como variables locales.
1. Si una función no acepta parámetros debe indicarse con la palabra reservada `void`.
	```c
	int mostrarMenu(void);
	```
1. Si una función no devuelve ningún valor, debe declararse como tipo `void`.
	```c
	void mostrarDatos(int a, int b);
	```
1. En una función, que tiene que devolver un resultado, se recomienda incluir siempre una única sentencia `return` y que ésta esté situada al final de la función. Queda excluida de esta regla el caso de las funciones de validación que retornan `0` o `1`.
1. A la hora de implementar una función se recomienda definirla haciendo uso del prototipo. Además, este prototipo debería incluir el nombre (y no solo el tipo) de los parámetros que recibe.
## Vectores
1. El tamaño de un vector debe estar declarado como una constante.
	```c
	#define TAM 20
	
	int main(void)
	{
		int vector[TAM];
		...
		return 0;
	}
	```
1. Cuando un vector se pasa como parámetro a una función es buena práctica pasar el tamaño del vector como parámetro adicional. Con esto se consigue dar mayor generalidad a las funciones.
## Claridad del código
1. Utilizar un correcto tabulado del texto para localizar rápidamente el inicio y el final de cada bloque de código.
	```c
	for(i = 0; i < 4; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &auxiliarInt);
		
		acumulador = acumulador + auxiliarInt;
		
		if(auxiliarInt > maximo)
		{
			maximo = auxiliarInt;
		}
	}
	```
1. En estructuras de bloque (condicionales o iterativas) con una única sentencia se pueden obviar las llaves que delimitan el bloque de instrucciones. Sin embargo, al ampliar el bloque añadiendo instrucciones el no tener marcado el inicio y el final suele ser una fuente de error. Se recomienda SIEMPRE utilizar llaves.
1. No escribir líneas de código demasiado largas, como máximo 80 caracteres. En `C` todas las expresiones matemáticas, expresiones lógicas y llamadas a función se pueden separar en varias líneas.
1. El programa principal, siempre que sea posible, no deberá ocupar más de una pantalla (40 líneas de código sin incluir comentarios).
1. Las cadenas de caracteres se pueden separar en varias líneas cerrando las dobles comillas en una línea y abriéndolas en la siguiente. 
1. Debe utilizarse la estructura de bucle adecuada para cada caso: `for`, `while` ó `do−while`. Como norma general el bucle `for` se utiliza cuando el número de iteraciones es fijo y conocido desde el principio. Por lo tanto la condición de salida del bucle `for` no debería ser muy compleja, ni tiene sentido modificar el contador dentro del bucle. Las salidas a mitad de bucle con `break` o `continue` están totalmente desaconsejadas. 
1. Está desaconsejada la utilización de `exit` en cualquier parte del código y la utilización de `return` en medio de una función. Salvo casos excepcionales, resulta más claro que las funciones tengan un único punto de entrada y un único punto de salida. 
1. Evitar el anidamiento excesivo de estructuras condicionales (`if`, `switch`) y/o iterativas (`for`, `while`, `do-while`). Si hay más de estas tres estructuras anidadas emplear funciones para reducir el número de ellas.
1. Un conjunto de instrucciones no trivial que se repite a lo largo del código, ha de ser reemplazado por la correspondiente función.
1. La directiva `#define` es una palabra clave del pre-procesador y su nombre siempre irá en mayúsculas. Si el nombre consta de varias palabras se escribirá separadas por un guión bajo.
	```c
	#define MAX_FILAS 20
	```
1. Se aconseja no utilizar más de una instrucción por línea de código.
1. Se deben añadir explicaciones a todo lo que no es evidente pero también hay que evitar las redundancias. Es decir, no hay que repetir lo que se hace, sino explicar, de forma clara y concisa, por qué se hace.
## Modularización del Software
1. El código `C` se organiza en archivos `.c` y `.h`. Para cada archivo `.c` debe existir un `.h` con el mismo nombre (`Person.c`, `Person.h`). A esta pareja de archivos se la denomina __módulo__.
1. Cada módulo tiene una interfaz pública definida en su `.h`, y una serie de variables y funciones privadas escondidas dentro de `.c`.
1. Las declaraciones de variables y funciones pública se ponen en el `.h` para que otros módulos puedan incluirlas (`#include "People.h"`)1. Las declaraciones de variables y funciones privadas quedan dentro del `.c` definidas como `static` para no permitir que estas funciones sean utilizadas desde otros módulos.
1. Los módulos contendrán de forma natural conjuntos de funciones relacionadas desde un punto de vista lógico.
1. Los nombres de las funciones públicas contenidas en el módulo comenzarán con el nombre del módulo en minúscula seguida por el guión bajo (ejemplo `person_setEdad`).
1. Cada archivo `.c` debe incluir a su propio `.h` (`#include "Person.h"`).
1. Los archivos `.h` deben contener sólo declaraciones públicas: tipos, constantes y prototipos de funciones diseñadas para ser usados desde fuera del módulo.
1. Todo archivo `.h` debe evitar inclusiones múltiples:
	```c
	#ifndef PERSON_H
	#define PERSON_H
	//... interfaz pública del módulo ...
	#endif /* PERSON_H */
	```
1. Cuando se realice la implementación de tipos de datos abstractos (```structs```) definidos por el programador, todas las funciones que acceden al tipo definido deberán estar contenidas en el mismo fichero.
1. Las funciones `set`: deberá existir como mínimo una función de este tipo por cada campo del tipo de dato abstracto (o entidad) administrado por el módulo. Ejemplo: `person_setName(Person* this, char* value)`, recibe como parámetro un puntero a la persona y el `String` (nombre de la persona) que asigna luego de realizar las validaciones correspondientes al campo `name` de la persona recibida como parámetro.
1. Las funciones `get`: deberá existir como mínimo una función de este tipo por cada campo del tipo abstracto (o entidad) administrado por el módulo. Ejemplo: `person_getName(Person* this)`, recibe como parámetro un puntero a la persona y retorna un puntero al nombre de la misma.
### Archivo: Person.c
```c
#include <stdlib.h>
#include "Person.h"

/* Tipo de dato privado */
typedef struct
{
	int age;
	int something;
}_Person;

/* Funciones Privadas */
static void initialize(Person* this, int age, int something);

/** \brief Reserva espacio en memoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Person* person_new(int age, int something)
{
	Person* this = malloc(sizeof(_Person));
	if(this != NULL)
	initialize(this, age, something);
	return this;
}

/** \brief Inicializa a una persona recibida como parámetro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Person* this, int age, int something)
{
	_Person* _this = (_Person*)this;
	_this->age = age;
	_this->something = something;
}

/** \brief Setea la edad de una persona recibida como parámetro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age)
{
	_Person* _this = (_Person*)this;
	if(age > 0)
	_this->age = age;
}

/** \brief Obtiene la edad de una persona recibida como parámetro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Person* this)
{
	_Person* _this = (_Person*)this;
	return _this->age;
}

/** \brief Libera el espacio ocupado por una persona recibida como parámetro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this) {
	free(this);
}
```
### Archivo: Person.h
```c
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

typedef struct
{
	//Tipo de dato público
}Person;
Person* person_new (int age, int something);

void person_setAge(Person* this, int age) ;

int person_getAge(Person* this);

void person_free(Person * this);

#endif //PERSON_H_INCLUDED
```
### Archivo: main.c
```c
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"

int main()
{
	Person* personArray[50];
	int i;

	for(i = 0; i < 10; i++)
	{
		personArray[i] = person_new(i,i);
	}
	
	for(i = 0; i < 10; i++)
	{
		person_setAge(personArray[i],i-4);
	}
	
	for(i = 0; i < 10; i++)
	{
		printf("\nAge: %2d",person_getAge(personArray[i]));
	}
	
	scanf(" ");
	
	return 0;
}
```