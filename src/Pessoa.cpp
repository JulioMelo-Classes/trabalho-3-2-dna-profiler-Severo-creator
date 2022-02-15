#include "../include/Pessoa.hpp"
#include <string.h>
#include <vector>

using namespace std;

int compare(string* str1, string* str2){
  string::iterator it1 = str1->begin(), it2 = str2->begin();
  int size, count = 0, porc;
  if(distance(str1->begin(), str1->end()) < distance(str2->begin(), str2->end()))size = distance(str1->begin(), str1->end()); else size = distance(str2->begin(), str2->end());

  for(int i = 0; i < size; i ++){
    if(*it1 == *it2){
      count ++;
    }
    it2 ++;
    it1 ++;
  }

  porc = (count / size) * 100;
 // cout << porc << "<<<<<<<<<<<<<<<" << endl;
  return porc;
}

pair<bool, int> bolling(string* str1, string str2, int i){
 // cout << "check 11" << endl;
  string::iterator it = str1->begin();
  string::iterator ind;
 // cout << *str1 << endl;


  //cout << "check 12" << endl;
  int soma = 0, salva = 1, count, base;
  //cout << str2 << endl;
  while(it != str1->end()){
   //cout << "check .1" << *it << endl;
    count = 0;
    if(*it == *str2.begin()){

      //cout << "check .2" << endl;
      ind = str2.begin();
      
      while(count != str2.length()){
        
        if(*it == *ind){
          //cout << *it << endl;
          it ++;
          ind++;
          count++;
        }else{
          it = it - count;
          break;
        }
      }
      if(count == str2.length()){
        soma ++;
        if(soma > salva){
          salva = soma;
          base = distance(str1->begin(), it) - (str2.length() * soma);
        } 
      }else{
        if(soma > salva) {
          salva = soma;
          base = distance(str1->begin(), it) - (str2.length() * soma);
        }
        soma = 0;
        it++;
      }
    }else{
      it ++;
    }
  }
  pair<bool, int> a;
  if(salva == i){
    
    a.first = true;
    a.second = base;
    //cout << base << endl;
    //cout << "true <<<<<<<<<<<<" <<endl;
    return a;
  }else{
    a.first = false;
    a.second = base;
    //cout << base << endl;
    //cout << "false <<<<<<<<<<<<" <<endl;
    return a;
  }
}

Pessoa::Pessoa(std::string str, std::vector<std::string> atributos){
  char* entrada, *saida;
  entrada = &str[0];

  saida = strtok(entrada,",");

  string name(saida);
  this->nome = name;
  name = "../data/sequence_" + name + ".txt";
  ifstream dna(name);
  dna >> cadeia;
  dna.close();
  //cout << cadeia << endl;

  //cout << "check  8" << endl;
  int k = 0;
  while (saida != NULL)
  {
  //cout << "check  ." << endl;
  //printf("%s\n",saida);
  saida = strtok (NULL, ",");
  if(saida != NULL){
    string sai(saida);
    pair<std::string, int> pair;
    pair.first = atributos[k];
    pair.second = stoi(sai);
    dados_pessoais.push_back(pair);
    k++;
    }
  }
}

void Pessoa::Printa_dados(){
  cout << nome << endl;
  for(auto i : dados_pessoais){
    cout << i.first << " : " << i.second << endl;
  }
  return;
}

std::pair<bool, std::vector<int>> Pessoa::Parear(string* str){
  int count =0;
  vector<int> vec;
  pair<bool, int> s;
  for(auto i : dados_pessoais){
    s = bolling(str, i.first, i.second);
    if(s.first == true)
      vec.push_back(s.second);
      count ++;
  }
  
  int a = compare(str, &cadeia);
  vec.push_back(a);
  pair<bool, vector<int>> par;
  par.second = vec;
  if(a >= 30 && count == dados_pessoais.size()){
    //cout << "Match ID (" << a << ") : " << nome << endl;
    par.first = true;
    return par;
  }

 // cout << "Sorry, no match in our database" << endl;
  par.first = false;
  return par;
  
}

string Pessoa::Retorna_nome(){
  return nome;
}

std::vector<std::pair<std::string, int>> Pessoa::Retorna_dados_pessoais(){
  return dados_pessoais;
}