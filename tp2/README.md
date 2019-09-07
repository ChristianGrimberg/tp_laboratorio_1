[Volver](../README.md)
# Trabajo Práctico número 2
## 1. Enunciado
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

* Datos:
<p style="max-width: 300px; display:block; margin:auto;">
    <img src="../.github/img/employee.png">
</p>

El sistema deberá tener el siguiente menú de opciones:
1. __ALTAS:__ Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.
1. __MODIFICAR:__ Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido o Salario o Sector.
1. __BAJA:__ Se ingresará el Número de Id y se eliminará el empleado del sistema.
1. __INFORMAR:__
    1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
    1. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
> NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones. Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algún empleado.

Para la realización de este programa, se utilizará una biblioteca llamada `ArrayEmployees` que facilitará el manejo de la lista de empleados y su modificación. En la sección siguiente se detallan las funciones que esta biblioteca debe tener.