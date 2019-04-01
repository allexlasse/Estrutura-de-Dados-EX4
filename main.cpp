#include <iostream>
#include <cstring>
#include "Pilha.h"

using namespace std;

Pilha<char>P = Pilha<char>();
//A verificação funciona como uma checagem de escopo. Para cada parenteses aberto, deve haver outro fechado na exata posição oposta.
bool verifica(string s){
    char c;
    char aux;
    int i = 0;

    while(s[i] != '\0'){
        c = s[i];
        if(c == '(' || c == '{' || c == '['){
            P.empilha(c);
           }
        if(c == ')' || c == '}' || c == ']'){
            if(P.pilhavazia())
                return false;
            //Se o valor anterior a ')' não for '(', a string é inválida.
            if(c ==')'){
                aux = P.desempilha();
                if(aux != '(')
                    return false;
            }
            //Se o valor anterior a '}' não for '{', a string é inválida.
            if(c =='}'){
                aux = P.desempilha();
                if(aux != '{')
                    return false;
            }
            //Se o valor anterior a ']' não for '[', a string é inválida.
            if(c==']'){
                aux = P.desempilha();
                if(aux != '[')
                    return false;
            }
        }
    //Incrementa
    i+=1;
    }
    //Se for valido, a pilha deve estar vazia
    return P.pilhavazia();
}

int main()
{
    string input;

        cout<<"Entre com uma sequencia: ";
        cin>>input;

        if(verifica(input)){
            cout<<"Sequencia bem formada"<<endl;
        }
        else{
            cout<<"Sequencia mal formada"<<endl;
        }


    return 0;
}
