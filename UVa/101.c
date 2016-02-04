/*
 *	 Feito por Thiago Vieira
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str_item_list{
    int index;
    struct str_item_list *next;
} item_list;

typedef struct{
	item_list *head;
	int whereis;
} list;


//Inicializa as pilhas de blocos.
void initlists(list *pilhas, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        pilhas[i].head = (item_list*) malloc(sizeof(item_list));
        pilhas[i].head->index = -1;
        pilhas[i].whereis = i;
        pilhas[i].head->next = (item_list*) malloc(sizeof(item_list));
        pilhas[i].head->next->index = i;
    	pilhas[i].head->next->next =NULL;
    }
}

//Printa as pilhas de blocos.
void printlists(list *pilhas, int n)
{
    item_list *aux;
    int i;
    
    for(i = 0; i < n; i++)
    {
        aux = (pilhas[i]).head->next;
        printf("%d:", i);
        
        while(aux != NULL)
        {
            printf(" %d", aux->index);
            aux = aux->next;
        }
        printf("\n");
    }
}

//Atualiza os campos whereis de todas as stacks.
void refreshwhereis(list *stacks, int n)
{
    item_list *aux = NULL;
    int i = 0;
    
    for(i = 0; i < n; i++)
    {
	    aux = stacks[i].head->next;
	
	    while(aux != NULL)
	    {
		    stacks[aux->index].whereis = i;
            aux = aux->next;
        }
    }
}

//Adiciona um item na pilhas de blocos a.
void Push(list *stacks, item_list *item, int a)
{
	item_list *aux = stacks[a].head;
	while(aux->next != NULL)
	    aux = aux->next;
    aux->next = item;
        
	refreshwhereis(stacks, a);
}

//Retira um item da pilha de blocos a.
void Pop(list *stacks, item_list **item, int a)
{
	item_list *aux = stacks[a].head;
	
	*item = NULL;
	if(aux->next == NULL) return;
	
	while(aux->next->next != NULL)
		aux = aux->next;
	
	*item = aux->next;
	aux->next = NULL;
}

//Função que acha um elemento com valor value, na stack 'a'.
//Retorna o ponteiro do elemento anterior.
item_list* find(list *stacks, int a, int value)
{
	item_list *aux = stacks[a].head;
	while(aux->next != NULL && aux->next->index != value)
		aux = aux->next;
	
	return (aux->next == NULL) ? NULL : aux;
}

/*
	1º while: Executa no máximo n loops, onde n é o número de blocos.
	2º while: Executa no máximo n menos m, onde m é o número de loops executados pelo 1º while.
	Em suma, O(n).
*/
void moveonto(list *stacks, int a, int b)
{
	item_list *auxa = NULL, *auxb = NULL;
    int index = stacks[b].whereis;
    
	while(1)
	{
		Pop(stacks, &auxa, stacks[a].whereis);
		
		if(auxa->index == a) break;
		auxa->next = NULL;
		//Retorno o bloco para a sua posição de origem.
		Push(stacks, auxa, auxa->index);
	}
	
	while(1)
	{
		Pop(stacks, &auxb, stacks[b].whereis);
		if(auxb->index == b) break;
		
		auxb->next = NULL;
		//Retorno o bloco para a sua posição de origem.
		Push(stacks, auxb, auxb->index);
	}
	auxb->next = auxa;
	auxb->next->next = NULL;
	Push(stacks, auxb, index);
}

/*
	1º while: Executa no máximo n loops, onde n é o número de blocos.
	O(n).
*/
void moveover(list *stacks, int a, int b)
{
	item_list *auxa = NULL;
	int index = stacks[b].whereis;
	
	while(1)
	{
		Pop(stacks, &auxa, stacks[a].whereis);
		if(auxa->index == a) break;
		
		auxa->next = NULL;
		//Retorno o bloco para a sua posição de origem.
		Push(stacks, auxa, auxa->index);
	}
	auxa->next = NULL;
	Push(stacks, auxa, index);
}

void pileonto(list *stacks, int a, int b)
{
	item_list *auxa = find(stacks, stacks[a].whereis, a);
	item_list *auxb = find(stacks, stacks[b].whereis, b);
	item_list *aux = NULL;
	
	while(auxb->next->next != NULL)
	{
		Pop(stacks, &aux, stacks[b].whereis);
		aux->next = NULL;
		Push(stacks, aux, aux->index);
	}
	
	auxb->next->next = auxa->next;
	auxa->next = NULL;
}

void pileover(list *stacks, int a, int b)
{
	item_list *auxa = find(stacks, stacks[a].whereis, a);
	
	Push(stacks, auxa->next, stacks[b].whereis);
	auxa->next = NULL;
}

int main()
{
	/*
		n guarda o número de pilhas.
		in1 e in2 serve para pegar o comando informado.
	*/
    int n, in1, in2;
    char cmd1[10], cmd2[10]; //Guarda os comandos recebidos
    list *pilhas;
    
    scanf("%d", &n);
    pilhas = (list*)calloc(n, sizeof(list));
    initlists(pilhas, n);
    
    while(1)
    {
        scanf("%s", cmd1);
        if(!strcmp(cmd1, "quit")) break;
        
        scanf("%d", &in1);
        scanf("%s", cmd2);
        scanf("%d", &in2);
        
        //Se os dois blocos estiverem na mesma pilha, só ignoro o comando informado.
        if(pilhas[in1].whereis == pilhas[in2].whereis) continue;
        
        if(!strcmp(cmd1, "move"))
        {
            if(!strcmp(cmd2, "over"))
                moveover(pilhas, in1, in2);
            else
                moveonto(pilhas, in1, in2);
        }
        else
        {
            if(!strcmp(cmd2, "over"))
            	pileover(pilhas, in1, in2);
            else
                pileonto(pilhas, in1, in2);
        }
        refreshwhereis(pilhas, n);
    }
    
    printlists(pilhas, n);
    free(pilhas);
    return 0;
}
