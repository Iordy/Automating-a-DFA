#include <iostream>
#include "dfa.hpp"
#include <vector>


using namespace std;

int main(){


DFA *automata = new DFA();


    cin>>*automata;
    
    string word;
    vector <int> circuit;
    
    for(int i = 0; i < automata->get_nodes().size(); i++){
        cout<<automata->get_nodes()[i];
    }
    cout<<endl;
    for(int i = 0; i < automata->get_final_states().size(); i++){
        cout<<automata->get_final_states()[i];
    }
    
    cout<<endl;
    for(int i = 0; i < automata->get_nodes().size(); i++){
        for(int j = 0; j < automata->get_nodes().size(); j++){
            cout<<automata->get_adjancy_matrix()[i][j];
        }
        cout<<endl;}
    
    cout<<"Introdu cuvantul pe care vrei sa il testezi:"<<endl;
    cin>>word;
    reverse(word.begin(), word.end());
    automata->next_node(0, word, circuit);
    
    


    return 0;
}
