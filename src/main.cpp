#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>

#include "../include/Dados.hpp"
#include "../include/Scan.hpp"

using namespace std;


int main(int argc, char *argv[]) {

  /*for(int i = 0; i < argc ;i ++){
    cout << argv[i] << endl;
  }*/

string pasta(argv[2]);
string DNA(argv[4]);

cout << "check  1" << endl;

Dados *dados = new Dados();
Scan *scan = new Scan();

scan->Executar(&pasta, &DNA, dados);

return 0;
}