#include "menu.h"

/** \brief Funcion que limpia la pantalla de la consola en los diferentes SO
 *
 * \param void No requiere paramteros
 * \return void No retorna valores
 *
 */
static void clearScreen(void);

void menu_pauseScreen(void)
{
    printf("Presione la tecla Enter para continuar...");
    /**< Metodo para parar la ejecucion del programa
    hasta presionar Enter para diferentes SO */
    setbuf(stdin, NULL);
    getchar();
}

int menu_main(int* option, double x, double y)
{
    int returnValue = -1;

    clearScreen();

    /**< Impresion del menu con los valores dentro */
    printf("=======================================================\n");
    menu_printNumberByType("    1 - Ingresar 1er operando A =", x);
    menu_printNumberByType("    2 - Ingresar 2do operando B =", y);
    printf("    3 - Calcular la suma (A + B)\n");
    printf("    4 - Calcular la resta (A - B)\n");
    printf("    5 - Calcular la division (A / B)\n");
    printf("    6 - Calcular la multiplicacion (A * B)\n");
    printf("    7 - Calcular el factorial (A!) (B!)\n");
    printf("    8 - Salir\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, OPTION_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

void menu_printNumberByType(char message[], float number)
{
    switch (input_getNumberType(number))
    {
        case 1:
            /**< Se imprime en consola el numero como entero */
            printf("%s %d\n", message, (int)number); 
            break;
        case 2:
            /**< Se imprime en consola el numero como flotante con tres decimales */
            printf("%s %.3f\n", message, number);
            break;
    }
}

static void clearScreen()
{
    #if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
    {
        system("clear");
    }
    #else
    {
        system("cls");
    }
    #endif
}

