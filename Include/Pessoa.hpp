#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <vector>
#include<list>
#include <fstream>

class Pessoa
{
private:
  std::string nome;
  std::vector<std::pair<std::string, int>> dados_pessoais;
  std::string cadeia;
public:
  Pessoa(std::string str, std::vector<std::string> atributos);
  void Printa_dados();
  std::pair<bool, std::vector<int>> Parear(std::string* str);
  std::string Retorna_nome();
  std::vector<std::pair<std::string, int>> Retorna_dados_pessoais();
};


#endif