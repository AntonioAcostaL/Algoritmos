/*Un centro de espectaculos requiere un sistema para la venta y asignacion
de boeltos. Las opciones son*/
/*a) asignar boletos. Las filas estan marcadas de la A a la I y cada 
fila tiene asientos de 1 al 10. Si las localidades no estan agotadas,
entonces el cliente debera elegir su asientos proporcionado fila y asiento.
Si elige un asientos que ya haya ocupado, el programa debe indicar que está ocupado y
el cliente debera elegir de nuevo.*/

/*b) cancelar venta*/

/*c) mostrar mapa del lugar, indicando con un color diferente cuales asientos NO estan libres
y cuales estan disponibles.*/

/*d) calcular el monto total del boletaje vendido. La primera fila cuesta 1000 pesos, la segunda 750
la tercera 500 y el resto 300*/

#include <stdio.h>
#include <conio.h>

void AsignarBoletos();

int main(){
    char opcion;

    do{
        printf("INICIO\n");
        printf("a) Asignar Boletos\n");
        printf("b) Cancelar una asignacion\n");
        printf("c) Mostar mapa\n");
        printf("d) Calcular el totaal de ventas\n");
        printf("e) Salir\n");
        printf("Selecciona una opcion: ");
        scanf(" %c", &opcion);

        switch (opcion)
        {
        case 'a':
            AsignarBoletos();
            break;
        case 'e':
            printf("Saliendo...\n");
            break;

        default:
            printf("\nOpcion no existe.\n");
        }
    }
    while (opcion!='e');
    
    return 0;
}

/*Asignar boletos: Las filas están numeradas del 1 al 10 y cada fila tiene entre 8 y
12 asientos, dependiendo de la fila. El cliente selecciona la fila y el asiento, pero si el
asiento ya está ocupado, el sistema debe pedirle que elija otro.*/
void AsignarBoletos(){
    printf("Boletos asignado\n");
}

int validacion(){
    char tecla=0; 
    int  numero[2]={0}, i=0, j=0, valor=0;
    while (tecla!='\n')
    {
        /* code */
    }
    
}
int validaDigitos(){
    char tecla;
    int numero[2], i=0, j=0, valor=0;
    while (tecla!=ENTER)    
    {
        tecla=getch();
        if (tecla>='1'&&tecla<='9')
        {
            if (i<2)
            {
                printf("%c", tecla);
                numero[i] = tecla -'0';
                i++;
            }
        }
        if (i>0&&tecla==BACKSPACE)
        {
            printf("\b \b");
            numero[i-1] = 0;
            i--;
        }
    }
    for (j = 0; j < i; j++)
    {
        vaor = valor*10+numero[j];
    }
    return valor;
}

