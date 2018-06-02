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
#include "quant_cidades.h"
#include "distancias.h"
using namespace std;

int main(){
    int continua_menu=0, opcao_menu=0, quantidade_cidades=0;
    
    while(continua_menu!=1){
        cout <<" ------------------------------------------------- \n";
        cout <<"|   [1] - Digitar quantidade de cidades           | \n";
        cout <<"|   [2] - Digitar a distâncias entre as cidades   | \n";
        cout <<"|   [3] - Mostrar Rsultado                        | \n";
        cout <<"|   [4] - Sair                                    | \n";
        cout <<" ------------------------------------------------- \n\n";
        
        do{
            cout << "Digite a sua opção:" ;
            cin >> opcao_menu;
            if(opcao_menu<1 || opcao_menu>4){
                cout <<"Opção inválida, por favor tente novamente.\n\n";
            }
        }
        while(opcao_menu<1 || opcao_menu>4);
        
        switch (opcao_menu) {
            case 1:
                
                quantidade_cidades = quant_cidades();
                
                cout << quantidade_cidades << " Cidades \n";
                
                break;
                
            case 2:
                
                dist(quantidade_cidades);
                
                break;
                
            case 3:
                break;
                
            case 4:
                exit(0);
        }
    }
}
