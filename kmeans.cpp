#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
////////////////////////////////////////////////////////////////////////////////////////////  
   ifstream dataSet("data2.txt");
   if (dataSet.is_open()){
     string firstLine;
     string secondLine;

     getline(dataSet,firstLine);
     int row = atoi(firstLine.c_str());
     getline(dataSet,secondLine);
     int clusterNum = atoi(secondLine.c_str());

     vector< vector<double> > dataMatrix;
     int column;

     vector<double> vec;
     string line;
     while(getline(dataSet,line)){
          char *token = strtok( const_cast<char*>(line.c_str()),"( , )");
          while (token != NULL){
	     vec.push_back(atoi(token));
	     token = strtok(NULL, "( , )");
            }
	  column = vec.size();
	  dataMatrix.push_back(vec);
	  vec.erase(vec.begin(),vec.end());
      }
///////////////////////////////////////////////////////////////////////////////////////////
    vector<int> centerVec;
    vector <vector<double>> centerMatrix;

    for(int i=0;i<clusterNum;i++){
      int randomNum;
      randomNum = rand()%row;
      for(int j=0;j<column;j++)
       centerVec.push_back(dataMatrix[randomNum][j]);
      centerMatrix.push_back(centerVec);
      centerVec.erase(centerVec.begin(),centerVec.end());         
     }
    
    double disToCenter;
    double sum =0;

    for(int i=0;i<row;i++){
      for(int j=0;j<clusterNum;j++){
        for(int k=0;k<column;k++){
	    sum = sum + (dataMatrix[i][k] - dataMatrix[j][k]) *(dataMatrix[i][k]- dataMatrix[j][k]);
         }
	
       
    

   }else{
     
     cout << "Sorry, it is a wrong file." << endl;

}

}
