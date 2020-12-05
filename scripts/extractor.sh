./decoder $1 $2 # run the decoder by passing through CL arguments as input
cp decodedMsg.txt decodedMessage.c # copy the decoded message to a new file with the .c extension to allow compilation
gcc decodedMessage.c -o payload # compile the decoded message
./payload # execute the decoded message
rm decodedMessage.c #remove the intermediary files
rm payload
rm decodedMessage.txt