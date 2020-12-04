shopt -s nullglob # stops bash from throwing an error if there are no .png or .bmp files in current directory
for f in *.{png,bmp}# iterate through .png and .bmp files in directory
do
	echo "Checking for malicious content in file - $f"
	./decoder "$f" 480 >> /dev/null # run the decoder on f and output the first 60 characters to a text file
	if [[ $(cat decodedMsg.txt | grep -q main ; echo $?) = *0* ]]; then # check if the first 60 characters contain the string "main" (ie: the c/c++ function header)
		echo "Potentially malicious code found in: $f. Enter \"Remove\" to permanently delete this file, or any other input to skip." # if main is found, ask user for permission to delete the file
		read userIn
		if [[ $(echo "$userIn") = *Remove* ]]; then # if the user gives permission to delete the file, do so
			rm "$f"
		fi
	fi
done
rm decodedMsg.txt # delete intermediary files