#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;
	int map[9][9];
	int tempnum[81];                              //last input 
	int tempnum1[81];
	int tempx=0;	//last input location
	int tempy=80;
	int startrow[81];
	int startcol[81];
	int startblock[81];
	int addrow[9];
	int addcol[9];
	int addblock[9];
	int ss[81];
	int ss0[81];
	int ss1[81];
	int ss2[81];
	int ss3[81];
	int ss4[81];
	int ss5[81];
	int N=0;
	void Sudoku::solve(){
		exchange();
		for(i=0;i<81;i++){
			ss1[i]=ss[i];
			ss0[i]=ss[i];
			ss4[80-i]=ss[i];}
//		for(i=0;i<81;i++)
//			cout<<ss[i];
//			cout<<endl;
//		for(i=0;i<81;i++)	
//			cout<<ss4[i];
//			cout<<endl;
			exam();
		init();
		tryans();
		for(i=0;i<81;i++)
			ss[i]=ss2[i];
		exchange1();
		printOut();
	}

	void Sudoku::exam(){
		for(int k=0;k<9;k++){
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					if((ss[9*k+i]==ss[9*k+j]&&ss[9*k+i]!=0)&&(9*k+i)!=(9*k+j)){
						cout<<"0"<<endl;
						exit(1);}
					if((ss[k+9*i]==ss[k+9*j]&&ss[k+9*i]!=0)&&(k+9*i)!=(k+9*j)){
						cout<<"0"<<endl;
						exit(1);}
					if(ss[27*(k/3)+3*(k%3)+9*(i/3)+(i%3)]==ss[27*(k/3)+3*(k%3)+9*(j/3)+(j%3)]&&ss[27*(k/3)+3*(k%3)+9*(i/3)+(i%3)]!=0){
						if((27*(k/3)+3*(k%3)+9*(i/3)+(i%3))!=(27*(k/3)+3*(k%3)+9*(j/3)+(j%3))){
						cout<<"0"<<endl;
						exit(1);}
						}
					}
				}
			}
		}
		

	void Sudoku::init(){
		for(i=0;i<81;i++){
			startrow[i]=i/9*9;
			startcol[i]=i%9;
			startblock[i]=((i/9)/3)*27+((i%9)/3)*3;}
		for(i=0;i<9;i++){
			addrow[i]=i;
			addcol[i]=i*9;
			addblock[i]=(i/3)*9+(i%3);}
	}
	void Sudoku::tryans(){
		int x=getzero(-1);
		do{
			ss[x]++;
			if(ss[x]>9){
				ss[x]=0;
				x=beforesite();}
			else{
				if(check(x)==0){
					pointpush(x);
					x=getzero(x);
					if(x==81){
						for(i=0;i<81;i++)
							ss2[i]=ss[i];
					}
				}
			}
		}while(x>=0&&x<81);

		int y=getzero1(-1);
		do{
			ss4[y]++;
			if(ss4[y]>9){
				ss4[y]=0;
				y=beforesite();}
			else{
				if(checkk(y)==0){
					pointpush(y);
					y=getzero1(y);
					if(y==81){
						for(i=0;i<81;i++)
							ss3[i]=ss4[80-i];
					}
				}
			}
		}while(y>=0&&y<81);
		for(i=0;i<81;i++){
			if(ss2[i]==ss3[i])
				N++;}
//				for(i=0;i<81;i++)
//					cout<<ss2[i];
//					cout<<endl;
//				for(i=0;i<81;i++)
//					cout<<ss4[i];
//					cout<<endl;	
//				for(i=0;i<81;i++)
//					cout<<ss3[i];
//					cout<<endl;
		if(N!=81){
			cout<<"2"<<endl;
			exit(1);}
		else if(N==81)
			cout<<"1"<<endl;
	}	

	int Sudoku::check(int x){	//check row col block
		int y=0;
		if(!y) y=check1(x,startrow[x],addrow);
		if(!y) y=check1(x,startcol[x],addcol);
		if(!y) y=check1(x,startblock[x],addblock);	
		return y;
	}
	int Sudoku::checkk(int x){
		int y=0;
		if(!y) y=check2(x,startrow[x],addrow);
		if(!y) y=check2(x,startcol[x],addcol);
		if(!y) y=check2(x,startblock[x],addblock);
		return y;
	}
		
	int Sudoku::check2(int x,int start,int *addnum){
		int y=0,z;
		for(i=0;i<9;i++){
			z=start+addnum[i];
			if(x!=z&&ss4[x]==ss4[z])
				y++;
		}
		return y;
	}
	int Sudoku::check1(int x,int start,int *addnum){
		int y=0,z;
		for(i=0;i<9;i++){
			z=start+addnum[i];
			if(x!=z&&ss[x]==ss[z])
				y++;
		}
		return y;
	}
	int Sudoku::getzero1(int x){
		do{
			x++;
		}while(x<81&&ss4[x]>0);	
		return x;
	}
	int Sudoku::getzero(int x){
		do{
			x++;
			}while(x<81&&ss[x]>0);
		return x;
	}
	int Sudoku::aftersite(){
		if(tempy>=80)
			return(81);
		else return(tempnum1[++tempy]);
		}
	int Sudoku::beforesite(){
		if(tempx<=0)
			return(-1);
		else return(tempnum[--tempx]);
	}
	int Sudoku::pointpush(int x){
		tempnum[tempx++]=x;
	}
	int Sudoku::pointpull(int x){
		tempnum1[tempy--]=x;
	}
//////////////////////////////////////////////////////////////////////////////////
	void Sudoku::giveQuestion(){
		int mmm[9][9]={{5,3,0,0,7,0,0,0,0},
			  	   {6,0,0,1,9,5,0,0,0},
			   	   {0,9,8,0,0,0,0,6,0},
				   {8,0,0,0,6,0,0,0,3},
				   {4,0,0,8,0,3,0,0,1},
				   {7,0,0,0,2,0,0,0,6},
				   {0,6,0,0,0,0,2,8,0},
				   {0,0,0,4,1,9,0,0,5},
				   {0,0,0,0,8,0,0,7,9}};
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				map[i][j]=mmm[i][j];
		}
	}
	void Sudoku::readIn(){
			
			for(i=0;i<9;i++){
				for(j=0;j<9;j++)
					cin>>map[i][j];}
//			for(i=0;i<9;i++){
//				for(j=0;j<9;j++)
//					cout<<map[i][j];}			
//					cout<<endl;
//			}
		}
	void Sudoku::changeNum(int a,int b){
		if( a < 1 || a > 9){
			cout<<"input error"<<endl;
			exit(1);}
		else if ( b < 1 || b > 9){
			cout<<"input error"<<endl;
			exit(1);}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(map[i][j]==a)
					map[i][j]=b;
				else if(map[i][j]==b)
					map[i][j]=a;
			}
		}
	}
	void Sudoku::changeRow(int a, int b){
		if(a<0||a>2){
			cout<<"input error"<<endl;
			exit(1);}
		else if(b<0||b>2){
			cout<<"input error"<<endl;
			exit(1);}
		
		if((a==0&&b==1)||(a==1&&b==0)){
				for(j=0;j<9;j++){
					int x=map[0][j];
					int y=map[1][j];
					int z=map[2][j];
					map[0][j]=map[3][j];
					map[1][j]=map[4][j];
					map[2][j]=map[5][j];
					map[3][j]=x;
					map[4][j]=y;
					map[5][j]=z;}
		}
				
		else if((a==0&&b==2)||(a==2&&b==0)){
				for(j=0;j<9;j++){
					int x=map[0][j];
					int y=map[1][j];
					int z=map[2][j];
					map[0][j]=map[6][j];
					map[1][j]=map[7][j];
					map[2][j]=map[8][j];
					map[6][j]=x;
					map[7][j]=y;
					map[8][j]=z;}
		}
		else if((a==1&&b==2)||(a==2&&b==1)){
				for(j=0;j<9;j++){
					int x=map[3][j];
					int y=map[4][j];
					int z=map[5][j];
					map[3][j]=map[6][j];
					map[4][j]=map[7][j];
					map[5][j]=map[8][j];
					map[6][j]=x;
					map[7][j]=y;
					map[8][j]=z;}
		}
	}

	void Sudoku::changeCol(int a,int b){
		if(a<0||a>2){
			cout<<"input error"<<endl;
			exit(1);}
		else if(b>2||b<0){
			cout<<"input error"<<endl;
			exit(1);}

		if((a==0&&b==1)||(a==1&&b==0)){
			for(i=0;i<9;i++){
				int x=map[i][0];
				int y=map[i][1];
				int z=map[i][2];
				map[i][0]=map[i][3];
				map[i][1]=map[i][4];
				map[i][2]=map[i][5];
				map[i][3]=x;
				map[i][4]=y;
				map[i][5]=z;}

		}
		if((a==0&&b==2)||(a==2&&b==0)){
			for(i=0;i<9;i++){
				int x=map[i][0];
				int y=map[i][1];
				int z=map[i][2];
				map[i][0]=map[i][6];
				map[i][1]=map[i][7];
				map[i][2]=map[i][8];
				map[i][6]=x;
				map[i][7]=y;
				map[i][8]=z;}
		}
		if((a==1&&b==2)||(a==2&&b==1)){
			for(i=0;i<9;i++){
				int x=map[i][3];
				int y=map[i][4];
				int z=map[i][5];
				map[i][3]=map[i][6];
				map[i][4]=map[i][7];
				map[i][5]=map[i][8];
				map[i][6]=x;
				map[i][7]=y;
				map[i][8]=z;}
		}
	}
	
	void Sudoku::rotate(int n){
		int out[9][9];
		if(n<0||n>100){
			cout<<"input error"<<endl;
			exit(1);}
		if(n==0){
			for(i=0;i<9;i++){
				for(j=0;j<9;j++)
					map[i][j]=map[i][j];}
		}
		else 
			for(int k=0;k<n;k++){
				for(i=0;i<9;i++){
					for(j=0;j<9;j++)
						out[j][8-i]=map[i][j];}
					
				for(i=0;i<9;i++){
					for(j=0;j<9;j++)
						map[i][j]=out[i][j];}
					}
		}

	void Sudoku::flip(int n){
		int out[9][9]={0};
		if(n!=1&&n!=0){
			cout<<"input error"<<endl;
			exit(1);}
		if(n==0){
			for(i=0;i<9;i++){
				for(j=0;j<9;j++)
					out[8-i][j]=map[i][j];
				}
		}
		else{
			for(i=0;i<9;i++){
				for(j=0;j<9;j++)
					out[i][8-j]=map[i][j];
			}
		}
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				map[i][j]=out[i][j];
		}
	}
	void Sudoku::transform(){
		readIn();
		change();
	}

	void Sudoku::change(){
		srand(time(NULL));
		changeNum(rand()%9+1,rand()%9+1);
		changeRow(rand()%3,rand()%3);
		changeCol(rand()%3,rand()%3);
		rotate(rand()%101);
		flip(rand()%2);
	}
	void Sudoku::printOut(){
		int i;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				printf("%d%c",map[i][j],j==8?'\n':' ');
		}
	}

	void Sudoku::exchange(){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				ss[i*9+j]=map[i][j];
		}
	}
	void Sudoku::exchange1(){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				map[i][j]=ss[i*9+j];
		}
	}


				
				





		









