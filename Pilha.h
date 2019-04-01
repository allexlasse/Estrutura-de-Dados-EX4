#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

template<typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template<typename Tipo>
struct Pilha{

    Node<Tipo> *topo;

    Pilha(){
        topo = NULL;
    }

    bool empilha(Tipo t){
        bool verifica = false;
        Node<Tipo> *aux = new Node<Tipo>;
        if(aux != NULL){
            verifica = true;
            aux->info = t;
            aux->prox = topo;
            topo = aux;
        }
        return verifica;
    }

    Tipo desempilha(){
        Tipo aux2 = topo->info;
        Node<Tipo> *aux = topo;
        topo = topo->prox;
        delete aux;
        return aux2;
    }

    bool pilhavazia(){
        return topo == NULL;
    }
};


#endif // PILHA_H_INCLUDED
