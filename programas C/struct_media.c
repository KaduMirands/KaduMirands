#include <stdio.h>
#include <string.h>
struct aluno {
    float historia;
    float matematica;
    float geografia;
};

float calcularMedia(struct aluno n) {
    return n.historia + n.matematica + n.geografia / 2;
}

int main(){
    struct aluno not1;
    printf("Informe a nota em historia:");
    scanf("%f", &not1.historia);
    printf("Informe a nota em matematica:");
    scanf("%f", &not1.matematica);
    printf("Informe a nota em geografia:");
    scanf("%f", &not1.geografia);
    
    
    printf("A média é: %.2f\n", calcularMedia(not1));
    return 0;
}