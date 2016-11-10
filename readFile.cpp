#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <math.h>

using namespace std;

int main(){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  ifstream dataSet("data2.txt");
  if (dataSet.is_open()){
     string firstLine;
     string secondLine;

     getline(dataSet, firstLine);
     int row = atoi(firstLine.c_str());
     getline(dataSet, secondLine);
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
     vector< vector<double> > disMatrix(row, vector<double>(row));
      
     double sum = 0;
     double dis = 0;

     for(int i=0;i<row;i++){
          for(int j=i;j<row;j++){
	     for(int k=0;k<column;k++){
	        sum = sum + (dataMatrix[i][k] - dataMatrix[j][k]) * (dataMatrix[i][k] - dataMatrix[j][k]);
	      }
	    dis = sqrt(sum);
	    sum = 0;
	    disMatrix[i][j] = disMatrix[j][i] = dis;
           }
      
       }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////     
     vector<int> countVec;
     for(int i=0;i<row;i++){
       countVec.push_back(i);
      }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
     int curClusterNum = row;
     int m;
     int n;
////////////////////////////////////////////////////////////////////////////////////////////////////
     while(curClusterNum > clusterNum ){
        int countClusterNum = 0;
	vector<int> countVector(row);
	double min = 1.79e+308;
	
	for(int i=0;i<row;i++){
          for(int j=i+1;j<row;j++){
            if(disMatrix[i][j]!= 0 && disMatrix[i][j] < min){
	       min = disMatrix[i][j];
	       m = i;
	       n = j;
	     }
           }
          }
	
	if(disMatrix[m][n] !=0){
	  disMatrix[m][n] = disMatrix[n][m] =0;  
	  }
	else{curClusterNum = curClusterNum;}
	 
	 for(int k=0;k<row;k++){
	   if((disMatrix[k][m] >= disMatrix[k][n])&&(disMatrix[k][n] != 0)){
               disMatrix[k][n] =disMatrix[n][k]= disMatrix[k][m];
	       }
	       //disMatrix[n][k] = disMatrix[k][m];}
	   else if((disMatrix[k][m] < disMatrix[k][n])&&(disMatrix[k][m] != 0)){
	       disMatrix[k][m] = disMatrix[k][n];
	       disMatrix[m][k] = disMatrix[k][n];}
	   else if((disMatrix[k][m] == 0) ||( disMatrix[k][n] == 0)){
	       disMatrix[k][n] = disMatrix[k][m] = disMatrix[m][k] = disMatrix[n][k]=0;
	       //disMatrix[k][m] = 0;
	       //disMatrix[m][k] = 0;
	       //disMatrix[n][k] = 0;
	    }
	  }
    
        for(int i=0;i<row;i++){
	  for(int j=0;j<row;j++){
	   if(disMatrix[i][j] == 0){
	     countVec[j] = countVec[i];
	    }
	   }
	 }
	
	for(int i =0;i<row;i++){
	  countVector[countVec[i]]++;
	 }
	
	for(int i=0;i<row;i++){
	 if(countVector[i] != 0){
	    countClusterNum++;}
	 }

	curClusterNum = countClusterNum;
     }
/////////////////////////////////////////////////////////////////////////////////////////////    

   for(int i=0;i<row;i++){
     cout << countVec[i] << ",";
    }

   cout << endl;

   //for (int i=0;i<row;i++){
     //for(int j=0;j<row;j++){
       //cout << disMatrix[i][j] << ",";
      //}
     //cout << endl;
    //}

  }else{
     cout << "Sorry, it is a wrong file" << endl;
    }

  return 0;
}
