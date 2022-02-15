#ifndef DADOS_H
#define DADOS_H


#include <iostream>
#include <vector>
#include <string>
#include "Pessoa.hpp"

class Dados
{
private:
  std::vector<Pessoa*> pessoas;
  std::vector<std::string> atributos;
  std::vector<std::pair<std::string, int>> dados_pessoais_suspeito;
public:
  Dados(/* args */);
  bool Salva_dados(std::string str);
  std::pair<bool, std::vector<int>> Scaning(std::string* str);
  std::vector<std::string> Retorna_atributos();
  std::vector<std::pair<std::string, int>> Retorna_dados_pessoais_suspeito();
};


#endif