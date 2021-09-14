#include "strBlob.h"

strBlob::strBlob() { data = make_shared<vector<string>>(); }
strBlob::strBlob(initializer_list<string> li): data(make_shared<vector<string>>(li)) {}

void strBlob::push_back(const string& s){
    data->push_back(s);
}

void strBlob::pop_back(){
    check(0, "pop_back on empty strBlob");
    data->pop_back();
}

string& strBlob::front(){
    check(0, "front on empty strBlob");
    return data->front();
}

const string& strBlob::front() const{
    check(0, "front on empty strBlob");
    return data->front();
}

string& strBlob::back(){
    check(0, "back on empty strBlob");
    return data->back();
}

const string& strBlob::back() const{
    check(0, "back on empty strBlob");
    return data->back();
}

void strBlob::check(int index, const string& msg) const {
    if(index >= data->size()){
        throw out_of_range(msg);
    }
}

strBlobPtr strBlob::begin() { return strBlobPtr(*this); }

const strBlobPtr strBlob::begin() const { return strBlobPtr(*this); }

strBlobPtr strBlob::end() { return strBlobPtr(*this, data->size()); }

const strBlobPtr strBlob::end() const { return strBlobPtr(*this, data->size()); }

// strBlobPtr

string& strBlobPtr::deref(){
        auto sp = check(curr, "dereference past end");
        return (*sp)[curr];
}

const string& strBlobPtr::deref() const{
        auto sp = check(curr, "dereference past end");
        return (*sp)[curr];
}

strBlobPtr& strBlobPtr::incr(){
    check(curr, "increment past end");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> strBlobPtr::check(size_t index, const string& msg) const{
    auto sp = ptr.lock();
    if(!sp){
        throw runtime_error("unbound strBlobPtr");
    }
    if(index >= sp->size()){
        throw out_of_range(msg);
    }
    return sp;
}