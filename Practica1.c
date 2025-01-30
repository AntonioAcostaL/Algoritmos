#include <stdio.h>

int Vocales(char c) {
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;
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