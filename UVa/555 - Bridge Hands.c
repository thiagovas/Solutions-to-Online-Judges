/*
     Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//CLUBS < DIAMONDS < SPADES < HEARTS
//2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < T < J < Q < K < A

typedef struct str_card{
    char suit, value;
} card;

int comp(const void *a, const void *b);
card* ReadDeck();
int ConvertDealerCharToInt(char dealer);
char ConvertDealerIntToChar(int dealer);
int ConvertSuit(char suit);
int ConvertCard(char card);

int comp(const void *a, const void *b)
{
    card *first = (card*)a, *second = (card*)b;
    
    if(ConvertSuit(first->suit) == ConvertSuit(second->suit))
        return ConvertCard(first->value) - ConvertCard(second->value);
    else
        return ConvertSuit(first->suit) - ConvertSuit(second->suit);
}

card* ReadDeck()
{
    card *deck = (card*)calloc(52, sizeof(card));
    int i = 0;
    
    while(i < 52)
    {
        card newCard;
        
        scanf("%c", &newCard.suit);
        if(!isalnum(newCard.suit)) continue;
        
        scanf("%c", &newCard.value);
        if(!isalnum(newCard.value)) continue;
        
        deck[i++] = newCard;
    }
    return deck;
}

int ConvertDealerCharToInt(char dealer)
{
    switch(dealer)
    {
        case 'S':
            return 0;
        case 'W':
            return 1;
        case 'N':
            return 2;
        case 'E':
            return 3;
        default:
            printf("Invalid Dealer. Inform a valid dealer(N, E, S, or W).\n");
            exit(1);
    }
}

char ConvertDealerIntToChar(int dealer)
{
    switch(dealer)
    {
        case 0:
            return 'S';
        case 1:
            return 'W';
        case 2:
            return 'N';
        case 3:
            return 'E';
        default:
            printf("Invalid Dealer.\n");
            exit(1);
    }
}

int ConvertSuit(char suit)
{
    switch(suit)
    {
        case 'C':
            return 0;
        case 'D':
            return 1;
        case 'S':
            return 2;
        case 'H':
            return 3;
        default:
            printf("'%c' %d Invalid Suit.\n", suit, suit);
            exit(1);
    }
}

int ConvertCard(char card)
{
    switch(card)
    {
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'A':
            return 14;
        default:
            return card-'0';
            break;
    }
}

void PrintSortedHands(card *deck, char dealer)
{
    int i = 0, j = 0;
    int S = 3-ConvertDealerCharToInt(dealer); // Guarda a posição da primeira carta que S recebe.
    card hand[13];
    
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
            hand[j] = deck[4*j + (i + S)%4];
        
        qsort(hand, 13, sizeof(card), comp);
        
        printf("%c:", ConvertDealerIntToChar(i));
        for(j = 0; j < 13; j++)
            printf(" %c%c", hand[j].suit, hand[j].value);
        printf("\n");
    }
}

int main()
{
    char dealer = '\0';
    card *deck = NULL;
    
    while(1)
    {
        scanf("%c", &dealer);
        if(!isalnum(dealer))
        {
            if(dealer == '#') break;
            else continue;
        }
        deck = ReadDeck();       
        PrintSortedHands(deck, dealer);
        free(deck);
    }
    
    return 0;
}
