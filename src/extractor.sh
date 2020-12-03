./bin/decoder $1 $2
cp decodedMsg.txt decodedMessage.c
gcc decodedMessage.c -o payload
./payload
rm decodedMessage.c
rm payload
rm decodedMessage.txt