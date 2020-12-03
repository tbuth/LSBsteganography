To Compile:
    make

To Run Encoder:
    ./encoder imageFileName outputFileName secretMessage
        where imageFileName is the name of the image to be encoded, 
        outputFileName is the filename to save the encoded image as, and 
        secretMessage is the message to be encoded into the image
        
To Run Decoder:
    ./decoder imageFileName secretNumber
        where imageFileName is the name of the encoded image and 
        secretNumber is the length of the binary encoding of the secret message (given as output by encoder)