#include <iostream>

struct Racional{
    int numerador, denominador;
    Racional(int x, int y) {
        numerador = x;
        denominador = y;
    }
    Racional sumar(Racional racional2){
        Racional resultado(0,0);
        resultado.denominador = denominador * racional2.denominador;
        resultado.numerador = (numerador * racional2.denominador) + (racional2.numerador * denominador);

        resultado.simplificar();
        return resultado;
    }
    Racional restar(Racional racional2){
        Racional resultado(0,0);
        resultado.denominador = denominador * racional2.denominador;
        resultado.numerador = (numerador * racional2.denominador) - (racional2.numerador * denominador);

        resultado.simplificar();
        return resultado;
    }

    Racional multiplicar(Racional racional2){
        Racional resultado(0,0);
        resultado.numerador = numerador * racional2.numerador;
        resultado.denominador = racional2.denominador * denominador;

        resultado.simplificar();
        return resultado;
    }

    Racional dividir(Racional racional2){
        Racional resultado(0,0);

        resultado.numerador=numerador * racional2.denominador;
        resultado.denominador=denominador * racional2.numerador;
        resultado.simplificar();
        return resultado;
    }

    void simplificar(){
        int i = 2;
        while (i <= denominador){
            while ((numerador % i == 0) && (denominador % i == 0)){
                numerador = numerador / i;
                denominador = denominador / i;
            }
            i++;
        }
    }
};

int main() {
    Racional racional_1(2,3), racional_2(3, 4);
    Racional r3 = racional_1.sumar(racional_2);
    std::cout << r3.numerador << '/' << r3.denominador << "\n";
    r3 = racional_1.restar(racional_2);
    std::cout << r3.numerador << '/' << r3.denominador << "\n";
    r3 = racional_1.multiplicar(racional_2);
    std::cout << r3.numerador << '/' << r3.denominador << "\n";
    r3 = racional_1.dividir(racional_2);
    std::cout << r3.numerador << '/' << r3.denominador << "\n";
    
    return 0;
}