/*El siguiente algoritmo permite generar identificadores únicos para usuarios basados en el
nombre de su sitio web favorito.
1. Primer dígito: Es el número de consonantes en el nombre del sitio web
2. Segundo dígito: Es la 2da letra del nombre del sitio, convertida a mayúscula.
3. Tercer dígito: Es el número de vocales en el nombre del sitio menos el número de
consonantes, en caso de que la resta de un valor negativo convertirlo a su valor
absoluto.
4. Cuarto dígito: Es “-” si el nombre del sitio contiene una "o" (mayúscula o
minúscula), y "$" si no la contiene.
5. Últimos tres dígitos: Son las tres primeras consonantes del nombre del sitio, en orden
inverso.
Por ejemplo:
• Para "Twitter", el identificador único sería: 53W$ttT
• Para "Facebook", el identificador único sería: 4A0-bcF
• Para "Google", el identificador único sería: 3O0-lgG*/

#include <stdio.h>

int Vocales(char c) { //funcion que retorna un valor entero y espera un parametro de tipo char llamado 'c'
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c; // la variable c tipo char es igual a una operacion que dice que 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int Consonantes(char c) {
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;
    return ((c >= 'a' && c <= 'z') && !Vocales(c));
}

int contarVocales(const char *cadena) {
    int contador = 0;
    while (*cadena) {
        if (Vocales(*cadena))
            contador++;
        cadena++;
    }
    return contador;
}

int contarConsonantes(const char *cadena) {
    int contador = 0;
    while (*cadena) {
        if (Consonantes(*cadena))
            contador++;
        cadena++;
    }
    return contador;
}

int miStrlen(const char *cadena) {
    int longitud = 0;
    while (*cadena++) {
        longitud++;
    }
    return longitud;
}

char tieneUnaO(const char *cadena) {
    while (*cadena) {
        if (*cadena == 'o' || *cadena == 'O')
            return '-';
        cadena++;
    }
    return '$';
}

void tresConsonantes(const char *cadena, char *resultado) {
    int contador = 0;
    char consonantes[3] = {'X', 'X', 'X'};
    int longitud = miStrlen(cadena);
    for (int i = 0; i < longitud && contador < 3; i++) {
        if (Consonantes(cadena[i])) {
            consonantes[contador++] = cadena[i];
        }
    }
    resultado[0] = consonantes[2];
    resultado[1] = consonantes[1];
    resultado[2] = consonantes[0];
    resultado[3] = '\0';
}

void generarIdentificador(const char *sitio) {
    int consonantes = contarConsonantes(sitio);
    int vocales = contarVocales(sitio);
    int diferencia = consonantes - vocales;
    if (diferencia < 0) diferencia = -diferencia;
    char segundoDigito = (sitio[1] >= 'a' && sitio[1] <= 'z') ? sitio[1] - 32 : sitio[1];
    char cuartoDigito = tieneUnaO(sitio);
    char ultimosTres[4];
    tresConsonantes(sitio, ultimosTres);
    
    printf("Identificador único: %d%c%d%c%s\n", consonantes, segundoDigito, diferencia, cuartoDigito, ultimosTres);
}

int main() {
    char sitio[50];
    printf("Ingrese el nombre del sitio web: ");
    scanf("%s", sitio);
    generarIdentificador(sitio);
    return 0;
}