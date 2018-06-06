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
    int caminho[quantidade_cidades][quantidade_cidades];
    float min=1500, total[quantidade_cidades];
    int cidade_inicial=0, cidade_destino=0;
    int achou=0;
    int ci=0;
    int controle=0;
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            distancias[linhas][colunas] = 0;
            mat_calc[linhas][colunas] = 0;
            caminho[linhas][colunas] = 0;
            total[linhas]=0;
        }
    }
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            if(linhas !=  colunas){
                if(distancias[linhas][colunas] == 0){
                    cout << "Digite a distância entre a cidade " << linhas+1 << " até a cidade " << colunas+1 << "  ";
                    cin >> distancias[linhas][colunas];
                    cout << "\n";
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
            cout <<  distancias[linhas][colunas] << "\t" ;
            mat_calc[linhas][colunas] = distancias[linhas][colunas];
        }
        cout << "\n";
    }
    
    //teste de cálculo
    
    cout << "Digite o número da cidade de partida: ";
    cin >> cidade_inicial;
    cout << "\n";
    cidade_inicial=cidade_inicial-1;
    
    min = 1500;
    cidade_destino = 0;
    
    while(achou <= quantidade_cidades){
        min = 1500;
        for(int linhas=0; linhas<quantidade_cidades;linhas++){
            if(linhas == cidade_inicial){
                for(int colunas=0;colunas<quantidade_cidades;colunas++){
                    if(linhas != colunas){
                        if(mat_calc[linhas][colunas] != 0){
                            if(mat_calc[linhas][colunas] < min){
                                min = mat_calc[linhas][colunas];
                                //caminho[linhas][colunas] = 1;
                                total[linhas] = min;
                                cout << "Resultado "<< linhas +1 << " : " << total[linhas] <<"\n" ;
                                ci = colunas;
                            }
                        }
                    }
                }
            }
        }
        
        cidade_inicial = ci;
        
        for(int linhas=0; linhas<quantidade_cidades;linhas++){
            if(linhas == cidade_inicial){
                for(int colunas=0;colunas<quantidade_cidades;colunas++){
                    if(linhas != colunas){
                        if(mat_calc[linhas][colunas] != 0){
                            if(mat_calc[linhas][colunas] == min){
                                caminho[linhas][colunas] = 1;
                                for(int l=0;l<quantidade_cidades;l++){
                                    mat_calc[l][colunas] = 0;
                                }
                                total[linhas] = min;
                                caminho[linhas][colunas] = 1;
                            }
                        }
                    }
                }
            }
        }
        //if(controle == 5){
            //achou =1;
        //}
        achou ++;
    }
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            /*if(caminho[linhas][colunas] == 1){
             controle = controle+1;
             cout << controle << " \n";
             }*/
            cout << caminho[linhas][colunas] << "\t";
        }
        cout << "\n";
    }
    
    cout << "\n\n\n" ;
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            cout << mat_calc[linhas][colunas] << "\t";
        }
        cout << "\n";
    }
    
    cout << "\n\n\n" ;
    
    
    printf("Menor da coluna: %.2f \n\n", min);
    //printf("Soma total: %.2f \n\n", total);
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        cout << "Resultado " << linhas+1 << ": " << total[linhas] <<"\n";
    }
}

#endif /* distancias_h */
