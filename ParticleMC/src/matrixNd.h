#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class matrixNd {
  private:

  int nC;
  int nL;
  double **m;

  public:

  // constructor
  matrixNd(int m_nL, int m_nC);

  // destructor
  virtual~matrixNd();

  //operators
  matrixNd operator = (matrixNd &);
  matrixNd operator = (matrixNd *);

  // Setter functions  
  virtual void SetValue(int m_posL, int m_posC, double mx){
    nC=(int) GetColumn();
    nL=(int) GetLine();
    if ((m_posL>nL) or (m_posC>nC)) {
      cout << "The matrix dimension is " << nC <<"x"<< nL << endl;
    }else{
      m[m_posL][m_posC]=mx;
    } 
  }

  // Getter functions
  virtual double GetValue(int m_posL, int m_posC) {
    nC=(int) GetColumn();
    nL=(int) GetLine();
    if ((m_posL>nL) or (m_posC>nC)) {
      cout << "The matrix dimension is " << nC <<"x"<< nL << endl;
    }else{
      return m[m_posL][m_posC];
    } 
    return 0;
  }
  
  double GetColumn() {
    return nC;
  }
  
  double GetLine() {
    return nL;
  }

  // Others
  matrixNd(matrixNd &d);
  void Print();
};
