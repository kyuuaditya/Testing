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

  /*
  CImg<unsigned char> img("lena.jpeg"),vis(758,438,1,3);

//   CImg<unsigned char> img(758,438,1,3);
  img.fill(0);
  img.noise(128);
//   img.blur(2,0,0);



//   CImg<unsigned char> image("test.png");
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
    */

    /*
    CImg<unsigned char> img("test.jpg");

    // Get width, height, number of channels
    int w=img.width();
    int h=img.height();
    int c=img.spectrum();
    cout << "Dimensions: " << w << "x" << h << " " << c << " channels" <<endl;

    CImg<unsigned int> *image = new CImg<unsigned int>("test.jpg") ;

    int col[3]={255,255,255};
    // Dump all pixels
    for(int y=0;y<h;y++){
       for(int x=0;x<w;x++){
            //cout << y << "," << x << " " << (int)img(x,y) << endl;
            // cout<<img.atXY(x, y, 1,)<<" "; // this gives you the red channel
            // cout<<image->atXY(x, y, 1)<<" "; // this gives you the blue channel
            // cout<<image->atXY(x, y, 2)<< endl; // this gives you the green channel
            img(60,y,0,0)=50;
       }
    }
    img(100,200,0,0)=1;
    img(100,200,0,1)=1;
    img(100,200,0,2)=1;
    // img.save_jpeg();
    CImgDisplay pic(*image,"lets go");
    int go=0;
    while(!pic.is_closed()){
        img.display(pic);
        go=1;
    }
        // const float color[] = {1.0,1.0,0.0};
        // img.draw_point(50,50,color);
        // img.normalize(0, 255);
        img.save("test.jpg");
    

    CImg<unsigned int>*image1 = new CImg<unsigned int>("test.jpg") ;

    CImgDisplay pic1(*image1,"lets go");
    while(!pic1.is_closed()){
        img.display(pic1);
    }
    */
   int x5=800;
   int y5=600;
    CImg<unsigned char> vis(x5,y5,1,3);
    CImgDisplay draw_disp(vis,"Intensity profile");
    vis.fill(120);

    while (!draw_disp.is_closed()) {
        vis.display(draw_disp);
    }




return 0;
}