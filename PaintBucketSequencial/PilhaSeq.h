#include <iostream>

#ifndef PILHASEQ_H_
#define PILHASEQ_H_

using namespace std;

//***************declaração da pilha***********************
template <typename Tipo>
class PilhaSeq {
	public:
		PilhaSeq(int size);
		~PilhaSeq();

		void empilha(const Tipo &elem);
		Tipo desempilha();
		bool cheia();
		bool vazia();
		int tamanho();

	private:
		Tipo *vetor;
		int topo,size;
};

//***Construtor********************************************
template <typename Tipo>
PilhaSeq<Tipo>::PilhaSeq(int size){
	this->size = size;
	vetor = new Tipo[size];
	topo = -1;
}
//***Destrutor*********************************************
template<typename Tipo>
PilhaSeq<Tipo>::~PilhaSeq(){
	delete [] vetor;
}
//***Empilha***********************************************
template<typename Tipo>
void PilhaSeq<Tipo>::empilha(const Tipo &elem){
	if(topo == (size -1 )){
		 //TODO
		}else{
			vetor[++topo]=elem;
		}
}
//***Desempilha********************************************
template<typename Tipo>
Tipo PilhaSeq<Tipo>::desempilha(){
	if(topo<0){
		 //TODO
	}
	//cout << *vetor ;
	return (vetor[topo--]);
}
//***Cheia*************************************************
template<typename Tipo>
bool PilhaSeq<Tipo>::cheia(){
	if(topo == (size - 1) ){
		return 1;
	}
	return 0;

}
//***Vazia*************************************************
template<typename Tipo>
bool PilhaSeq<Tipo>::vazia(){
	if(topo == -1){
		return 1;
	}
	return 0;
}
//***Tamanho***********************************************
template<typename Tipo>
int PilhaSeq<Tipo>::tamanho(){
	return(topo + 1);
}

#endif
