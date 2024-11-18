#include <stdio.h>
#include <string.h>
#include "pediatria.h"

paciente_t* primeiro_paciente(char *nome, int idade, float peso, float altura, char genero) {
    paciente_t* novo_paciente = (paciente_t*)malloc(sizeof(paciente_t));
    if (novo_paciente == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    strcpy(novo_paciente->nome, nome);
    novo_paciente->idade = idade;
    novo_paciente->peso = peso;
    novo_paciente->altura = altura;
    novo_paciente->genero = genero;
    novo_paciente->prox = NULL;

    return novo_paciente;
}

void novo_paciente(paciente_t *primeiro, char *nome, int idade, float peso, float altura, char genero) {
    paciente_t *atual = primeiro;


    while (atual->prox != NULL) {
        atual = atual->prox;
    }


    paciente_t* novo = primeiro_paciente(nome, idade, peso, altura, genero);
    atual->prox = novo;
}

IMCInfantil calcula_imc(paciente_t *crianca) {
        float imc = crianca->peso / (crianca->altura * crianca->altura);


    if (imc < 14.0) {
        return ABAIXO;
    } else if (imc >= 14.0 && imc < 18.0) {
        return NORMAL;
    } else if (imc >= 18.0 && imc < 25.0) {
        return SOBREPESO;
    } else {
        return OBESIDADE;
    }
}

void imprime_imc(paciente_t *crianca) {
    IMCInfantil imc = calcula_imc(crianca);

    printf("Nome: %s\n", crianca->nome);
    printf("Idade: %d\n", crianca->idade);
    printf("Peso: %.2f kg\n", crianca->peso);
    printf("Altura: %.2f m\n", crianca->altura);
    printf("Genero: %c\n", crianca->genero);

        switch (imc) {
        case ABAIXO:
            printf("IMC: Abaixo do peso\n");
            break;
        case NORMAL:
            printf("IMC: Peso normal\n");
            break;
        case SOBREPESO:
            printf("IMC: Sobrepeso\n");
            break;
        case OBESIDADE:
            printf("IMC: Obesidade\n");
            break;
    }
}

int main() {
        paciente_t* lista_pacientes = primeiro_paciente("João Silva", 10, 30.5, 1.35, 'M');


    novo_paciente(lista_pacientes, "Maria Oliveira", 9, 28.0, 1.30, 'F');
    novo_paciente(lista_pacientes, "Pedro Santos", 12, 40.5, 1.45, 'M');
    novo_paciente(lista_pacientes, "Ana Souza", 11, 35.0, 1.40, 'F');


    paciente_t* atual = lista_pacientes;
    while (atual != NULL) {
        imprime_imc(atual);
        atual = atual->prox;
    }

    return 0;
}
