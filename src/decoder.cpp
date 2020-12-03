#include <string>
#include <iostream>
#include <fstream>
#include <bitset>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

// finds the least significant bit of an integer
char getLSB(int str){
    if (str % 2 == 0){return '0';} //str is even
    else return '1'; //str is odd
}

bool writeToFile(const string dataStr)
{
    ofstream myfile;
    myfile.open ("decodedMsg.txt");
    if (myfile.is_open()) {
        myfile << dataStr;
        myfile.close();
        return true;
    }

    myfile.close();
    return false;
}

// converts 8-bit binary representation to char representation
string binToString (string binaryRep){
    string stringRep = "";
    for (int i=0; i<binaryRep.size(); i+=8){
        string tmpString = "";
        for (int j=i; j<i+8; j++){
            tmpString += binaryRep[j];
        }
        stringRep += static_cast<char>(bitset<8>(tmpString).to_ulong());
    }
    return stringRep;
}

int main(int argc, char *argv[])
{
    // check arg count
    if (argc != 3){
        cout << "Invalid number of arguments, see README for help. Exiting." << endl;
        return 0;
    }

    // get filename & max digits from argv
    char* inputName = argv[1];
    int maxDigits = stoi(argv[2]);
    string secretMessage = "";
    string secretMessageBin = "";
   
    // read an image
    CImg<float> imgToEncode(inputName);

    // read LSB of each pixel's R,G and B channels into a string
    int pixIndex = 0;
    cimg_forY(imgToEncode, y){
        cimg_forX(imgToEncode, x){
            for (int i=0; i<3; i++)
                if (pixIndex >= maxDigits)
                    break;
                else{
                    secretMessageBin += getLSB(imgToEncode(x,y,i));
                    pixIndex++;
                }
        }
    }

    // convert binary string to character string & print message
    secretMessage = binToString(secretMessageBin);
    if (writeToFile(secretMessage) == true) {
        cout << "Secret message is in decodedMsg.txt" << endl;
        return 0;
    }

    cout << "Failed to decode message data\n";
    return(0);
}