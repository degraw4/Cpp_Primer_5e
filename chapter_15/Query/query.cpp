#include "query.h"

TextQuery::TextQuery(ifstream &in): file(new vector<string>){
    string line_text;
    while(getline(in, line_text)){
        file->push_back(line_text);
        int line_number = file->size();
        istringstream line_words(line_text);
        string word;
        while(line_words >> word){
            auto& sp = times[word];
            if(!sp){
                sp.reset(new set<int>);
            }
            sp->insert(line_number);
        }
    }
}

QueryResult TextQuery::query(const string& s) const{
    static shared_ptr<set<int>> no_result(new set<int>);
    if(times.find(s) == times.end()){
        return QueryResult(s, file, no_result);
    }
    else{
        // return QueryResult(s, file, times[s]); // times[s]会改变times，与const成员函数相违背
        return QueryResult(s, file, times.find(s)->second);
    }
}

ostream& print(ostream& os, const QueryResult& qr){
    os << qr.word << " occurs " << qr.lines->size() << " times" << endl;
    for(auto a: *qr.lines){
        os << "\t(line " << a << ") " << *(qr.file->begin() + a - 1) << endl;
    }
}