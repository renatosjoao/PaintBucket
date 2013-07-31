/*
 * PilhaEnc.h
 *
 *  Created on: Mar 8, 2012
 *      Author: Renato Stoffalette Joao
 */


#include<iostream>
#include<stdlib.h>

#ifndef PILHAENC_H_
#define PILHAENC_H_


using namespace std;

//*********************************************************
template <typename Tipo>
class PilhaEnc{
	public:
		PilhaEnc();
		~PilhaEnc();
		void empilha(const Tipo &elem);
		Tipo desempilha();
		bool vazia();
		int tamanho();
	private:
		struct Celula{
			Tipo num;
			Celula *prox;
		};
		Celula *topo;
		int nelem;
};
//*********************************************************
template <typename Tipo>
PilhaEnc<Tipo>::PilhaEnc(){
	//topo = NULL;
	topo = NULL ;
	nelem = 0;
}
//*********************************************************
template <typename Tipo>
PilhaEnc<Tipo>::~PilhaEnc(){
	Celula *aux;
	while(topo){
		topo = topo->prox;
		delete aux;
	}
}
//*********************************************************
template <typename Tipo>
void PilhaEnc<Tipo>::empilha(const Tipo &elem){
	Celula *aux = new Celula;
	if(aux == NULL){ }
	aux->num = elem;
	aux->prox=topo;
	topo=aux;
	nelem++;
}
//*********************************************************
template <typename Tipo>
Tipo PilhaEnc<Tipo>::desempilha(){
	Celula *aux = topo;
	Tipo ret = topo->num;
	topo = topo->prox;
	delete aux;
	nelem--;
	return (ret);
}
//*********************************************************
template <typename Tipo>
bool PilhaEnc<Tipo>::vazia(){
	if(nelem==0){
		return 1;
	}
	return 0;
}
//*********************************************************
template <typename Tipo>
int PilhaEnc<Tipo>::tamanho(){
	return (nelem);
}
//*********************************************************
#endif /* PILHAENC_H_ */
