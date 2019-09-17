#include <iostream>

struct Racional{
    private:
        int numerador, denominador;
    public:
        Racional(int x, int y);
        void setRacional(int x, int y);
        void setNumerador(int x);
        void setDenominador(int y);
        int getNumerador();
        int getDenominador();
        // Operaciones con la racional
        Racional sumar(Racional racional2);
        Racional restar(Racional racional2);
        Racional multiplicar(Racional racional2);
        Racional dividir(Racional racional2);
        void simplificar();
};
Racional::Racional(int x, int y){
    numerador = x;
    denominador = y;
}
void Racional::setRacional(int x, int y) {
    numerador = x;
    denominador = y;
}
void Racional::setNumerador(int x){
    numerador = x;
}
void Racional::setDenominador(int y){
    denominador = y;
}
int Racional::getNumerador(){
    return numerador;
}
int Racional::getDenominador(){
    return denominador;
}
// Operaciones con la racional
Racional Racional::sumar(Racional racional2){
    Racional resultado(0,0);
    resultado.denominador = denominador * racional2.denominador;
    resultado.numerador = (numerador * racional2.denominador) + (racional2.numerador * denominador);

    resultado.simplificar();
    return resultado;
}
Racional Racional::restar(Racional racional2){
    Racional resultado(0,0);
    resultado.denominador = denominador * racional2.denominador;
    resultado.numerador = (numerador * racional2.denominador) - (racional2.numerador * denominador);

    resultado.simplificar();
    return resultado;
}
Racional Racional::multiplicar(Racional racional2){
    Racional resultado(0,0);
    resultado.numerador = numerador * racional2.numerador;
    resultado.denominador = racional2.denominador * denominador;

    resultado.simplificar();
    return resultado;
}
Racional Racional::dividir(Racional racional2){
    Racional resultado(0,0);

    resultado.numerador=numerador * racional2.denominador;
    resultado.denominador=denominador * racional2.numerador;
    resultado.simplificar();
    return resultado;
}
void Racional::simplificar(){
    int i = 2;
    while (i <= denominador){
        while ((numerador % i == 0) && (denominador % i == 0)){
            numerador = numerador / i;
            denominador = denominador / i;
        }
        i++;
    }
}

int main() {
    Racional racional_1(2,3), racional_2(3, 4);

    Racional r3 = racional_1.sumar(racional_2);
    std::cout << r3.getNumerador() << '/' << r3.getDenominador() << "\n";

    r3 = racional_1.restar(racional_2);
    std::cout << r3.getNumerador() << '/' << r3.getDenominador() << "\n";

    r3 = racional_1.multiplicar(racional_2);
    std::cout << r3.getNumerador() << '/' << r3.getDenominador() << "\n";

    r3 = racional_1.dividir(racional_2);
    std::cout << r3.getNumerador() << '/' << r3.getDenominador() << "\n";
    
    return 0;
}