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
    printf("    1 - Ingresar 1er operando (A = %.2f)\n", x);
    printf("    2 - Ingresar 2do operando (B = %.2f)\n", y);
    printf("    3 - Calcular la suma (%.2f + %.2f)\n", x, y);
    printf("    4 - Calcular la resta (%.2f - %.2f)\n", x, y);
    printf("    5 - Calcular la division (%.2f / %.2f)\n", x, y);
    printf("    6 - Calcular la multiplicacion (%.2f * %.2f)\n", x, y);
    printf("    7 - Calcular el factorial (%.2f!)\n", x);
    printf("    8 - Calcular el factorial (%.2f!)\n", y);
    printf("    9 - Salir\n");
    printf("=======================================================\n");

    if(input_getInt(option, "Elija una opción del menu",
        "Opción incorrecta, ingrese nuevamente", OPTION_MIN, OPTION_MAX) == 0)
    {
        returnValue = 0;
    }

    menu_pauseScreen();

    return returnValue;
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
