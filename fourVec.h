/*
Darius Rushaj

Four Vector Header file
*/

#include<cmath>

class fourVec
{
	private:
		//Note: Will be using +--- metric.
		int dim = 4;
		double* array;// = new double[4];
		
	public:
	
		//Constructors:
		fourVec(); 									//Default constructor
		fourVec(const fourVec&); 		//Copy constructor.
		fourVec(double ptx0, double ptx1, double ptx2, double ptx3);
		fourVec(double ptx0, double ar[3]);
		
		//Destructor:
		~fourVec();
		
		//Operators:
		void operator= (const fourVec&);
		fourVec operator+ (const fourVec&);
		void operator+= (const fourVec&);
		fourVec operator- (const fourVec&);
		void operator-= (const fourVec&);
		fourVec operator* (const double& scalar);
		void operator*= (const double& scalar);
		fourVec operator/ (const double& scalar);
		void operator/= (const double& scalar);
		
		//Setters:
		void Set(int index, double value);
		
		//Getters:
		double Get(int index) const;
		
		//Member Functions:
		void print();
		double Dot(const fourVec& v); //Using +--- metric.
		fourVec BoostX(double beta); //Boost along x axis: Not yet implemented.
};

fourVec operator* (const double& scalar, fourVec& V);
