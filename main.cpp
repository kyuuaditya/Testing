#include<iostream>
#include<fstream>
using namespace std;

#define MAX_LINES 1000

int main() {
    // to check the randomness of rand() and use-case of srand(time(0))
    /*
    srand(time(0));
    int iterations = 100000;
    int count[10] = {0};
    int temp;
    for (int i = 0; i < iterations; i++) {
        temp = rand() % 10;
        count[temp]++;
    }
    for (int i = 0; i < 10; i++) {
        cout << count[i] << " ";
    }
    */

   string filename;
   ifstream file;
   string array[MAX_LINES];

   cout<<"File name: ";
   cin>>filename;

   file.open(filename);

   if(file.fail()){
    cout<<"File failed to oprn."<<endl;
    return 1;
   }

   int lines=0;

   while(!file.eof()){
    getline(file,array[lines]);
    lines++;

    if(lines==MAX_LINES){
        cout<<"Max storage reached"<<endl;
        break;
    }
   }

   file.close();

   for(int i=0;i<lines;i++){
    cout<<array[i]<<endl;
   }

   return 0;
}