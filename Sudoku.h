using namespace std;
class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int,int);
		void changeRow(int,int);
		void changeCol(int,int);
		void rotate(int);
		void flip(int);
		void transform();
		void change();
		void printOut();
		void exchange();
		void exchange1();
		void init();
		void tryans();
		void exam();
		int check(int);
		int checkk(int);
		int check1(int,int,int*);
		int check2(int,int,int*);
		int pointpull(int);
		int pointpush(int);
		int aftersite();
		int beforesite();
		int getzero(int);
		int getzero1(int);
	private:
		int i,j;

};
