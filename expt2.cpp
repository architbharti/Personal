#include <iostream>
using namespace std;

int main(){

string str;
cout<<"Enter the string you want to check - "<<endl;
cin>> str;

if(str == "alignas" || str == "alignof" || str == "and" || str == "and_eq" ||
        str == "asm" || str == "atomic_cancel" || str == "atomic_commit" || str == "atomic_noexcept" ||
        str == "auto" || str == "bitand" || str == "bitor" || str == "bool" ||
        str == "break" || str == "case" || str == "catch" || str == "char" ||
        str == "char8_t" || str == "char16_t" || str == "char32_t" || str == "class" ||
        str == "compl" || str == "concept" || str == "const" || str == "consteval" ||
        str == "constexpr" || str == "constinit" || str == "const_cast" ||
        str == "continue" || str == "co_await" || str == "co_return" || str == "co_yield" ||
        str == "decltype" || str == "default" || str == "delete" || str == "do" ||
        str == "double" || str == "dynamic_cast" || str == "else" || str == "enum" ||
        str == "explicit" || str == "export" || str == "extern" || str == "false" ||
        str == "float" || str == "for" || str == "friend" || str == "goto" ||
        str == "if" || str == "inline" || str == "int" || str == "long" ||
        str == "mutable" || str == "namespace" || str == "new" || str == "noexcept" ||
        str == "not" || str == "not_eq" || str == "nullptr" || str == "operator" ||
        str == "or" || str == "or_eq" || str == "private" || str == "protected" ||
        str == "public" || str == "reflexpr" || str == "register" || str == "reinterpret_cast" ||
        str == "requires" || str == "return" || str == "short" || str == "signed" ||
        str == "sizeof" || str == "static" || str == "static_assert" || str == "static_cast" ||
        str == "struct" || str == "switch" || str == "synchronized" || str == "template" ||
        str == "this" || str == "thread_local" || str == "throw" || str == "true" ||
        str == "try" || str == "typedef" || str == "typeid" || str == "typename" ||
        str == "union" || str == "unsigned" || str == "using" || str == "virtual" ||
        str == "void" || str == "volatile" || str == "wchar_t" || str == "while" ||
        str == "xor" || str == "xor_eq"){
            cout<<"The input string is a KEYWORD!"<<endl;
        }

    else{
        cout<<"NOT a keyword!"<<endl;
    }

return 0;
}