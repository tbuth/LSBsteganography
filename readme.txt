To Compile:
    make

To Run Encoder:
    ./encoder [imageFileName] [outputFileName] [secretMessage]
        where imageFileName is the name of the image to be encoded, 
        outputFileName is the filename to save the encoded image as, and 
        secretMessage is the text file containing the message to be encoded into the image
        
To Run Decoder:
    ./decoder [imageFileName] [secretNumber]
        where imageFileName is the name of the encoded image and 
        secretNumber is the length of the binary encoding of the secret message (given as output by encoder)

To use attack (or "extractor") script:
    -copy "extractor.sh" and "decoder" (the binary file, not decoder.cpp) into the directory where your encoded image is stored.
    -to run the script, enter the following command into a terminal instance (which should be operating in the same directory as stored images):
        ./extractor.sh [imageFileName] [secretNumber]
            where imageFileName is the name of the encoded image and 
            secretNumber is the length of the binary encoding of the secret message (given as output by encoder)
    -the c program embedded in the image will be compiled and executed.

To use defence script:
    -copy "defence.sh" and "decoder" (the binary file, not decoder.cpp) into the directory where your images are stored/downloaded to.
    -the script may be run any time a new image is downloaded (recommended), or intermittantly at the user's discretion.
    -to run the script, enter the following commands into a terminal instance (which should be operating in the same directory as stored images):
        chmod +x defence.sh
        ./defence.sh
    -follow the prompts regarding deletion of potentially malicious files.
    -the files "defence.sh" and "decoder" may remain in your image directory for easier use the next time you wish to scan your files.
