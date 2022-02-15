#include "../include/Dados.hpp"

#include <fstream>
#include <string.h>

using namespace std;

Dados::Dados(){
  
}

bool Dados::Salva_dados(string str){
  fstream dados(str);
   //cout << "check  2" << endl;
  if(dados.bad()){
    cout << "erro" << endl;
    return false;
  }
  //cout << "check  3" << endl;
  char* entrada, *saida;
  string a;
  //cout << "check  4" << endl;
  dados >> a;
  entrada = &a[0];
  //cout << "check  5" << endl;

  saida = strtok(entrada,",");

  

  while (saida != NULL)
  {
    //cout << "check  ." << endl;
    //printf("%s\n",saida);
    saida = strtok (NULL, ",");
    if(saida != NULL){
      string atr(saida);
      atributos.push_back(atr);
      //cout << atr << endl;
    }
  }
  //cout << "check  7" << endl;
  
  /*for(auto i : atributos){
    cout << i << endl;
  }*/
  //cout << atributos.size() << endl;
  while(dados >> a){
    Pessoa *o = new Pessoa(a, atributos);
    this->pessoas.push_back(o);
  }

 /* for(auto i : pessoas){
    i->Retorna_dados();
  }*/


  dados.close();
 return true;
}

std::pair<bool, std::vector<int>> Dados::Scaning(string* str){
  ifstream conteudo(*str);
  string dna, name;
  conteudo >> dna;
  int porc = 0;
  vector<int>::iterator it;
  pair<bool, std::vector<int>> a, ind;
  //cout << "check 9" << endl;
  bool check = false;
  if(conteudo.bad()){
    a.first = false;
    a.second = {-1};
    return a;
  }



  for(auto i : pessoas){
    //cout << "check ." << endl;
    a = i->Parear(&dna);
    
    it = a.second.end() - 1;
    //cout << *it << endl;
    if(*it > porc) {
      name = i->Retorna_nome();
      dados_pessoais_suspeito = i->Retorna_dados_pessoais();
      check = true;
      porc = *it;
      //cout << porc << " maior <<<<<<<<<<<" << endl;
      ind = a;
    }
  }
  if(check == true){
    cout << endl << "Match ID (" << porc << ") : " << name << endl;
    return ind;
  }else{
    cout << endl <<"Sorry, no match in our database" << endl;
    return a;
  }
}

std::vector<std::string> Dados::Retorna_atributos(){
  return atributos;
}

std::vector<std::pair<std::string, int>> Dados::Retorna_dados_pessoais_suspeito(){
  return dados_pessoais_suspeito;
}