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

int main(){
    char opcion;

    do{
        printf("INICIO\n");
        printf("a) Asignar Boletos\n");
        printf("b) Cancelar Venta\n");
        printf("c) Mostar mapa\n");
        printf("d) Calcular monto tatal de ventas\n");
        printf("e) Salir\n");
        scanf("%c",&opcion);

        switch (opcion)
        {
        case 'a':
            AsignarBoletos();
            break;
        case 'e':
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion no existe. Intenta de new");
        }
    }
}
