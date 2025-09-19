class Spreadsheet {
      vector<vector<int>> grid;
public:
    Spreadsheet(int rows) {
     grid.resize(rows+1, vector<int>(26, 0)); 
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1));
        grid[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1));
        grid[row][col]=0;
    }
    
    int getValue(string formula) {
        string s=formula.substr(1);
        string store="";
        int i=0;
        while(s[i]!='+'){
            store+=s[i];
            i++;
        }
        i++;
        string store2;
        while(i<s.size()){
            store2+=s[i];
            i++;
        }
        if(store[0]>='A' && store[0]<='Z' && store2[0]>='A' && store2[0]<='Z'){
             int row1=stoi(store.substr(1));
             int col1=store[0]-'A';
             int row2=stoi(store2.substr(1));
             int col2=store2[0]-'A';

             return grid[row1][col1]+grid[row2][col2];
        }
        else if(store[0]>='A' && store[0]<='Z'){
               int row1=stoi(store.substr(1));
             int col1=store[0]-'A';
             return stoi(store2)+grid[row1][col1];
        }
        else if(store2[0]>='A' && store2[0]<='Z'){
            int row2=stoi(store2.substr(1));
             int col2=store2[0]-'A';
             return stoi(store)+grid[row2][col2];
        }
        return stoi(store)+stoi(store2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */