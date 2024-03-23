#include <iostream>
#include "Image_Class.h"
using namespace std;
int main() {
    string filename;
    cout << "Please enter the image name: ";
    cin >> filename;

    Image image(filename);
    // Convert to grayscale first
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int gray = 0; // Initialize average value

            for (int k = 0; k < 3; ++k) {
                gray += image(i, j, k); // Accumulate pixel values
            }

            gray /= 3; // Calculate average
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = gray;
            }
        }
    }




    // Apply high contrast
    unsigned int threshold = 128; // Midpoint of 256 grayscale levels
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int Pixel = image(i, j, 0); // Assuming the image is now grayscale
            if (Pixel > threshold) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255; // Set to white
                }
            } else {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 0; // Set to black
                }
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    image.saveImage(filename); // Save the high-contrast image

    return 0;
}