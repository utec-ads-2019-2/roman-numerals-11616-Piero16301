#include<bits/stdc++.h>

using namespace std;

int valorRomano(char caracter) {

    switch (caracter) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return -1;

}

int valorArabico(const char* caracter) {

    int resultado = 0;
    while (*caracter) {
        resultado = resultado * 10 + *caracter++ - '0';
    }
    return resultado;

}

void convertirADecimal(const char* numeroRomano) {

    int resultado = 0;
    for (int i = 0; i < strlen(numeroRomano); ++i) {
        int primerValor = valorRomano(numeroRomano[i]);
        if (i + 1 < strlen(numeroRomano)) {
            int segundoValor = valorRomano(numeroRomano[i + 1]);
            if (primerValor >= segundoValor) {
                resultado += primerValor;
            } else {
                resultado = resultado + segundoValor - primerValor;
                i++;
            }
        } else {
            resultado += primerValor;
        }
    }
    cout << resultado << endl;

}

void convertirARomano(const char* numeroArabico) {

    int numero = valorArabico(numeroArabico);
    int equivalenciasArabicas[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string equivalenciasRomanas[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (numero > 0) {
        int dividir = numero / equivalenciasArabicas[i];
        numero = numero % equivalenciasArabicas[i];
        while (dividir--) {
            cout << equivalenciasRomanas[i];
        }
        i--;
    }
    cout << endl;

}

int main() {
    
    char numero [100];
    while (scanf("%s", &numero) == 1) {
        if (std::isalpha(*numero)) {
            convertirADecimal(numero);
        } else {
            convertirARomano(numero);
        }
    }

    return 0;
}