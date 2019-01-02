#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int num;
    char nome[20], tipo[20], origem[20], destino[20];
    struct Node *prox;
};
typedef struct Node aviao;
int tamd=0, tamp=0, tam=0;
//int menu(void);
//void opcao(aviao *FILA, int op);
void inicia(aviao *FILA);
int vazia(aviao *FILA);
aviao *aloca();
void insere(aviao *FILA, int opt);
aviao *retira(aviao *FILA, int opt);
void exibe(aviao *FILA);
void libera(aviao *FILA);
int main()
{
    aviao *decolagem, *pousar, *tmp;
    int opt, opt2, dado, verif;
    inicia(&decolagem);
    inicia(&pousar);
    do
    {
        opt2 = 0;

printf("\n                             \\   /");
printf("\n                              \\_/");
printf("\n                               |");
printf("\n                               |");
printf("\n                              ###");
printf("\n                              ###   ");
printf("\n                  ##########################");
printf("\n                  \\                       /");
printf("\n                   \\                     /");
printf("\n #########################################################");
printf("\n  \\                                                      /");
printf("\n   \\                   AEROPORTO F&T                    /");
printf("\n    \\                                                  /");
printf("\n     \\  |##########################################|  /");
printf("\n      \\ |  |________|________||________|________|  | /");
printf("\n       \\|__|________|________||________|________|__|/ ");
printf("\n          |                                      |  ");
printf("\n          |                                      |");
printf("\n          |                                      |");
printf("\n          |             DECOLAGEM                |");
printf("\n          |1. Adicionar aviao na fila de         |");
printf("\n          |decolagem                             |");
printf("\n          |2. Autorizar aviao para decolagem     |");
printf("\n          |3. Listar avioes na fila de decolagem |");
printf("\n          |4. Listar numero de avioes na fila    |");
printf("\n          |de decolagem                          |");
printf("\n          |                                      |");
printf("\n          |                POUSO                 |");
printf("\n          |5. Adicionar aviao na fila de pouso   |");
printf("\n          |6. Autorizar aviao da fila de pouso   |");
printf("\n          |7. Listar avioes na fila de pouso     |");
printf("\n          |8. Listar numero de avioes na fila    |");
printf("\n          |de pouso                              |");
printf("\n          |                                      |");
printf("\n          |                                      |");
printf("\n          |0.Sair                                |");
printf("\n          |                                      |\n");

        scanf("%d", &opt);
        system("cls");
        switch(opt)
        {
        case 1:
            opt2 = 1;
            insere(&decolagem, opt2);
            break;
        case 2:
            primeiro(&decolagem);
            opt2=1;
            tmp = retira(&decolagem,opt2);
            animadecolar();
            if(tmp!=NULL)
            {
                printf("Retirado: %3d\n\n", tmp->num);
                free(tmp);
            }
            break;
        case 3:

            exibe(&decolagem);
            break;
        case 4:
            lista(&decolagem);
            break;
        case 5:
            opt2 = 2;
            insere(&pousar, opt2);
            break;
        case 6:
            opt2=2;
            primeiro(&pousar);
            tmp = retira(&pousar,opt2);
            animapouso();
            if(tmp!=NULL)
            {
                printf("Retirado: %3d\n\n", tmp->num);
                free(tmp);
            }
            break;
        case 7:
            exibe(&pousar);
            break;
        case 8:
            lista(&pousar);
            break;
        case 0:
            break;
        default:
            printf("\n");
        }
    }
    while(opt!=0);
}
/*int main(void)
{
	aviao *decolar = (aviao *) malloc(sizeof(aviao));
	if(!decolar){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(decolar);
	int opt;
	do{
		opt=menu();
		opcao(decolar,opt);
	}while(opt);
	free(decolar);
	return 0;
	}
}
int menu(void)
{
	int opt;
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar fila\n");
	printf("2. Exibir fila\n");
	printf("3. Adicionar Elemento na Fila\n");
	printf("4. Retirar Elemento da Fila\n");
	printf("Opcao: "); scanf("%d", &opt);
	return opt;
}
void opcao(aviao *FILA, int op)
{
	aviao *tmp;
	switch(op){
		case 0:
			libera(FILA);
			break;
		case 1:
			libera(FILA);
			inicia(FILA);
			break;
		case 2:
			exibe(FILA);
			break;
		case 3:
			insere(decolar);
			break;
		case 4:
			tmp= retira(FILA);
			if(tmp != NULL){
				printf("Retirado: %3d\n\n", tmp->num);
				free(tmp);
			}
			break;
		default:
			printf("Comando invalido\n\n");
	}
}*/
void inicia(aviao *FILA)
{
    FILA->prox = NULL;
    tam=0, tamd=0, tamp=0;
}
int vazia(aviao *FILA)
{
    if(FILA->prox == NULL)
        return 1;
    else
        return 0;
}
aviao *aloca()
{
    aviao *novo=(aviao *) malloc(sizeof(aviao));
    if(!novo)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        printf("Codigo Aviao: ");
        scanf("%d", &novo->num);
        fflush(stdin);
        printf("Nome Piloto: ");
        scanf("%s",&novo->nome);
        fflush(stdin);
        printf("Origem de Partida: ");
        scanf("%s",&novo->origem);
        fflush(stdin);
        printf("Destino da Viagem: ");
        scanf("%s",&novo->destino);
        return novo;
    }
}
void insere(aviao *estado, int opt)
{
//    tam++;
//	if (opt=1){
//	tamd++;
//    }else{
//    	tamp++;
//    }
    aviao *novo=aloca();
    novo->prox = NULL;
    if(vazia(estado))
        estado->prox=novo;
    else
    {
        aviao *tmp = estado->prox;
        while(tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }



}
aviao *retira(aviao *FILA, int opt)
{
    if(FILA->prox == NULL)
    {
        printf("Fila ja esta vazia\n");
        return NULL;
    }
    else
    {
        aviao *tmp = FILA->prox;
        FILA->prox = tmp->prox;
//		tam--;
//		tamd--;
        return tmp;
    }
}
void exibe(aviao *estado)
{

    if(vazia(estado))
    {
        printf("Fila vazia!\n\n");
        return ;
    }
    aviao *tmp;
    tmp = estado->prox;
    printf("Fila: ");
    while( tmp != NULL)
    {
        printf("Piloto: %s ", tmp->nome);
        printf("Aviao: %d ", tmp->num);
        printf("Origem de Partida: %s ", tmp->origem);
        printf("Destino da Viagem: %s;\n", tmp->destino);
        tmp = tmp->prox;
    }
    printf("\n        ");
//	int count;
//	for(count=0 ; count < tamd ; count++)
//		printf("  ^  ");
//	printf("\nOrdem:");
//	for(count=0 ; count < tamd ; count++)
//		printf("%5d", count+1);
//	printf("\n\n");
}

void libera(aviao *FILA)
{
    if(!vazia(FILA))
    {
        aviao *proxNode,*atual;

        atual = FILA->prox;
        while(atual != NULL)
        {
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}
void lista(aviao *estado)
{
    int tama=0;
    if(vazia(estado))
    {
        printf("Fila vazia!\n\n");
        return ;
    }
    aviao *tmp;
    tmp = estado->prox;
    printf("Fila: ");
    while( tmp != NULL)
    {
        printf("Piloto: %s ", tmp->nome);
        printf("Aviao: %d;", tmp->num);
        tmp = tmp->prox;
        tama++;
    }
//	printf("\n        ");
//	int count;
//	for(count=0 ; count < tamd ; count++)
//		tama++;
    printf("\n%d",tama);

}

void primeiro(aviao *estado)
{

    if(vazia(estado))
    {
        printf("Fila vazia!\n\n");
        return ;
    }
    aviao *tmp;
    tmp = estado->prox;
    printf("Piloto: %s ", tmp->nome);
    printf("\nAviao: %d;   ", tmp->num);
    printf("\nOrigem de Partida: %s ", tmp->origem);
    printf("\nDestino da Viagem: %s; ", tmp->destino);
    tmp = tmp->prox;


}

void animapouso()
{
    int i, i2;


    for(i = 0; i<2; i++)
    {
        printf("\n           _____");
        printf("\n           \\ U \\__      _____");
        printf("\n            \\   \\/_______\\___\\_____________");
        printf("\n           < /_/   .....................  `-.");
        printf("\n            `-----------,----,--------------'");
        printf("\n                       _/____/");
        system("cls");
        for(i = 0; i<2; i++)
        {
            printf("\n\n\n\t           _____");
            printf("\n\t           \\ U \\__      _____");
            printf("\n\t            \\   \\/_______\\___\\_____________");
            printf("\n\t           < /_/   .....................  `-.");
            printf("\n\t            `-----------,----,--------------'");
            printf("\n\t                       _/____/");
            system("cls");

            for(i = 0; i<2; i++)
            {
                printf("\n\n\n\n\n\t\t           _____");
                printf("\n\t\t           \\ U \\__      _____");
                printf("\n\t\t            \\   \\/_______\\___\\_____________");
                printf("\n\t\t           < /_/   .....................  `-.");
                printf("\n\t\t            `-----------,----,--------------'");
                printf("\n\t\t                       _/____/");
                system("cls");

                for(i = 0; i<2; i++)
                {
                    printf("\n\n\n\n\n\t\t\t           _____");
                    printf("\n\t\t\t           \\ U \\__      _____");
                    printf("\n\t\t\t            \\   \\/_______\\___\\_____________");
                    printf("\n\t\t\t           < /_/   .....................  `-.");
                    printf("\n\t\t\t            `-----------,----,--------------'");
                    printf("\n\t\t\t                       _/____/");
                    system("cls");
                }
            }
        }
    }
}
void animadecolar()
{
    int i;
    for(i = 0; i<2; i++)
    {
        printf("\n\n\n\n\n\n\n           _____");
        printf("\n           \\ U \\__      _____");
        printf("\n            \\   \\/_______\\___\\_____________");
        printf("\n           < /_/   .....................  `-.");
        printf("\n            `-----------,----,--------------'");
        printf("\n                       _/____/");
        system("cls");
        for(i = 0; i<2; i++)
        {
            printf("\n\n\n\n\n\t           _____");
            printf("\n\t           \\ U \\__      _____");
            printf("\n\t            \\   \\/_______\\___\\_____________");
            printf("\n\t           < /_/   .....................  `-.");
            printf("\n\t            `-----------,----,--------------'");
            printf("\n\t                       _/____/");
            system("cls");

            for(i = 0; i<2; i++)
            {
                printf("\n\n\t\t           _____");
                printf("\n\t\t           \\ U \\__      _____");
                printf("\n\t\t            \\   \\/_______\\___\\_____________");
                printf("\n\t\t           < /_/   .....................  `-.");
                printf("\n\t\t            `-----------,----,--------------'");
                printf("\n\t\t                       _/____/");
                system("cls");

                for(i = 0; i<2; i++)
                {
                    printf("\n\t\t\t           _____");
                    printf("\n\t\t\t           \\ U \\__      _____");
                    printf("\n\t\t\t            \\   \\/_______\\___\\_____________");
                    printf("\n\t\t\t           < /_/   .....................  `-.");
                    printf("\n\t\t\t            `-----------,----,--------------'");
                    printf("\n\t\t\t                       _/____/");
                    system("cls");
                }
            }
        }
    }
}


