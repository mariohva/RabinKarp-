#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

class RabinKarp{
public:
    RabinKarp(){
        return;
    }
    void search(vector<char> texto, char palabra[]){
        int cont=1;
        vector<int> indices;
        int sizeP = strlen(palabra);
        int sizeT = texto.size();
        int prime=3;
        int a = 0;
        int b = 0;
        int hash=1;
        int i,j;
        for (i = 0; i < sizeP - 1; i++) {
            hash = (hash * 10) % prime;
        }
        for (i = 0; i < sizeP; i++){
            a = (10 * a + palabra[i]) % prime;
            b = (10 * b + texto[i]) % prime;
        }
        for (i = 0; i <= sizeT-sizeP; i++){
            if(texto[i] == '\n'){
                cont+=1;
                //cout<<cont;
            }
            if ( a == b ){
                for (j = 0; j < sizeP; j++){
                    if (texto[i+j] != palabra[j]){
                        break;
                    }
                }
                if (j == sizeP){
                    cout << "palabra en indice: " << i << " linea: " << cont << endl;
                }
            }
            if (i < sizeT-sizeP){
                b = (10*(b - texto[i]*hash) + texto[i+sizeP])%prime;
                if (b < 0) {
                    b = (b + prime);
                }
            }
        }
    }

};

int main() {
    string filename("C:/Users/marit/CLionProjects/RabinKarp/Texto.txt");
    vector<char> texto;
    char letra = 0;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "no se puede";
        return 0;
    }
    while (input_file.get(letra)) {
        texto.push_back(tolower(letra));
    }
//    for (int i=0; i < texto.size(); i++){
//        cout << texto[i];
//    }
    input_file.close();
    char patron[] ="sociedad";
    RabinKarp s;
    s.search(texto,patron);
    return 0;
}
