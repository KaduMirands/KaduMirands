#include <stdio.h>
#include <string.h>
struct Retangulo {
    float altura;
    float largura;
};

float calcularArea(struct Retangulo r) {
    return r.altura * r.largura;
}

int main(){
    struct Retangulo ret1;
    printf("Informe a altura do retangulo:");
    scanf("%f", &ret1.altura);
    printf("Informe a largura do retangulo:");
    scanf("%f", &ret1.largura);
    printf("Area do retangulo: %.2f\n", calcularArea(ret1));
    return 0;
}