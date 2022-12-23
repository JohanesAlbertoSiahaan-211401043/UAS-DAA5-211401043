#include <bits/stdc++.h>

using namespace std;

void mainLine();
void line();
void preKMP(string x, int m, int kmpNext[]);
void KMP(string x, int m, string y, int n);

int main()
{
    string text, pattern;

    system("cls");

    mainLine();
    cout << "|                   STRING MATCHING PROGRAM                    |" << endl;
    mainLine();  

    cout << "Input your text : ";
    getline(cin,text);

    line();
    cout << "Input your word you want to search : ";
    getline(cin,pattern);

    system("cls");

    mainLine();
    cout << "|                            RESULT                            |" << endl;
    mainLine();

    KMP(pattern,pattern.length(),text,text.length());

    return 0;
}

void mainLine(){
    cout << "================================================================" << endl;
}

void line(){
    cout << "----------------------------------------------------------------" << endl;
}

void preKMP(string x, int m, int kmpNext[]){
    int i , j;

    i = 0;
    j = kmpNext[0] = -1;

    while (i < m){
        while (j > -1 && x[i] != x[j]){
            j = kmpNext[j];
        }
        i++;
        j++;

        if(x[i] == x[j]){
            kmpNext[i] = kmpNext[j];
        } else {
            kmpNext[i] = j;
        }
    }
}

void KMP(string x, int m, string y, int n)
{
    int i, j, kmpNext[m];

    preKMP(x, m, kmpNext);

    cout << "KMPNext Table : | ";

    for(int a = 0; a <= m; a++){
        cout << kmpNext[a] << " | ";
    }

    i = j = 0;

    cout << endl;
    while(j < n){
        while (i > -1 && x[i] !=y [j]){
            i = kmpNext[i];
        }

        i++;
        j++;

        if(i >= m){
            cout << "Found in index : " << (j-i) << endl;
            i = kmpNext[i];
        }
        else if(i < m && j == n){
            cout << endl;
            cout << "Data not found" << endl;
        }
    }
    line();
}