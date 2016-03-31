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
		int check(int);
		int check1(int,int,int*);
		int pointpush(int);
		int beforesite();
		int getzero(int);
	private:
		int i,j;

};
