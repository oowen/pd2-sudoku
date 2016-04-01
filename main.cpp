#include<iostream>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku ss;
	ss.giveQuestion();
//	ss.readIn();
	ss.printOut();
	ss.solve();
//	ss.transform();
//	ss.printOut();
//	cout<<endl;
	return 0;
}

	
