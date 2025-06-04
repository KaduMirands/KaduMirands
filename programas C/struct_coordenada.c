#include <stdio.h>
#include <string.h>
#include <math.h>
struct Ponto {
    float x1;
    float x2;
    float y1;
    float y2;
    
};

float calcularDistancia(struct Ponto d) {
    return sqrt((x2 - x1) * 2 (y1 - y2) * 2);
}

int main(){
    struct Ponto dis1;
    printf("Informe a coordenada de x1:");
    scanf("%f", &dis1.x1);
    printf("Informe a coordenada de x2:");
    scanf("%f", &dis1.x2);
    printf("Informe a coordenada de y1:");
    scanf("%f", &dis1.y1);
      printf("Informe a coordenada de y2:");
    scanf("%f", &dis1.y2);
    
    
    
    printf("A distância é: %.2f\n", calcularDistancia(dis1));
    return 0;
}