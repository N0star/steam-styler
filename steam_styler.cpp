#include <cstdio>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
//steam_styler.cpp -o ss.exe -lstdc++

int main(){
  ofstream newf;
  string bft,path;
  int i,flag; flag=0;
  //path="D:\\Program Files (x86)\\Steam\\steamui\\css\\";

  ifstream pf("path.txt");
  getline( pf, path);
  pf.close();
  printf(path.c_str());

  bool fwn;
  fwn=true;

  newf.open (path+"new_style");
  ifstream rfile(path+"libraryroot.css");
  while (getline (rfile, bft)) {
    switch(flag){
      case 0: newf << bft+"\n"; break;
      case 1: newf << "  display: none; }\n"; break;
      default: newf << bft+"\n";
    } flag=0;

    if(bft==".libraryhome_WhatsNewContainer_gdZT7 {") {if(fwn==true) {flag=1;}}
  }

  newf.close();
  rfile.close();
  rename((path+"libraryroot.css").c_str(),(path+"old_libraryroot.css").c_str());
  rename((path+"new_style").c_str(),(path+"libraryroot.css").c_str());

  return 0;
};
