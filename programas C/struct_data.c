#include <stdio.h>
#include <math.h>

struct Data {
    int dia, mes, ano;
};

void definirData(struct Data d) {
    printf("A data de hoje é: %02d/%02d/%04d", d.dia, d.mes, d.ano);
}

int main() {
    struct Data d;
    printf("Digite o dia:");
    scanf("%d", &d.dia);
    printf("Digite o mês:");
    scanf("%d", &d.mes);
    printf("Digite o ano:");
    scanf("%d", &d.ano);
    
    definirData(d);
    return 0;
    
}
