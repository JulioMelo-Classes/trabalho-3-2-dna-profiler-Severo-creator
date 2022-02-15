#include "../include/Scan.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

#define ESC "\033["
#define BLUE_TXT "36"
#define RED_TXT "31"
#define GREEN_TXT "32"
#define RESET "\033[m"





using namespace std;

Scan::Scan(){

}


void Scan::Executar(string* str1, string* str2, Dados* dados){

  cout << "==============================" << endl << "Welcome to the Basic DNA profiler, v0.1" << endl << "Copyright (C) 2021, Sela R. dos santos" << endl << "==============================" << endl;

  cout << endl << ESC << ";" << BLUE_TXT << "m" << "This program loads a DNA database and an unknown" << endl << "DNA sequence and tries to find a match between" << endl << "the input DNA sequence and the DNA database" << RESET << endl;

  cout << endl << "[+]  preparing to read the DNA database file [" << ESC << ";" << RED_TXT << "m" << *str1 << RESET << "]" << endl;
  
  bool check1 = dados->Salva_dados(*str1);
  cout <<"[+]  preparing to read the unknown DNA sequence file [" << ESC << ";" << RED_TXT << "m" << *str2 << RESET << "]" << endl;
  
  cout << "[+]  prossecing data, please wait..." << endl;

  if(check1){
    cout << endl << "[+]  input files successfully read." << endl;
    cout << "[+]  searching the data base for match... pealse wait." << endl;
  }else{
    return;
  }
  bases = dados->Scaning(str2);
  cout << endl;
  std::vector<std::pair<std::string, int>> semi_str = dados->Retorna_dados_pessoais_suspeito();
  std::vector<std::pair<std::string, int>>::iterator it = semi_str.begin();
  string cadeia;
  ifstream doc(*str2);
  doc >> cadeia;
  int count = 0 ,count1 = 0;
  string::iterator ind = cadeia.begin();

  



  if( bases.first = true){
    while(ind != cadeia.end()){
      count1 = 0;
      for(int a = 0; a < semi_str.size(); a ++){
        if(count == bases.second[a]){
          count1 = 1;
          for(int s = 0; s < semi_str[a].first.length() * semi_str[a].second ; s++){
            cout << ESC << ";" << GREEN_TXT << "m" << *ind << RESET;
            count ++;
            ind++;
            continue;
          }
        }
      }
      if(count1 == 0){
        cout << *ind;
        count ++;
        ind++;
      }
    }
  }
cout << endl;

}
