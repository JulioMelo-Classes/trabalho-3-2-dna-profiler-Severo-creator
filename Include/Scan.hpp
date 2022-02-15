#ifndef SCAN_H
#define SCAN_H
#include <iostream>
#include <vector>
#include <list>
#include <string>

#include "Dados.hpp"

class Scan
{
private:
  std::pair<bool, std::vector<int>> bases;
public:
  Scan(/* args */);
  void Executar(std::string* str1, std::string* str2, Dados* dado);
};



#endif