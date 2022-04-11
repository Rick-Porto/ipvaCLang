#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int TAM_MAX = 10;
const int MAX_PLACA = 8;
const int MAX_MODELO = 20;
const int MIN_MODELO = 5;

struct veiculo{
    char placa[MAX_PLACA];
    char modelo[MAX_MODELO];
    char tipo;
    float valor;
    char combustivel;
    float ipva;
};

bool verifica_placa(char placa[], int MAX_PLACA){

    if(strlen(placa) >= MAX_PLACA)
        return false;
    for(int i = 0; i < MAX_PLACA - 1; i++){
        if(i < 3){
            if(!isalpha(placa[i])){
                return false;
            }
        }
        else{
            if(!isdigit(placa[i])){
                return false;
            }
        }
    }
    return true;
}

bool verifica_modelo(char modelo[],int MIN_MODELO, int MAX_MODELO){

    if ((strlen(modelo) < MIN_MODELO || strlen(modelo) > MAX_MODELO) && modelo[0] != '\0')
        return false;
    else
        return true;
}

bool verifica_valor(float valor){

    if (valor < 500)
        return false;
    else
        return true;
}

void calcula_ipva(veiculo RegistroVeiculo[], int qtdveiculos){
    if(RegistroVeiculo[qtdveiculos].tipo == 'C' || RegistroVeiculo[qtdveiculos].tipo == 'c'){
        if(RegistroVeiculo[qtdveiculos].combustivel == 'E' || RegistroVeiculo[qtdveiculos].combustivel == 'e')
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.05 * 0.9;

        else if(RegistroVeiculo[qtdveiculos].combustivel == 'G' || RegistroVeiculo[qtdveiculos].combustivel == 'g')
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.05 * 0.95;

        else
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.05 * 0.93;
    }
    else if(RegistroVeiculo[qtdveiculos].tipo == 'M' || RegistroVeiculo[qtdveiculos].tipo == 'm'){
        if(RegistroVeiculo[qtdveiculos].combustivel == 'E' || RegistroVeiculo[qtdveiculos].combustivel == 'e')
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.03 * 0.95;

        else
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.03 * 0.98;

    }
    else{
        if(RegistroVeiculo[qtdveiculos].combustivel == 'G' || RegistroVeiculo[qtdveiculos].combustivel == 'g')
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.07 * 0.97;

        else
            RegistroVeiculo[qtdveiculos].ipva = RegistroVeiculo[qtdveiculos].valor * 0.07 * 0.9;
    }
}

void ler_veiculos(veiculo RegistroVeiculo[], int &qtdveiculos){

    printf("Digite a Placa do Veiculo: ");
    scanf("%s", &RegistroVeiculo[qtdveiculos].placa);
    while(!verifica_placa(RegistroVeiculo[qtdveiculos].placa, MAX_PLACA)){
       printf("Valor Invalido.\n");
       printf("Digite a Placa do Veiculo: ");
       scanf("%s", &RegistroVeiculo[qtdveiculos].placa);
    }

    printf("Digite o Modelo do Veiculo: ");
    scanf("%s", &RegistroVeiculo[qtdveiculos].modelo);
    while(!verifica_modelo(RegistroVeiculo[qtdveiculos].modelo, MIN_MODELO, MAX_MODELO)){
       printf("Quantidade minima 5 caracteres e maxima 30 caracteres.\n");
       printf("Digite o Modelo do Veiculo: ");
       scanf("%s", &RegistroVeiculo[qtdveiculos].modelo);
    }

    puts("------------");
    puts("  Registro");
    puts("------------");
    puts("C - Carro");
    puts("M - Moto");
    puts("H - Caminhao");
    getchar();
    scanf("%c", &RegistroVeiculo[qtdveiculos].tipo);
    while((RegistroVeiculo[qtdveiculos].tipo != 'C' && RegistroVeiculo[qtdveiculos].tipo != 'c')
    && (RegistroVeiculo[qtdveiculos].tipo != 'M' && RegistroVeiculo[qtdveiculos].tipo != 'm')
    && (RegistroVeiculo[qtdveiculos].tipo != 'H' && RegistroVeiculo[qtdveiculos].tipo != 'h')){
        puts("Caracter Invalido.");
        puts("------------");
        puts("  Registro");
        puts("------------");
        puts("C - Carro");
        puts("M - Moto");
        puts("H - Caminhao");
        getchar();
        scanf("%c", &RegistroVeiculo[qtdveiculos].tipo);
    }

    printf("Digite o Valor do Veiculo: ");
    scanf("%f", &RegistroVeiculo[qtdveiculos].valor);
    while(!verifica_valor(RegistroVeiculo[qtdveiculos].valor)){
       printf("Valor Invalido. Valor Tem que ser >= 500,00\n");
       printf("Digite o Valor do Veiculo: ");
       scanf("%f", &RegistroVeiculo[qtdveiculos].valor);
    }

    if(RegistroVeiculo[qtdveiculos].tipo == 'C' || RegistroVeiculo[qtdveiculos].tipo == 'c'){
        puts("------------");
        puts("  Registro");
        puts("------------");
        puts("E - Etanol");
        puts("G - Gasolina");
        puts("D - Diesel");
        getchar();
        scanf("%c", &RegistroVeiculo[qtdveiculos].combustivel);
        while(RegistroVeiculo[qtdveiculos].combustivel != 'E' && RegistroVeiculo[qtdveiculos].combustivel != 'e'
        && RegistroVeiculo[qtdveiculos].combustivel != 'G' && RegistroVeiculo[qtdveiculos].combustivel != 'g'
        && RegistroVeiculo[qtdveiculos].combustivel != 'D' && RegistroVeiculo[qtdveiculos].combustivel != 'd'){
            puts("------------");
            puts("  Registro");
            puts("------------");
            puts("E - Etanol");
            puts("G - Gasolina");
            puts("D - Diesel");
            getchar();
            scanf("%c", &RegistroVeiculo[qtdveiculos].combustivel);
        }
    }
    else if(RegistroVeiculo[qtdveiculos].tipo == 'M' || RegistroVeiculo[qtdveiculos].tipo == 'm'){
        puts("------------");
        puts("  Registro");
        puts("------------");
        puts("E - Etanol");
        puts("G - Gasolina");
        getchar();
        scanf("%c", &RegistroVeiculo[qtdveiculos].combustivel);
        while(RegistroVeiculo[qtdveiculos].combustivel != 'E' && RegistroVeiculo[qtdveiculos].combustivel != 'e'
        && RegistroVeiculo[qtdveiculos].combustivel != 'G' && RegistroVeiculo[qtdveiculos].combustivel != 'g'){
            puts("------------");
            puts("  Registro");
            puts("------------");
            puts("E - Etanol");
            puts("G - Gasolina");
            getchar();
            scanf("%c", &RegistroVeiculo[qtdveiculos].combustivel);
        }
    }
    else{
        puts("------------");
        puts("  Registro");
        puts("------------");
        puts("G - Gasolina");
        puts("D - Diesel");
        getchar();
        scanf("%c", &RegistroVeiculo[qtdveiculos].combustivel);
        while(RegistroVeiculo[qtdveiculos].combustivel != 'G' && RegistroVeiculo[qtdveiculos].combustivel != 'g'
        && RegistroVeiculo[qtdveiculos].combustivel != 'D' && RegistroVeiculo[qtdveiculos].combustivel != 'd'){
            puts("------------");
            puts("  Registro");
            puts("------------");
            puts("G - Gasolina");
            puts("D - Diesel");
            getchar();
            scanf("%c", &RegistroVeiculo[qtdveiculos].combustivel);
        }
    }

    calcula_ipva(RegistroVeiculo, qtdveiculos);
    qtdveiculos++;
}

imprimir_veiculos(veiculo RegistroVeiculo[], int qtdveiculos){

    puts("--------------------------------------------------------------");
    puts("Placa   Modelo               Tipo Valor    Comb.   IPVA");
    puts("--------------------------------------------------------------");
    for(int i = 0; i < qtdveiculos; i++)
        printf("%s %-20s %-4c %-9.2f %-5c %-9.2f\n", RegistroVeiculo[i].placa,
                                                  RegistroVeiculo[i].modelo,
                                                  RegistroVeiculo[i].tipo,
                                                  RegistroVeiculo[i].valor,
                                                  RegistroVeiculo[i].combustivel,
                                                  RegistroVeiculo[i].ipva);
}

void ordena_veiculos(veiculo RegistroVeiculo[], int qtdveiculos, char opcao, char opcao2){

    veiculo OrdernarPlaca[qtdveiculos];
    for(int i = 0; i < qtdveiculos; i++)
        OrdernarPlaca[i] = RegistroVeiculo[i];
    if(opcao == 'P' || opcao == 'p'){
       if(opcao2 == 'C' || opcao2 == 'c'){
            bool trocou = true;

            for (int k = qtdveiculos-1; k > 0 && trocou; k--)
            {
                trocou = false;
                for (int i = 0; i < k; i++)
                    if (strcmp(OrdernarPlaca[i].placa, OrdernarPlaca[i+1].placa) > 0)
                    {
                        veiculo aux = OrdernarPlaca[i+1];
                        OrdernarPlaca[i+1] = OrdernarPlaca[i];
                        OrdernarPlaca[i] = aux;
                        trocou = true;
                    }
            }
            imprimir_veiculos(OrdernarPlaca, qtdveiculos);
       }
       else{
            bool trocou = true;

            for (int k = qtdveiculos-1; k > 0 && trocou; k--)
            {
                trocou = false;
                for (int i = 0; i < k; i++)
                    if (strcmp(OrdernarPlaca[i].placa, OrdernarPlaca[i+1].placa) < 0)
                    {
                        veiculo aux = OrdernarPlaca[i+1];
                        OrdernarPlaca[i+1] = OrdernarPlaca[i];
                        OrdernarPlaca[i] = aux;
                        trocou = true;
                    }
            }
            imprimir_veiculos(OrdernarPlaca, qtdveiculos);
       }
    }

    else{
        if(opcao2 == 'C' || opcao2 == 'c'){
            bool trocou = true;

            for (int k = qtdveiculos-1; k > 0 && trocou; k--)
            {
                trocou = false;
                for (int i = 0; i < k; i++)
                    if (OrdernarPlaca[i].ipva > OrdernarPlaca[i+1].ipva)
                    {
                        veiculo aux = OrdernarPlaca[i+1];
                        OrdernarPlaca[i+1] = OrdernarPlaca[i];
                        OrdernarPlaca[i] = aux;
                        trocou = true;
                    }
            }
            imprimir_veiculos(OrdernarPlaca, qtdveiculos);
        }
        else{
            bool trocou = true;

            for (int k = qtdveiculos-1; k > 0 && trocou; k--)
            {
                trocou = false;
                for (int i = 0; i < k; i++)
                    if (OrdernarPlaca[i].ipva < OrdernarPlaca[i+1].ipva)
                    {
                        veiculo aux = OrdernarPlaca[i+1];
                        OrdernarPlaca[i+1] = OrdernarPlaca[i];
                        OrdernarPlaca[i] = aux;
                        trocou = true;
                    }
            }
            imprimir_veiculos(OrdernarPlaca, qtdveiculos);
        }
    }
}

int main(){
    int n, qtdveiculos = 0;
    veiculo RegistroVeiculo[TAM_MAX];
    char opcao, opcao2;

    printf("Digite a quantidade de Veiculos para Registrar: ");
    scanf("%d", &n);
    while(n <= 0 || n > 10)
    {
        printf("Valor invalido\n");
        printf("Digite a quantidade de Veiculos para Registrar: ");
        scanf("%d", &n);
    }

    for(int i = 0; i < n; i++){
        ler_veiculos(RegistroVeiculo, qtdveiculos);
    }

    getchar();
    printf("Ordernar por P - Placa ou I - IPVA: ");
    scanf("%c", &opcao);

    while(opcao != 'P' && opcao != 'p' && opcao != 'I' && opcao != 'i')
    {
        printf("Opcao invalida\n");
        printf("Ordernar por P - Placa ou I - IPVA: ");
        scanf("%c", &opcao);
    }

    getchar();
    printf("Ordernar por C - Crescente ou D - Decrescente: ");
    scanf("%c", &opcao2);

    while(opcao2 != 'C' && opcao2 != 'c' && opcao2 != 'D' && opcao2 != 'd')
    {
        printf("Opcao invalida\n");
        printf("Ordernar por C - Crescente ou D - Decrescente: ");
        scanf("%c", &opcao2);
    }

    ordena_veiculos(RegistroVeiculo, qtdveiculos, opcao, opcao2);

}
