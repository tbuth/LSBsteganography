#include <string>
#include <iostream>
#include <bitset>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

// modifies LSB of integer in binary representation to a given value (0 or 1)
int embedLSB(int str, int bit){
    if ((str % 2 == 0) && (bit == '0')){return str;} // str is even & bit to write is 0
    else if ((str % 2 == 0) && (bit == '1')){return str+1;} // str is even & bit to write is 1
    else if ((str % 2 != 0) && (bit == '0')){return str-1;} // str is odd & bit to write is 0
    else if ((str % 2 != 0) && (bit == '1')){return str;} // str is odd & bit to write is 1
    else return 0;
}

int main(int argc, char *argv[])
{
    // check arg count
    if (argc != 4){
        cout << "Invalid number of arguments, see README for help. Exiting." << endl;
        return 0;
    }

    // get filename from argv
    char* inputName = argv[1];
    char* outputName = argv[2];
    string secretMessage = argv[3];
    string secretMessageBin = "";

    // convert secret message to binary string
    for (std::size_t i = 0; i < secretMessage.size(); i++){
        secretMessageBin += bitset<8>(secretMessage[i]).to_string();
    }
    secretMessageBin += "&";

    // read image into Cimg object
    CImg<float> imgToEncode(inputName);

    // compute number of bits available
    float numBits = imgToEncode.width()*imgToEncode.height()*3;
    float numChar = floor(numBits/8);

    // check that message will fit into image, exit if not
    if (numBits < secretMessageBin.size()){
        cout << "The message you have entered is too long for the size of image given. Exiting." << endl;
        return 0;
    }

    // do computation on the pixels (R,G,B => 0,1,2 values)
    int pixIndex = 0;
    cimg_forY(imgToEncode, y){
        cimg_forX(imgToEncode, x){
            for (int i=0; i<3; i++)
                if (secretMessageBin[pixIndex] == '&')
                    break;
                else{
                    //std::cout << imgToEncode(x,y,i) << " + " << secretMessageBin[pixIndex] << ">> ";
                    imgToEncode(x,y,i) = embedLSB(imgToEncode(x,y,i),secretMessageBin[pixIndex]);
                    //std::cout << imgToEncode(x,y,i) << endl;
                    pixIndex++;
                }
        }
    }

    // print number of chars available
    std::cout << "Available bits: " << numBits << endl;

    // print "secret number" (ie: length of binary representation of string)
    std::cout << "Secret number: " << secretMessageBin.size()-1 << endl;

    // save image to new file
    imgToEncode.save(outputName);

    return(0);
}