#include <stdio.h>
int main(void){
	int capacity = 0,newCap,quantity=0,opt,inc,dec;
	bool run = true,crowded = false;
	while(run){
		printf("----------Sistema para controle do refeitorio----------\n");
		printf("Capacidade: %d\n",capacity);
		printf("Quantidade: %d\n",quantity);
		if(crowded) printf("\a(Refeitorio lotado)\a\n");
		printf("-------------------------------------------------------\n");
		printf("(1) Alterar capacidade       (2) Incrementar quantidade\n");
		printf("(3) Decrementar quantidade   (4) Sair\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Alterar para: ");
				scanf("%d",&newCap);
				if(newCap<0){
					printf("\n--------------------Dado invalido!----------------------\n");
					break;
				}
				capacity = newCap;
				break;
			case 2: 
				printf("Incrementar em: ");
				scanf("%d",&inc);
				if(inc<0){
					printf("\n--------------------Dado invalido!----------------------\n");
					break;
				}
				else if(quantity+inc>capacity){
					printf("\n----------------Capacidade insuficiente----------------\n");
					break;
				}
				quantity+=inc;
				break;
			case 3:
				printf("Decrementar em: ");
				scanf("%d",&dec);
				if(dec<0 || quantity-dec<0){
					printf("\n--------------------Dado invalido!----------------------\n");
					break;
				}
				quantity -= dec;
				break;
			case 4:
				printf("\n-------------------Finalizado--------------------------\n");
				run = false;
				break;
			default:
				printf("\n-----------------Opcao invalida!-----------------------\n");
				break;
		}
		if(quantity>=capacity&&quantity!=0&&capacity!=0) crowded = true;
		else crowded = false;
	}
	return 0;
}
