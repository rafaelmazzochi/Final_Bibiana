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
    int ci=0, guard_ci=0;
    float soma=0;
    
    /*
      + ----------------------------------------------------------------------------- +
      | Declaração de variáveis                                                       |
      + ----------------------------------------------------------------------------- +
     */
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            distancias[linhas][colunas] = 0;
            mat_calc[linhas][colunas] = 0;
            caminho[linhas][colunas] = 0;
            total[linhas]=0;
        }
    }
    
    /*
      + ----------------------------------------------------------------------------- +
      | Função para percorrer todas as matrizes e vetores do programa para todos      |
      | iniciarem em 0.                                                               |
      + ----------------------------------------------------------------------------- +
     */
    
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
    
    /*
        + ----------------------------------------------------------------------------- +
        | Solicita para o usuário digitar a distância entre as cidades, de acordo com   |
        | o número de cidades informada na função anterior.                             |
        + ----------------------------------------------------------------------------- +
     */
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            cout <<  distancias[linhas][colunas] << "\t" ;
            mat_calc[linhas][colunas] = distancias[linhas][colunas];
        }
        cout << "\n";
    }
    
    /*
      + -------------------------------------------------------------------- +
      | Copia a matriz principal para uma secundária para realizar o cálculo |
      + -------------------------------------------------------------------- +
     */
    
    cout << "Digite o número da cidade de partida: ";
    cin >> cidade_inicial;
    cout << "\n";
    cidade_inicial=cidade_inicial-1;
    guard_ci = cidade_inicial;
    
    /*
     + -------------------------------------------------------------------- +
     | Usuário digita a cidade inicial do trajeto.                          |
     + -------------------------------------------------------------------- +
     */
    
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
                                ci = colunas;
                            }
                        }
                    }
                }
            }
        }
        
        cidade_inicial = ci;
        cout << "\n Cidade destino: " << cidade_inicial+1 << "\n" ;
        system( "read -n 1 -s -p \"Press any key to continue...\"" ); // se for usar no windows trocar pra: system('pause');
        cout << "\n\n";
        
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
                                //cout << "Resultado "<< linhas +1 << " : " << total[linhas] <<"\n" ;
                            }
                        }
                    }
                }
            }
        }
        achou ++;
        /*
         + ------------------------------------------------------------------------------------------- +
         | Verificações do programa, encontra a cidade inicial (linha), vai procurar o menor           |
         | caminho (colunas) para a próxima cidade, irá verificar todas as cidades que a distância for |
         | diferente de 0. Quando encontrar, irá zerar a coluna inteira para identificar que já passou |
         | por aquela cidade, quando encontrou o menor, armazena dentro de um vetor o valor para que   |
         | seja somado no final e apresente o menor caminho para visitar todas as cidades.             |
         + ------------------------------------------------------------------------------------------- +
         */
    }
    
    soma = 0;
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        if(linhas == ci){
            for(int colunas=0;colunas<quantidade_cidades;colunas++){
                if(colunas == guard_ci){
                    for(int l=0;l<quantidade_cidades;l++){
                        if(total[l] == 0){
                            total[l] = distancias[linhas][colunas];
                        }
                        soma=soma+total[l];
                    }
                }
            }
        }
    }
    
    /*
     + ------------------------------------------------------------------------- +
     | Após terminar os cálculos, a condição acima vai pegar a ultima posição    |
     | que parou, e vai somar o valor de distância até o ponto incial (valor de  |
     | volta), para obter o valor total.                                         |
     + ------------------------------------------------------------------------- +
     */
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            cout << caminho[linhas][colunas] << "\t";
        }
        cout << "\n";
    }
    
    /*
        + ------------------------------------------------------------------------- +
        | Matriz para mostrar o caminho, por quais pontos a matriz percorreu.       |
        + ------------------------------------------------------------------------- +
     */
    
    cout << "\n\n\n" ;
    
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        for(int colunas=0;colunas<quantidade_cidades;colunas++){
            cout << mat_calc[linhas][colunas] << "\t";
        }
        cout << "\n";
    }
    /*
        + ------------------------------------------------------------------------- +
        | Matriz para mostrar que zerou todas as cidades que foram visitadas.       |
        + ------------------------------------------------------------------------- +
     */
    
    cout << "\n\n\n" ;
    
    
    printf("Menor da coluna: %.2f \n\n", min);
    for(int linhas=0;linhas<quantidade_cidades;linhas++){
        cout << "Resultado " << linhas+1 << ": " << total[linhas] <<"\n";
    }
    
    /*
        + ------------------------------------------------------------------------- +
        | Apresenta o vetor que guardou os resultados de cada cidade visitada       |
        + ------------------------------------------------------------------------- +
     */
    
    cout << "Soma final: " << soma << "\n";
    
    /*
        + ------------------------------------------------------------------------- +
        | Apresenta a soma total dos resultados, mostrando o valor final.           |
        + ------------------------------------------------------------------------- +
     */
}

#endif /* distancias_h */
