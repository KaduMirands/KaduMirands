#include <stdio.h>
#include <math.h>

struct Caixa {
    float comprimento, largura, altura;
};

float calcularVolume(struct Caixa c) {
    return c.comprimento * c.altura * c.largura;
}

int main() {
    struct Caixa volume;
    printf("Informe o comprimento");
    scanf("%f", &volume.comprimento);
    printf("Informe a largura");
    scanf("%f", &volume.largura);
    printf("Informe a altura");
    scanf("%f", &volume.altura);
    
    printf("O volume é: %.2f\n", calcularVolume(volume));
    return 0;
}