// ================================================================================================================
// part 1 (5 filters + menu)

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// *** first member name: Youssef Aboalyouser Afeed Ibrahem
// ID: 20230475
// work on: darken and lighten filter , Grayscale filter ***
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// *** second member name: Ahemd Mahmoud Ibrahim Mahmoud
// ID: 20230650
// work on: black and white filter , resizing image filter ***
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// *** third member name: Mohamed Youssef Ishaq Abdel Hafeez
// ID: 20230790
// work on: invert image filter , menu ***
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ================================================================================================================
#include "Image_Class.h"
#include <iostream>
using namespace std;
string filename;
int main();
void mergetowpic(Image &picture1, Image &picture2)
{

    string ask;
    cout << "do you want to save new image[Y/N]: ";
    cin >> ask;
    if (ask == "Y" || ask == "y")
    {
        cout << "write your name of new image(don't forget extension): ";
        cin >> filename;
        int new_width = 1024;
        int new_hight = 1024;
        Image new_picture1(new_width, new_hight);
        Image new_picture2(new_width, new_hight);
        Image final_photo(new_width, new_hight);
        float x_scale1 = static_cast<float>(picture1.width) / new_width;
        float y_scale1 = static_cast<float>(picture1.height) / new_hight;

        float x_scale2 = static_cast<float>(picture2.width) / new_width;
        float y_scale2 = static_cast<float>(picture2.height) / new_hight;

        for (int y = 0; y < new_hight; ++y)
        {
            for (int x = 0; x < new_width; ++x)
            {
                int origx1 = static_cast<int>(x * x_scale1);
                int origy1 = static_cast<int>(y * y_scale1);

                int origx2 = static_cast<int>(x * x_scale2);
                int origy2 = static_cast<int>(y * y_scale2);

                for (int c = 0; c < 3; ++c)
                {
                    new_picture1.imageData[(y * new_width + x) * 3 + c] =
                        picture1.imageData[(origy1 * picture1.width + origx1) * 3 + c];

                    new_picture2.imageData[(y * new_width + x) * 3 + c] =
                        picture2.imageData[(origy2 * picture2.width + origx2) * 3 + c];
                }
            }
        }
        for (int i = 0; i < final_photo.width; i++)
        {
            for (int j = 0; j < final_photo.height; j++)
            {
                unsigned int picture1_pixel;
                unsigned int picture2_pixel;
                for (int k = 0; k < 3; k++)
                {
                    picture1_pixel = new_picture1(i, j, k);
                    picture2_pixel = new_picture2(i, j, k);
                }
                final_photo(i, j, 0) = (new_picture1(i, j, 0) + new_picture2(i, j, 0)) / 2; // Red channel
                final_photo(i, j, 1) = (new_picture1(i, j, 1) + new_picture2(i, j, 1)) / 2; // Green channel
                final_photo(i, j, 2) = (new_picture1(i, j, 2) + new_picture2(i, j, 2)) / 2; // Blue channel
            }
        }
        final_photo.saveImage(filename);
    }
    else if (ask == "N" || ask == "n")
    {
        main();
    }
    else
    {
        cout << "ERROR! , try again" << endl;
        cout << "=========================================================================\n";
        main();
    }
}

void edgedetictiveFilter(Image &picture)
{
    int value = 10;
    for (int i = 0; i < picture.width; i++)
    {
        for (int j = 0; j < picture.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (abs(picture(i, j, k) - picture(i + 1, j, k)) > value && abs(picture(i, j, k) - picture(i, j + 1, k)) > value)
                {
                    picture(i, j, k) = 0;
                }
                else
                {
                    picture(i, j, k) = 255;
                }
            }
        }
    }
}

void Flip_Horizontal(Image &photo)
{
    int width = photo.width;
    for (int j = 0; j < photo.height; ++j)
    {
        for (int i = 0; i < width / 2; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                int temp = photo.imageData[(j * width + i) * 3 + k];
                photo.imageData[(j * width + i) * 3 + k] = photo.imageData[(j * width + (width - 1 - i)) * 3 + k];
                photo.imageData[(j * width + (width - 1 - i)) * 3 + k] = temp;
            }
        }
    }
}

void Flip_Vertical(Image &photo)
{
    int width = photo.width;
    int height = photo.height;
    for (int j = 0; j < height / 2; ++j)
    {
        for (int i = 0; i < width; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                int temp = photo.imageData[(j * width + i) * 3 + k];
                photo.imageData[(j * width + i) * 3 + k] = photo.imageData[((height - 1 - j) * width + i) * 3 + k];
                photo.imageData[((height - 1 - j) * width + i) * 3 + k] = temp;
            }
        }
    }
}

void invert_image(Image &picture)
{
    for (int i = 0; i < picture.width; i++)
    {
        for (int j = 0; j < picture.height; j++) // make nested loop to access every pixel in the photo
        {
            // convert pright pexel to darker pixel and the invers is correct
            // by subtract from maximum value
            picture(i, j, 0) = 255 - picture(i, j, 0);
            picture(i, j, 1) = 255 - picture(i, j, 1);
            picture(i, j, 2) = 255 - picture(i, j, 2);
        }
    }
}

void darken_lighten_filter(Image &picture, string ver)
{
    if (ver == "i" || ver == "I") // darken version
    {
        for (int i = 0; i < picture.width; i++)
        {
            for (int j = 0; j < picture.height; j++)
            {
                // access every pixel and multiplay the value of rgb by 1/2 to make it darker
                picture(i, j, 0) *= 0.5f;
                picture(i, j, 1) *= 0.5f;
                picture(i, j, 2) *= 0.5f;
            }
        }
    }
    else if (ver == "I" || ver == "II") // lighten version
    {
        for (int i = 0; i < picture.width; i++)
        {
            for (int j = 0; j < picture.height; j++)
            {

                // access every pixel and multiplay the value of rgb by 1.5 to make it lighter
                picture(i, j, 0) *= 1.5f;
                picture(i, j, 1) *= 1.5f;
                picture(i, j, 2) *= 1.5f;
            }
        }
    }
}

void GrayscaleFilter(Image &picture)
{
    for (int i = 0; i < picture.width; i++)
    {
        for (int j = 0; j < picture.height; j++)
        {
            // access to all pixel and calculte the average or rgb value
            unsigned int average = 0;
            for (int k = 0; k < 3; k++)
            {
                average += picture(i, j, k);
            }
            average /= 3;
            // applay the average of rgb to all pixel to rech grayscale look
            picture(i, j, 0) = average;
            picture(i, j, 1) = average;
            picture(i, j, 2) = average;
        }
    }
}
// black and white filter
void black_and_whiteFilter(Image &photo)
{
    // convert to black and white
    unsigned int Midpoint = 127; // Midpoint of 255 grayscale levels
    for (int i = 0; i < photo.width; ++i)
    {
        for (int j = 0; j < photo.height; ++j)
        {
            unsigned int Pixel = photo(i, j, 0);
            if (Pixel > Midpoint)
            {
                for (int k = 0; k < 3; ++k)
                {
                    photo(i, j, k) = 255; // Set to white
                }
            }
            else
            {
                for (int k = 0; k < 3; ++k)
                {
                    photo(i, j, k) = 60; // Set to black
                    photo(i, j, k) = 0;  // Set to black
                }
            }
        }
    }
}
// resizing filter
void resizing(Image &photo, string ask)
{
    int new_width = 0;
    int new_height = 0;
    string choice;
    float ratio = 0.0;
    if (ask == "y" || ask == "Y")
    {
        cout << "write your name of new image(don't forget extension): ";
        cin >> filename;

        cout << "please select: A)enter the new width and height     Z)enter a ratio of reduction or increase " << endl;
        cout << ": ";
        cin >> choice;
        if (choice == "A" || choice == "a")
        {
            cout << "please enter the new width: ";
            cin >> new_width;
            cout << "please enter the new height: ";
            cin >> new_height;
        }
        else if (choice == "z" || choice == "Z")
        {
            cout << "please enter the resize ratio(e.g.,0.5 for half size):";
            cin >> ratio;
            new_width = static_cast<int>(photo.width * ratio);
            new_height = static_cast<int>(photo.height * ratio);
        }
        // Create a new photo with the desired dimensions
        Image new_photo(new_width, new_height);

        // Calculate the scaling factors
        float X_scale = static_cast<float>(photo.width) / new_width;
        float Y_scale = static_cast<float>(photo.height) / new_height;

        // Copy and scale the pixel data
        for (int y = 0; y < new_height; ++y)
        {
            for (int x = 0; x < new_width; ++x)
            {
                int origX = static_cast<int>(x * X_scale);
                int origY = static_cast<int>(y * Y_scale);

                // Assuming the pixel data is stored in a 1D array and each pixel has 3 channels (RGB)
                for (int c = 0; c < 3; ++c)
                {
                    new_photo.imageData[(y * new_width + x) * 3 + c] =
                        photo.imageData[(origY * photo.width + origX) * 3 + c];
                }
            }
        }
        new_photo.saveImage(filename);
    }
    else if (ask == "n" || ask == "N")
    {
        main();
    }
    else
    {
        cout << "ERROR! , try again" << endl;
        cout << "=========================================================================\n";
        main();
    }
}
int main()
{
    while (true) // make infinite loop to use the programm
    {
        string chooce;
        cout << "Do you want to use the application?" << endl;
        cout << "[Y/N]: ";
        cin >> chooce;
        if (chooce == "Y" || chooce == "y")
        {
            string ask;
            string filterchooce;
            cout << "put your image name or path (with extension): ";
            cin >> filename;         // take filename of wanted picture
            Image picture(filename); // make variable to use the picture for type Image
            cout << "***we have lots of filters to applay***" << endl;
            cout << "=============================================================================\n";
            cout << "A) Grayscale conversion                B) Black and white\n"
                 << endl;
            cout << "C) Invert image                        D) Merge images\n"
                 << endl;
            cout << "E) Flip image                          F) Rotat image\n"
                 << endl;
            cout << "G) Darken or Lighten image             H) Crop images\n"
                 << endl;
            cout << "I) Adding a frame to the picture       J) Detect image edges\n"
                 << endl;
            cout << "K) Resizing images                     L) Blur images\n"
                 << endl;
            cout << "=============================================================================\n";
            cout << "chooce any one to apply: ";
            cin >> filterchooce;
            if (filterchooce == "A" || filterchooce == "a")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if (ask == "Y" || ask == "y")
                {
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    GrayscaleFilter(picture);    // calll grayscale function
                    picture.saveImage(filename); // save new image with new file name
                }
                else
                {
                    cout << "ERROR! , try again" << endl;
                    cout << "=========================================================================\n";
                    main(); // if user does not want to save changed recall the programm
                }
            }
            else if (filterchooce == "B" || filterchooce == "b")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if (ask == "Y" || ask == "y")
                {
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    GrayscaleFilter(picture);       // convert first the picture to grayscale
                    black_and_whiteFilter(picture); // second convert it to black and white
                    picture.saveImage(filename);    // save image with new file name
                }
                else if (ask == "N" || ask == "n")
                {
                    main();
                }
                else
                {
                    cout << "ERROR! , try again" << endl;
                    cout << "=========================================================================\n";
                    main();
                }
            }
            else if (filterchooce == "C" || filterchooce == "c")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if (ask == "Y" || ask == "y")
                {
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    invert_image(picture);       // call the function to convert colours
                    picture.saveImage(filename); // save new image with new filename
                }
                else if (ask == "N" || ask == "n")
                {
                    main();
                }
                else
                {
                    cout << "ERROR! , try again" << endl;
                    cout << "=========================================================================\n";
                    main();
                }
            }
            else if (filterchooce == "D" || filterchooce == "d")
            {
                cout << "put your second image name or path (with extension): ";
                cin >> filename;
                Image picture2(filename);

                mergetowpic(picture, picture2);
                // cout << "not completed yet!" << endl;
                // cout << "==========================================================================\n";
                // main();
            }
            else if (filterchooce == "E" || filterchooce == "e")
            {
                string choice;
                cout << "Enter what do want to do" << endl;
                cout << "a)Horizontally    b) vertically" << endl;
                cout << ": ";
                cin >> choice;
                if (choice == "a" || choice == "A")
                {
                    Flip_Horizontal(picture);
                }
                else if (choice == "b" || choice == "B")
                {
                    Flip_Vertical(picture);
                }
                else
                {
                    cout << "try again!";
                    main();
                }
                cout << "Enter new photo name(with extension): ";
                cin >> filename;
                picture.saveImage(filename);
                // cout << "not completed yet!" <<endl;
                // main();
            }
            else if (filterchooce == "F" || filterchooce == "f")
            {
                cout << "not completed yet!" << endl;
                main();
            }
            else if (filterchooce == "G" || filterchooce == "g")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if (ask == "Y" || ask == "y")
                {
                    string ver;
                    cout << "i)darken version         ii)lighten version " << endl;
                    cout << ": ";

                    cin >> ver;
                    cout << "write your name of new image(don't forget extension): ";
                    cin >> filename;
                    darken_lighten_filter(picture, ver);
                    picture.saveImage(filename);
                }
                else if (ask == "N" || ask == "n")
                {
                    main();
                }
                else
                {
                    cout << "ERROR! , try again" << endl;
                    cout << "=========================================================================\n";
                    main();
                }
            }
            else if (filterchooce == "H" || filterchooce == "h")
            {
                cout << "not completed yet!" << endl;
                main();
            }
            else if (filterchooce == "I" || filterchooce == "i")
            {
                cout << "not completed yet!" << endl;
                main();
            }
            else if (filterchooce == "J" || filterchooce == "j")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                if (ask == "Y" || ask == "y")
                {
                    GrayscaleFilter(picture);
                    edgedetictiveFilter(picture);
                    cout << "Enter new photo name(with extension): ";
                    cin >> filename;
                    picture.saveImage(filename);
                }
                else if (ask == "N" || ask == "n")
                {
                    main();
                }
                else
                {
                    cout << "ERROR! , try again" << endl;
                    cout << "=========================================================================\n";
                    main();
                }
                // cout << "not completed yet!" << endl;
                // main();
            }
            else if (filterchooce == "K" || filterchooce == "k")
            {
                cout << "do you want to save new image[Y/N]: ";
                cin >> ask;
                resizing(picture, ask);
            }
            else if (filterchooce == "L" || filterchooce == "l")
            {
                cout << "not completed yet!" << endl;
                main();
            }
            else
            {
                cout << "ERROR! , try again" << endl;
                cout << "=========================================================================\n";
                main();
            }
        }
        else if (chooce == "N" || chooce == "n")
        {
            cout << "***GODE BYE***";
            exit(EXIT_SUCCESS);
        }
    }
}
