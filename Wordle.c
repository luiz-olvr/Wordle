#include <stdio.h>
#include <string.h>


#define TAMANHO_PALAVRA 5
#define MAX_TENTATIVAS 6

//Variáveis globais de controle
char palavraChave [5]= "audio";
char tentativa[TAMANHO_PALAVRA];
int tentativas = 0;
int err = 0;
int tent = 1;

int main(void)
{
    printf("Bem-vindo ao Wordle (Termo)!\n");
    while(tent == 1){
    
    while(tentativas < MAX_TENTATIVAS) {
        printf("\n\nTentativa %d de %d\n", tentativas + 1, MAX_TENTATIVAS);
        printf("Digite sua palavra: ");
        scanf("%s", tentativa);
        
        //verificar se a palavra é igual ou Não
        
        if(strcmp(tentativa,palavraChave) == 0){
            break;
        }
        
        
        printf("\nSua tentavia foi: %s\n", tentativa);
        printf("\nSeus acertos foram: ");
        

        // Implementar a lógica de verificação da tentativa aqui
        
         for (int i = 0; i < TAMANHO_PALAVRA; i++) {
            err = 0;
            for(int j = 0; j < TAMANHO_PALAVRA; j++){
                if (tentativa[i] == palavraChave[j] && i == j) {
                    printf("*");}
            
                if(tentativa[i] == palavraChave[j] && i != j){
                    printf("+");}

                if(tentativa[i] != palavraChave[j] && i == j && err == 0){
                    printf("X");
                    err = 1;}
            }
        }
        
        tentativas++;
    }

   if(strcmp(tentativa,palavraChave) == 0){ 
        printf("\nMeus parabens, voce acertou\nA palavra era %s\n", palavraChave);}
    else{
        printf("\nInfelizmente suas chances acabaram, voce perdeu\nA palavra era %s\n",palavraChave);}
    printf("\n\nQuer jogar novamente? \n[1] Sim\n[0] Não");
    scanf("%d", &tent);
    if (tent == 1){tentativas = 0;}
    else{
        printf("\nObrigado por jogar, volte sempre!!\n");
    }
}
    return 0;
}