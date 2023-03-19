#include "dfa.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;


int getIndex(vector <char> v, char k)
{
    auto it = find(v.begin(), v.end(), k);
  
    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    return -1;

}

int getIndex(vector <int> v, int k)
{
    auto it = find(v.begin(), v.end(), k);
  
    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    return -1;

}


int DFA::next_node(int node, string word, vector <int> circuit)
{
    cout<<word<<endl;
    
    if (word.length() == 1){
        int temp = getIndex(adjancy_matrix[node], word[0]);
        if (getIndex(final_states, temp) != -1){
            cout<<"Succes";
            return 1;
            
        }
        else{
            cout<<"Imposibil";
            return 0;
        }
    }
    if(word.length() == 0 && *find(final_states.begin(), final_states.end(), node) == node)
    {

        for(int i = 0; i < circuit.size(); i++)
            cout<<circuit.at(i);
        return 0;
        
    }

    else if(word.length() == 0 && *find(final_states.begin(), final_states.end(), node) != node){
        cout<<"Cuvantul nu duce intr-o stare finala";
        return 0;}

    else if(getIndex(adjancy_matrix[node],word[word.length()-1]) == -1){
        cout<<"Cuvant neacceptat";
        return 0;
    }

    else{
        circuit.push_back(node);
        
        if (word.length()-1 > 0)
        {

            return next_node(getIndex(adjancy_matrix[node], word[word.length()-1]), word.substr(0,word.length()-1),circuit);
        }
        else return next_node(getIndex(adjancy_matrix[node], word[0]), word.substr(0,1),circuit);

        }
};



istream &operator >>(istream &in, DFA &source){
    
    int nr_noduri = 0;
    int stari_finale = 0;
    
    cout<<"Input pentru automat, citit ca si graf:"<<endl;
    cout<<"Atentie, inputul pentru graf se da in felul urmator: Initial introdu cate noduri sunt:"<<endl;
    cin>>nr_noduri;
    for(int i = 0; i < nr_noduri; i++){
        source.nodes.push_back(i);
    }
    
    vector <vector<char>> temp(nr_noduri, vector<char>(nr_noduri));
    
    cout<<"Acum introdu matricea de adiacenta: Pentru fiecare nod avem un tuplu (x,y) care ii indica pozitia in matrice, deci indicii, si un element apartinand alfabetului acceptat de automat - un caracter"<<endl;
    
    source.adjancy_matrix = temp;
    
    
    for(int i = 0; i < nr_noduri; i++){
        for(int j = 0; j < nr_noduri; j++){
            in>>source.adjancy_matrix[i][j];
        }
        
    }
    cout<<"Cate stari finale are automatul?";
    cin>>stari_finale;
    
    vector<int> aux(stari_finale, 0);
    
    source.final_states = aux;
    
    cout<<"Care sunt ele?";
    for(int i = 0; i < stari_finale; i++)
    {
        in>>source.final_states[i];
        
    }
    
    cout<<"Procesare automat...";
    usleep(2500000);
    
    return in;
    
}





