#include"Image_Class.h"
#include<iostream>
using namespace std;
// 12 filters (5 must submit in 3 dayes)
//youssef ====> menu + 1 filter from(1,4,7,10)
//ahmed ====>  2 filter(2,5,8,11)
//mohamed ====>  2 filter(3,6,9,12)


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
            string filename;
            string filterchooce;
            cout << "put your image name or path (with extension): ";
            cin >> filename;
            Image picture(filename);
            cout << "***we have lots of filters to applay***" << endl;
            cout <<"=============================================================================\n";
            cout << "A) Grayscale conversion                B) Blach and white\n"<<endl;
            cout << "C)Invert image                         D) Merge images\n"<<endl;
            cout << "E) Flip image                          F) Rotat image\n"<<endl;
            cout << "G) Darken and Lighten image            H) Crop images\n"<<endl;
            cout << "I) Adding a frame to the picture       J) Detect image edges\n"<<endl;
            cout << "K) Resizing images                     L) Blur images\n"<<endl;
            cout <<"=============================================================================\n";
            cout << "chooce any one do you apply: ";
            cin >> filterchooce;
            if(filterchooce == "A" || filterchooce == "a" )
            {
                // make function do the filter and call it here 

            }
            else if(filterchooce == "B" || filterchooce == "b")
            {
                // make function do the filter and call it here 
                
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

                // make function do the filter and call it here 
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

