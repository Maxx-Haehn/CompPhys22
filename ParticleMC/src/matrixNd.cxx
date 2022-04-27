#include "matrixNd.h"

matrixNd::matrixNd(int m_nL, int m_nC){
  nL=m_nL;
  nC=m_nC;
  m=new double*[nL];
  for (int k=0; k<nL; k++){
    m[k]=new double [nC];
  }
  for(int i=0; i<nL; i++){
    for(int j=0; j<nC; j++){
      m[i][j]=-99;
    }
  }
}

matrixNd::~matrixNd(){
  for (int k=0; k<nL; k++) delete [] m[k];
  delete []m;
}; 


matrixNd matrixNd::operator=(matrixNd &d){
  nL=(int) d.GetLine();
  nC=(int) d.GetColumn();
  m=new double*[nL];
  for (int k=0; k<nL; k++){
    m[k]=new double [nC];
  }
  for (int i=0;i< nL; i++){
    for (int j=0;j< nC; j++){
      m[i][j]=d.GetValue(i,j);
    }
  }
  return *this;
}

matrixNd matrixNd::operator = (matrixNd *d){
  nL=(int) d->GetLine();
  nC=(int) d->GetColumn();
  m=new double*[nL];
  for (int k=0; k<nL; k++){
    m[k]=new double [nC];
  }
  for (int i=0;i< nL; i++){
    for (int j=0;j< nC; j++){
      m[i][j]=d->GetValue(i,j);
    }
  }
  return *this;
}

matrixNd::matrixNd(matrixNd& d){
  nL=(int) d.GetLine();
  nC=(int) d.GetColumn();
  m=new double*[nL];
  for (int k=0; k<nL; k++){
    m[k]=new double [nC];
  }
  for (int i=0;i< nL; i++){
    for (int j=0;j< nC; j++){
      m[i][j]=d.GetValue(i,j);
    }
  }
}

void matrixNd::Print(){  
  nL=(int) GetLine();
  nC=(int) GetColumn();
  for(int i=0; i<nL; i++){ 
    for(int j=0; j<nC; j++){
      cout << GetValue(i,j) << "  ";
    }
    cout << endl;
  }
  cout << endl;
}

