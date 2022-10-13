/*
ID: achenni1
TASK: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int a, b, z, q;
int r[100005], rp, cycp; 
int de[100005],  dn;     
 
int main() {
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    fin >> a >> b;
    z = a / b;
    a -= z * b;
    while(1) {   
        if (r[a]) {
            cycp = r[a];
            break;
        }
        r[a] = ++rp;
        a *= 10;
        q = a / b;
        a = a - q * b;
        de[++dn] = q;
        if(a == 0) {
            rp =- 1;
            break;
        }       
    }
    int cnt = 2;
    for(int i = z; i > 9; i /= 10) {
        cnt++;
	}
    fout << z << ".";
    for(int i = 1; i <= dn; i++, cnt++) {
        if(cnt % 76 == 0)
        fout << endl;
        if(i == cycp)
        {
            fout << "(";
            cnt++;
        }
        fout << de[i];
        if(i == rp) fout << ")";
    }   
    fout << endl;
    return 0;
}