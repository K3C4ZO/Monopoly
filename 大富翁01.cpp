#include <bits/stdc++.h>

using namespace std;

struct Land{
	int player;
	int owner;
	int house;
	int value;
};

void board(Land*land){
	cout<<"地0: "<<land[0].player<<" ,"<<land[0].owner<<" ,"<<land[0].house<<" "
	<<"地1: "<<land[1].player<<" ,"<<land[1].owner<<" ,"<<land[1].house<<" "
	<<"地2: "<<land[2].player<<" ,"<<land[2].owner<<" ,"<<land[2].house<<" "
	<<"地3: "<<land[3].player<<" ,"<<land[3].owner<<" ,"<<land[3].house<<" "
	<<"地4: "<<land[4].player<<" ,"<<land[4].owner<<" ,"<<land[4].house<<" "
	<<"地5: "<<land[5].player<<" ,"<<land[5].owner<<" ,"<<land[5].house<<" "
	<<"地6: "<<land[6].player<<" ,"<<land[6].owner<<" ,"<<land[6].house<<" "
	<<"地7: "<<land[7].player<<" ,"<<land[7].owner<<" ,"<<land[7].house<<" "
	<<"地8: "<<land[8].player<<" ,"<<land[8].owner<<" ,"<<land[8].house<<" "
	<<"地9: "<<land[9].player<<" ,"<<land[9].owner<<" ,"<<land[9].house<<" "<<endl;
}


int main()
{
	Land land[10];
	for(int i=0;i<10;i++){
	    land[i].player=0;
	    land[i].owner=0;
	    land[i].house=0;
	    land[i].value=0;
	}
	int dice1,dice2,play;
	int p1=0,p2=0,moneyOne=200,moneyTwo=200;
	while(true){
		if(moneyTwo<=0 || moneyOne>=2000){
			cout<<"1號玩家勝利"<<endl;
			break; 
		}
		else if(moneyOne<=0 || moneyTwo>=2000){
			cout<<"2號玩家勝利"<<endl;
			break; 
		}
		
		dice1=0,play=0;
		cout<<"1號玩家的回合: ";
		cin>>play;
		if(play==0){
			break;
		}
		else{
			cout<<"1號玩家的錢: "<<moneyOne<<endl; 
			dice1=1+rand()%3;
			cout<<"你骰的點數為: "<<dice1<<endl; 
			p1+=dice1;
			if(p1>9){
				p1-=9;
				moneyOne+=100;
			}
			for(int i=0;i<10;i++){
				if(p1==i){
					if(land[i].player==2){
						land[i].player=21;
					}
					else{
						land[i].player=1;
					}
				}
			}
			board(land);
			if(land[p1].owner==0){
				int buy;
				cout<<"是否買地: ";
				cin>>buy;
				if(buy==1){
					land[p1].owner=1;
					land[p1].value=20;
					moneyOne-=50;
					board(land);
				}	
			}
			else if(land[p1].owner==1){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					land[p1].house=1;
					land[p1].value=60;
					moneyOne-=50;
					board(land);
				}
			}
			else if(land[p1].house==1){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					land[p1].house=2;
					land[p1].value=120;
					moneyOne-=50;
					board(land);
				}
			}
			if(land[p1].owner==2){
				moneyOne-=land[p1].value;
				moneyTwo+=land[p1].value;
				
			}
			cout<<"1號玩家的錢: "<<moneyOne<<endl; 
			cout<<"2號玩家的錢: "<<moneyTwo<<endl; 
	
		}
		cout<<endl;
		///////////////
		dice2=0,play=0;
		cout<<"2號玩家的回合: ";
		cin>>play;
		if(play==0){
			break;
		}
		else{
			cout<<"2號玩家的錢: "<<moneyTwo<<endl; 
			dice2=1+rand()%3;
			cout<<"你骰的點數為: "<<dice2<<endl; 
			p2+=dice2;
			if(p2>9){
				p2-=9;
				moneyTwo+=100;
			}
			for(int i=0;i<10;i++){
				if(p2==i){
					if(land[i].player==1){
						land[i].player=12;
					}
					else{
						land[i].player=2;
					}
				}
			}
			board(land);
			if(land[p2].owner==0){
				int buy;
				cout<<"是否買地: ";
				cin>>buy;
				if(buy==1){
					land[p2].owner=2;
					land[p2].value=20;
					moneyTwo-=50;
					board(land);
				}
			}
			else if(land[p2].owner==2){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					land[p2].house=1;
					land[p2].value=60;
					moneyTwo-=50;
					board(land);
				}
			}
			else if(land[p2].house==1){
				int buy;
				cout<<"是否買房: ";
				cin>>buy;
				if(buy==1){
					land[p2].house=2;
					land[p2].value=120;
					moneyTwo-=50;
					board(land);
				}
			}
	
		}
		if(land[p2].owner==1){
			moneyOne+=land[p2].value;
			moneyTwo-=land[p2].value;
			
		}
		cout<<"2號玩家的錢: "<<moneyTwo<<endl;
		cout<<"1號玩家的錢: "<<moneyOne<<endl;  
		
		//////////
	
		cout<<endl;
		
	}
    return 0;
}

