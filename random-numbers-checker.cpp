#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    for(int i=0;i<500;i++)
        cout << rand() % 10 << endl;     
}
