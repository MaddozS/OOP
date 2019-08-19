#include <stdio.h>
#include <stdlib.h>

struct Racional{
    int numerador, denominador;
};

struct Racional simplificar(struct Racional racional);

struct Racional sumar(struct Racional racional1, struct Racional racional2);
struct Racional restar(struct Racional racional1, struct Racional racional2);
struct Racional multiplicar(struct Racional racional1, struct Racional racional2);
struct Racional dividir(struct Racional racional1, struct Racional racional2);

int main(int argc, char **argv){
    // Inicializacion de las primeras 2 racionales
    struct Racional number1;
    struct Racional number2;
    // Asignacion de los numeradores y denominadores
    number1.numerador = 4;
    number1.denominador = 3;
    number2.numerador = 3;
    number2.denominador = 5;
    // Nuevas racionales creadas a partir de las funciones
    struct Racional suma = sumar(number1, number2);
    printf("La suma de los racionales da: %d/%d\n", suma.numerador, suma.denominador);
    struct Racional resta = restar(number1, number2);
    printf("La resta de los racionales da: %d/%d\n", resta.numerador, resta.denominador);
    struct Racional multi = multiplicar(number1, number2);
    printf("La multiplicacion de los racionales da: %d/%d\n", multi.numerador, multi.denominador);
    struct Racional divi = dividir(number1, number2);
    printf("La division de los racionales da: %d/%d\n", divi.numerador, divi.denominador);
    system("pause"); 
    return 0;
}

struct Racional sumar(struct Racional racional1, struct Racional racional2){
    struct Racional suma;
    suma.denominador=racional1.denominador * racional2.denominador;
    suma.numerador=(racional1.numerador * racional2.denominador) + (racional2.numerador * racional1.denominador);

    suma = simplificar(suma);
    return suma;
}

struct Racional restar(struct Racional racional1, struct Racional racional2){
    struct Racional resta;
    resta.denominador=racional1.denominador * racional2.denominador;
    resta.numerador=(racional1.numerador * racional2.denominador) + (racional2.numerador * racional1.denominador);

    resta = simplificar(resta);
    return resta;
}

struct Racional multiplicar(struct Racional racional1, struct Racional racional2){
    struct Racional mult;
    mult.numerador=racional1.numerador * racional2.numerador;
    mult.denominador=racional1.denominador * racional2.denominador;

    mult = simplificar(mult);
    return mult;
}

struct Racional dividir(struct Racional racional1, struct Racional racional2){
    struct Racional div;
    div.numerador=racional1.numerador * racional2.denominador;
    div.denominador=racional1.denominador * racional2.numerador;

    div = simplificar(div);
    return div;
}

struct Racional simplificar(struct Racional racional){
    int i = 2;
    while (i <= racional.denominador){
        while ((racional.numerador % i == 0) && (racional.denominador % i == 0)){
            racional.numerador = racional.numerador / i;
            racional.denominador = racional.denominador / i;
        }
        i++;
    }
    return racional;
}