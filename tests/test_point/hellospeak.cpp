#include "speak.h"
using namespace std;
Speak* r(){
    Speak r;
    r.i = "in";
    Speak *p = new Speak;
    p->i = "p";
    Speak* s = &r;
    s->i = "in2";
    return p;
}
std::string a(std::string& p){
    cout << p << endl;
    p = "chage it";
    return p;
}
int main(int argc,char *argv[])
{
        Speak speak;
        Speak *c = r();
        std::cout << c << " 's i is " << c->i << endl;
        delete c;
        speak.i = "1";
        a(speak.i);
        std::string cc = "555";
        a(cc);
        cout << cc << endl;
        speak.sayHello("world" + speak.i);
                return(0);

}
