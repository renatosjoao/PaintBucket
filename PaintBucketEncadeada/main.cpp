/*
 *  PaintBucket com Pilha Encadeada
 *
 *  Created on: Mar 8, 2012
 *      Author: Renato Stoffalette Joao
 */


#include <iostream>
#include "PilhaEnc.h"


using namespace std;

typedef struct PONTO2D{
    int xi, yi;
    }PONTO2D;

int main(int argc, char** argv)
{
    PONTO2D pt2D,semente,vizDir,vizEsq,vizUp,vizDown;
    char ponto;
    PilhaEnc<PONTO2D> *p;
    p  = new PilhaEnc<PONTO2D>;
    char Matriz[10][10] = {	'X','X','X','X','X','X','X','X','X','X',
                            '.','X','.','.','.','.','.','.','.','.',
                            '.','X','.','.','.','.','.','.','.','.',
                            '.','X','.','.','.','.','.','.','.','.',
                            '.','X','.','.','.','.','.','.','.','.',
                            'X','X','X','X','.','.','X','.','X','X',
                            'X','X','X','X','.','.','.','.','X','X',
                            '.','X','X','X','.','.','X','.','.','X',
                            '.','.','.','X','.','.','.','.','.','.',
                            'X','X','X','X','X','.','X','X','X','X' };

    cout << " *** Implementacao do algoritmo PaintBucket (FloodFill) *** " << endl;
    cout <<""<< endl;
    cout << "Dada  a Matriz abaixo e um ponto Semente de coordenadas (3,3)" << endl;
    cout << "";
    semente.xi=3;
    semente.yi=3;
    for(int i=0; i<10; i++){
        cout <<""<< endl;
        for(int j=0; j<10; j++){
        cout << Matriz[i][j]<<" ";
        }
    }
    p->empilha(semente); // Empilhando o ponto inicial semente (3,3) que contem " . "
    while(!p->vazia()){
	pt2D = p->desempilha();
		if((pt2D.xi < 10)&&(pt2D.yi < 10)){
		    if(Matriz[pt2D.xi][pt2D.yi] == '.'){
		        Matriz[pt2D.xi][pt2D.yi] = 'X';
                vizDir.xi = pt2D.xi+1 ;
                vizDir.yi = pt2D.yi;
                vizEsq.xi = pt2D.xi-1;
                vizEsq.yi = pt2D.yi;
                vizUp.xi = pt2D.xi;
                vizUp.yi = pt2D.yi+1;
                vizDown.xi = pt2D.xi;
                vizDown.yi = pt2D.yi-1;

		        p->empilha(vizDir);
                p->empilha(vizEsq);
            	p->empilha(vizUp);
            	p->empilha(vizDown);
		    }
		}else{
		  }
	}
cout <<""<< endl;
cout <<""<< endl;
cout << " *** Apos aplicarmos o algoritmo PaintBucket *** " << endl;
cout << " *** obtemos a matriz de resultado abaixo *** " << endl;

 for(int i=0; i<10; i++){
        cout <<""<< endl;
        for(int j=0; j<10; j++){
        cout << Matriz[i][j]<<" ";
        }
    }
    return 0;
}

