#include<iostream>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku ss;

	ss.giveQuestion();
	ss.solve();
	ss.printOut();

//	ss.transform();
//	ss.printOut();
//	cout<<endl;
	return 0;
}

	
