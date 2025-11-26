#include <iostream>
#include "checkconst.h"
using namespace std;

int main()
{
    char word[100];
    cout<<"Enter the string you want to check - "<<endl;
    cin>> word;

    if(isConstant(word)){
       cout<<"It is a constant"<<endl;
    }
    else{
        cout<<"It is not a constant"<<endl;
    }

    

    return 0;
}
