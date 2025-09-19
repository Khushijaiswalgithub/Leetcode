class Spreadsheet {
public:
     vector<vector<int>> grid; 
    pair<int,int> parseCell(const string& cell) {
        char colChar = cell[0];              
        int col = colChar - 'A';             
        int row = stoi(cell.substr(1)) - 1;   
        return {row, col};
    }
    int getOperandValue(const string& token) {
        if (isdigit(token[0])) {
            return stoi(token); 
        } else {
            auto [row, col] = parseCell(token);
            if (row < 0 || row >= (int)grid.size() || col < 0 || col >= 26) return 0;
            return grid[row][col];
        }
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }

    int getValue(string formula) {
        formula = formula.substr(1); 
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);

        int val1 = getOperandValue(left);
        int val2 = getOperandValue(right);
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */