#ifndef dfa.hpp
#define dfa.hpp

#include <iostream>
#include <string>
#include <vector>


class DFA{


private:
    
std::vector <int> nodes;
std::vector <std::vector<char>> adjancy_matrix;
std::vector <int> final_states;


public:


//default constructor
DFA(){

    this-> nodes = {};
    this-> adjancy_matrix = {};
    this-> final_states = {};
};

//constructor

DFA(std::vector <int> nodes, std::vector <std::vector<char>> adjancy_matrix, std::vector <int> final_states){

    this-> nodes = nodes;
    this-> adjancy_matrix = adjancy_matrix;
    this-> final_states = final_states;

}

//destructor

~DFA();

    int next_node(int node, std::string word, std::vector <int> circuit);

    friend std::istream &operator >>(std::istream &in, DFA &source);

    friend std::ostream &operator <<(std::ofstream &out, const DFA &source);
    
    
    auto get_nodes(){return this->nodes;};
    auto get_adjancy_matrix(){return this->adjancy_matrix;};
    auto get_final_states(){return this-> final_states;}
    

};



#endif



