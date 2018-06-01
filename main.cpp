//
//  main.cpp
//  Final_Bibiana
//
//  Created by Rafael do Canto Mazzochi on 01/06/18.
//  Copyright © 2018 Rafael do Canto Mazzochi. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int continua_menu=0, opcao_menu=0;
    
    while(continua_menu!=1){
        printf(" ------------------------------------------------- \n");
        printf("|   [1] - Digitar quantidade de cidades           | \n");
        printf("|   [2] - Digitar a distâncias entre as cidades   | \n");
        printf("|   [3] - Calcular a distância                    | \n");
        printf("|   [4] - Sair                                    | \n");
        printf(" ------------------------------------------------- \n\n");
        
        do{
            printf("Digite a sua opção: ");
            scanf("%d", &opcao_menu);
            if(opcao_menu<1 || opcao_menu>4){
                printf("Opção inválida, por favor tente novamente.\n\n");
            }
        }
        while(opcao_menu<1 || opcao_menu>4);
    }
    
    switch (opcao_menu) {
        case 1:
            break;
        
        case 2:
            break;
            
        case 3:
            break;
            
        case 4:
            exit(0);
    }
}
