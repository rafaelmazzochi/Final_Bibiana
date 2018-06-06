//
//  distancias.h
//  Final_Bibiana
//
//  Created by Rafael do Canto Mazzochi on 01/06/18.
//  Copyright © 2018 Rafael do Canto Mazzochi. All rights reserved.
//

#ifndef distancias_h
#define distancias_h
using namespace std;

void dist(int quantidade_cidades){
    float distancias[quantidade_cidades][quantidade_cidades];
    float mat_calc[quantidade_cidades][quantidade_cidades];
    float min=1500;
    float total=0;
    int cidade_inicial=0, cidade_destino=0;
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            distancias[linhas][colunas] = 0;
            mat_calc[linhas][colunas] = 0;
        }
    }
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            if(linhas !=  colunas){
                if(distancias[linhas][colunas] == 0){
                    printf("Digite a distância entre a cidade %d até %d: ", linhas+1, colunas+1);
                    scanf("%f", &distancias[linhas][colunas]);
                    printf("\n");
                    distancias[colunas][linhas] = distancias[linhas][colunas];
                }
            }
            else{
                distancias[linhas][colunas] = 0;
            }
        }
    }
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            printf("%.2f \t", distancias[linhas][colunas]);
            mat_calc[linhas][colunas] = distancias[linhas][colunas];
        }
        printf("\n");
    }
    
    //teste de cálculo
    
    printf("Digite o número da cidade de partida: ");
    scanf("%d", &cidade_inicial);
    cidade_inicial=cidade_inicial-1;
    
    min = 1500;
    total = 0;
    cidade_destino = 0;
    
    for(int linhas=0; linhas<quantidade_cidades;linhas++){
        if(linhas == cidade_inicial){
            for(int colunas=0;colunas<quantidade_cidades;colunas++){
                if(linhas != colunas){
                    if(mat_calc[linhas][colunas] != 0){
                        if(mat_calc[linhas][colunas] < min){
                            min = mat_calc[linhas][colunas];
                            mat_calc[colunas][linhas] = 0;
                            mat_calc[linhas][colunas] = 0;
                            total = total+min;
                            min = 1500;
                            cidade_destino = colunas;
                            cout << "Cidade Destido" << cidade_destino;
                            for(int l=0;l<quantidade_cidades;l++){
                                mat_calc[l][colunas] = 0;
                            }
                        }
                    }
                }
            }
        }
        if(cidade_destino != 0){
            for(int colunas=0;colunas<quantidade_cidades;colunas++){
                if(linhas != colunas){
                    if(mat_calc[linhas][colunas] != 0){
                        if(mat_calc[linhas][colunas] < min){
                            min = mat_calc[linhas][colunas];
                            mat_calc[colunas][linhas] = 0;
                            mat_calc[linhas][colunas] = 0;
                            total = total+min;
                            min = 1500;
                            cidade_destino = colunas;
                            for(int l=0;l<quantidade_cidades;l++){
                                mat_calc[l][colunas] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    //printf("Menor da coluna: %.2f \n\n", min);
    printf("Somta total: %.2f \n\n", total);
}

#endif /* distancias_h */
