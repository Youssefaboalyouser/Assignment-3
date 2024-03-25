#include"Image_Class.h"
#include<iostream>
using namespace std;
// 12 filters (5 must submit in 3 dayes)
//youssef ====> menu + 1 filter from(1,4,7,10)
//ahmed ====>  2 filter(2,5,8,11)
//mohamed ====>  2 filter(3,6,9,12)
// =======================================================================================
void darken_lighten_filter(Image& picture,string ver)
{
    if(ver == "i" || ver == "I")//darken version
    {
        for(int i = 0 ; i < picture.width ; i++)
        {
            for(int j = 0 ; j < picture.height ; j++)
            {
                picture(i,j,0) *= 0.5f;
                picture(i,j,1) *= 0.5f;
                picture(i,j,2) *= 0.5f;

            }
        }

    }
    else if(ver == "I" || ver == "II")//lighten version
    {
        for(int i = 0 ; i < picture.width ; i++)
        {
            for(int j = 0 ; j < picture.height ; j++)
            {
                picture(i,j,0) *= 1.5f;
                picture(i,j,1) *= 1.5f;
                picture(i,j,2) *= 1.5f;

            }
        }

    }

}


void GrayscaleFilter(Image& picture)
{
    for(int i = 0 ; i < picture.width ; i++)
    {
        for(int j = 0 ; j < picture.height ; j++)
        {
            unsigned int average = 0;
            for(int k = 0 ; k < 3 ; k++)
            {
                average += picture(i,j,k);
            }
            average /= 3;
            picture(i,j,0) = average;
            picture(i,j,1) = average;
            picture(i,j,2) = average;
        }
    }
}
// black and white filter
void black_and_whiteFilter(Image& photo){
    // convert to black and white
    unsigned int Midpoint = 127; // Midpoint of 255 grayscale levels
    for (int i = 0; i < photo.width; ++i) {
        for (int j = 0; j < photo.height; ++j) {
            unsigned int Pixel = photo(i, j, 0); 
            if (Pixel > Midpoint) {
                for (int k = 0; k < 3; ++k) {
                    photo(i, j, k) = 255; // Set to white
                }
            } else {
                for (int k = 0; k < 3; ++k) {
                    photo(i, j, k) = 60; // Set to black
                    photo(i, j, k) = 0; // Set to black
                }
            }
        }
    }
}
// resizing filter 
void resizing(Image& photo){
    int choice=0 , new_width=0, new_height=0;
    float ratio=0.0;
    cout<<"please select: 1)enter the new width and height     2)enter a ratio of reduction or increase ";
    cin>>choice;
    if (choice==1){
        cout<<"please enter the new width and height:";
        cin >> new_width >> new_height;
    }else if(choice==2){
        cout<<"please enter the resize ratio(e.g.,0.5 for half size):";
        cin>>ratio;
        new_width=static_cast<int>(photo.width * ratio);
        new_height=static_cast<int>(photo.height * ratio);
    }
    // Create a new photo with the desired dimensions
    Image new_photo(new_width, new_height);

    // Calculate the scaling factors
    float X_scale = static_cast<float>(photo.width) / new_width;
    float Y_scale = static_cast<float>(photo.height) / new_height;

    // Copy and scale the pixel data
    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            int origX = static_cast<int>(x * X_scale);
            int origY = static_cast<int>(y * Y_scale);

            // Assuming the pixel data is stored in a 1D array and each pixel has 3 channels (RGB)
            for (int c = 0; c < 3; ++c) {
                new_photo.imageData[(y * new_width + x) * 3 + c] =
                        photo.imageData[(origY * photo.width + origX) * 3 + c];
            }
        }
    }
}
int main()
{
    while (true)
    {
        string chooce;
        cout << "Do you want to use the application?"<<endl;
        cout <<"[Y/N]: ";
        cin >> chooce;
        if(chooce == "Y" || chooce == "y" )
        {
            string ask;
            string filename;
            string filterchooce;
            cout << "put your image name or path (with extension): ";
            cin >> filename;
            Image picture(filename);
            cout << "***we have lots of filters to applay***" << endl;
            cout <<"=============================================================================\n";
            cout << "A) Grayscale conversion                B) Black and white\n"<<endl;
            cout << "C) Invert image                         D) Merge images\n"<<endl;
            cout << "E) Flip image                          F) Rotat image\n"<<endl;
            cout << "G) Darken or Lighten image             H) Crop images\n"<<endl;
            cout << "I) Adding a frame to the picture       J) Detect image edges\n"<<endl;
            cout << "K) Resizing images                     L) Blur images\n"<<endl;
            cout <<"=============================================================================\n";
            cout << "chooce any one to apply: ";
            cin >> filterchooce;
            if(filterchooce == "A" || filterchooce == "a" )
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if(ask == "Y" || ask == "y")
                {
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    GrayscaleFilter(picture);
                    picture.saveImage(filename);
                }
                else{
                    exit(EXIT_SUCCESS);
                }
                
            }
            else if(filterchooce == "B" || filterchooce == "b")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if(ask == "Y" || ask == "y")
                {
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    GrayscaleFilter(picture);
                    black_and_whiteFilter(picture);
                    // black_and_whiteFilter(photo);
                    picture.saveImage(filename);

                }
                else{
                    exit(EXIT_SUCCESS);
                }
            }
            else if(filterchooce == "C" || filterchooce == "c")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "D" || filterchooce == "d")
            {
                // make function do the filter and call it here 
                // make function do the filter and call it here 
            }
            else if(filterchooce == "E" || filterchooce == "e")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "F" || filterchooce == "f")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "G" || filterchooce == "g")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if(ask == "Y" || ask == "y")
                {
                    string ver;
                    cout << "i)darken version         ii)lighten version " <<endl;
                    cout <<": ";

                    cin >> ver;
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    darken_lighten_filter(picture,ver);
                    picture.saveImage(filename);
                }
                else{
                    exit(EXIT_SUCCESS);
                }
               
            }
            else if(filterchooce == "H" || filterchooce == "h")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "I" || filterchooce == "i")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "J" || filterchooce == "j")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "K" || filterchooce == "k")
            {
                // make function do the filter and call it here 
            }
            else if(filterchooce == "L" || filterchooce == "l")
            {
                // make function do the filter and call it here 
            }
            else{
                cout << "Error.try again!" <<endl;
                break;
            }
        }
        else if(chooce == "N" || chooce == "n")
        {
            cout << "***GODE BYE***";
            exit(EXIT_SUCCESS);
        }
    }
    
    
}
