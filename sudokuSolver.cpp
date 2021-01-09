#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>


using namespace std;

class location{
	public:
		int col;
		int row;
		vector<int> trash;
	
};


class sudoku{
	public:
		//these two vectors have to be available to the public because i am 
		//going to edit them from outside the class 
		vector<int> movesMade;//correct and verified
		vector<vector<int>> grid;//correct and verified
		
		vector<location> locations(){
			vector<location> data;
			for(int i = 0; i < length; i++){
				for(int j = 0; j < length; j++){
					if(grid[i][j] == 0){
						location num;
						num.col = j;
						num.row = i;
						data.push_back(num); 
					}
				}
			}
			return data;
		};//correct and verified
		
		
		vector<int> subGrid(int row, int col){
			vector<int> disqualified;
			
			if((row >= 0)&&(row < 3)&&(col >= 0 )&&(col < 3)){
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
			}
			else if((row >= 0)&&(row < 3)&&(col >= 3)&&(col < 6)){
				for(int i = 0; i < 3; i++){
					for(int j = 3; j < 6; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
				
			}
			else if((row >= 0)&&(row < 3)&&(col >= 6)&&(col < 9)){
				for(int i = 0; i < 3; i++){
					for(int j = 6; j < 9; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
				
			}
			else if((row >= 3)&&(row < 6)&&(col >= 0)&&(col < 3)){
				for(int i = 3; i < 6; i++){
					for(int j = 0; j < 3; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
		
			}
			else if((row >= 3)&&(row < 6)&&(col >= 3)&&(col < 6)){
				for(int i = 3; i < 6; i++){
					for(int j = 3; j < 6; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
				
			}
			else if((row >= 3)&&(row < 6)&&(col >= 6)&&(col < 9)){
				for(int i = 3; i < 6; i++){
					for(int j = 6; j < 9; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
				
			}
			else if((row >= 6)&&(row < 9)&&(col >= 0)&&(col < 3)){
				for(int i = 6; i < 9; i++){
					for(int j = 0; j < 3; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
				
			}
			else if((row >= 6)&&(row < 9)&&(col >= 3)&&(col < 6)){
				for(int i = 6; i < 9; i++){
					for(int j = 3; j < 6; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
			}
			else if((row >= 6)&&(row < 9)&&(col >= 6)&&(col < 9)){
		
				for(int i = 6; i < 9; i++){
					for(int j = 6; j < 9; j++){
						if(grid[i][j] != 0){
							disqualified.push_back(grid[i][j]);
						}
					}
				}
			}
		
			return disqualified;
			
		}//verified and correct		
		
				
		
		vector<int> colNums(int col){
			vector<int> remove;
			for(int i = 0; i < length; i++){
				if(grid[i][col] != 0){
					remove.push_back(grid[i][col]); 
				}
			}
			return remove;
		};//correct and verified
		
		
		vector<int> rowNums(int row){
			vector<int> remove;
			for(int i = 0; i < length; i++){
				if(grid[row][i] != 0){
					remove.push_back(grid[row][i]); 
				}
			}
			return remove;
		};//correct and verified

		
		int size(int numb){
			length = numb;
			return length;
		}//correct and verified
		
		void returner(){
			for(int i = 0; i < length; i++){
				cout<<grid[i][0]<<" "<<grid[i][1]<<" "<<grid[i][2]<<" "<<grid[i][3]<<" "<<grid[i][4]<<" "<<grid[i][5]<<" "<<grid[i][6]<<" "<<grid[i][7]<<" "<<grid[i][8]<<endl;						
//				if(i != 8){
//					cout<<endl;
//				}
			}
		};//correct and verified
		
		
		void initialGrid(vector<vector<int>> nums){
			for(int i = 0; i < length; i++){
				vector<int> dummy;
				for(int j = 0; j < length; j++){
					dummy.push_back(nums[i][j]);
				}
				grid.push_back(dummy);
			}
		}//correct and verified

	
		bool isPresent(vector<int> data,int num){
			for(int el : data){
				if(el == num){
					return true;
				}
			}
			return false;
		}//correct and verified	
		
		bool isPresentCol(int kid,int num){
			for(int el : colNums(kid)){
				if(el == num){
					return true;
				}
			}
			return false;
		}	

		bool isPresentRow(int kid,int num){
			for(int el : rowNums(kid)){
				if(el == num){
					return true;
				}
			}
			return false;
		}	
			
		bool isPresentGrid(int kid1, int kid2,int num){
			for(int el : subGrid(kid1, kid2)){
				if(el == num){
					return true;
				}
			}
			return false;
		}	

			
	private:
		int length = 9;
};






int main(){
	
	vector<int> availNums = {1,2,3,4,5,6,7,8,9};

	vector<vector<int>> data;
	
	int numbers;
	ifstream file;
	vector<int> container;
	
	string letter;
	
	while(getline(cin, letter)){
		stringstream current(letter);
		string curr;
		vector<int> nu;
		
		while(getline(current, curr, ' ')){
			nu.push_back(stoi(curr));
		}
		data.push_back(nu);  
	}
	
	
	sudoku puzzel;
	puzzel.initialGrid(data);
	vector<location> empties = puzzel.locations();
	int gaurd = 0;
	int emptyCells = empties.size();
	
	while(gaurd < emptyCells){
		vector<int> options;
		
		for(int i = 1; i < 10; i++){
			if((!puzzel.isPresentCol(empties[gaurd].col, i))){
				if(!puzzel.isPresentRow(empties[gaurd].row, i)){
					if(!puzzel.isPresentGrid(empties[gaurd].row, empties[gaurd].col, i)){
						if(!puzzel.isPresent(empties[gaurd].trash, i)){
							options.push_back(i); 					
						} 
					}
				}
			}
		}
		if(options.size() == 0){
			if(puzzel.movesMade.size()  == 0){
				cout<<"No Solution"<<endl;
				break;
			}
			empties[gaurd].trash.clear();
			puzzel.movesMade.pop_back();
 			puzzel.grid[empties[gaurd].row][empties[gaurd].col] = 0;
			gaurd--;

		}
		else{
			empties[gaurd].trash.push_back(options[options.size()-1]);
			puzzel.movesMade.push_back(options[options.size()-1]); 
			puzzel.grid[empties[gaurd].row][empties[gaurd].col] = options[options.size()-1];
			gaurd++;
			}
//			cout<<gaurd<<" ";
	}
//	location banger = empties[emptyCells-1];
	if(puzzel.grid[empties[emptyCells-1].row][empties[emptyCells-1].col] != 0){
		puzzel.returner();
	}	


	return 0;	
}

//77198448+Morake17@users.noreply.github.com
