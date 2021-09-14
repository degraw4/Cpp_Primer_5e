#include "strBlob.h"

int main(){
    strBlob b1({"hello", "world"});
    const strBlob cb1({"hello", "world", "const"});
    b1.push_back("test");
    cout << b1.back() << endl;
    cout << cb1.back() << endl;

    strBlobPtr bp1(b1);
    strBlobPtr bp2(cb1);
    const strBlobPtr cbp1(cb1);
    cout << bp1.deref() << endl;
    bp1.incr();
    cout << bp1.deref() << endl;

    cout << b1.begin().deref()<< endl;
    cout << cb1.begin().deref()<< endl;

    return 0;
}