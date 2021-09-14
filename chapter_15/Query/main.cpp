#include "query.h"

int main(int argc, char** argv)
{
    ifstream in("file.txt");
    TextQuery textQuery(in);
    while(true){
        cout << "Please enter word to look for, or q to quit: ";
        string word;
        if(!(cin >> word) || word == "q"){
            break;
        }
        print(cout, textQuery.query(word));
    }
    return 0;
}