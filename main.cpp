#include<iostream>
#include<fstream>
#include "CImg.h"
using namespace std;
using namespace cimg_library;


// #define MAX_LINES 1000

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

   /*
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

   */
  // CImg<unsigned char> img("lena.jpeg"),visu(758,438,1,3);

  // CImg<unsigned char> img(758,438,1,3);
  // img.fill(0);
  // img.noise(128);
  // img.blur(2,0,0);

  CImg<unsigned char> image("lena.jpeg");
  CImg<unsigned char> vis(500,400,1,3,0);
const unsigned char red[] = { 255,0,0 }, green[] = { 0,255,0 }, blue[] = { 0,0,255 };
image.blur(2.5);
CImgDisplay main_disp(image,"Click a point"), draw_disp(vis,"Intensity profile");
while (!main_disp.is_closed() && !draw_disp.is_closed()) {
main_disp.wait();
if (main_disp.button() && main_disp.mouse_y()>=0) {
const int y = main_disp.mouse_y();
vis.fill(0).draw_graph(image.get_crop(0,y,0,0,image.width()-1,y,0,0),red,1,1,0,255,0);
vis.draw_graph(image.get_crop(0,y,0,1,image.width()-1,y,0,1),green,1,1,0,255,0);
vis.draw_graph(image.get_crop(0,y,0,2,image.width()-1,y,0,2),blue,1,1,0,255,0);
vis.display(draw_disp);
}
}
return 0;
}