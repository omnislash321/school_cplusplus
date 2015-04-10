#!/bin/bash

# Change this whatever the current project is called
progName='test'

if [ ! -d ./output ]; then
	echo 'output directory is missing.'
	exit 1
fi

if [ ! -d ./my-output ]; then
	echo 'my-output directory is missing.'
	exit 1
fi

if [ ! -d ./input ]; then
	echo 'input directory is missing.'
	exit 1
fi

for inFile in ./input/*.in
do
	inFileBase=$(basename "$inFile")

	outFile=${inFileBase%.*}.out

	if [ ! -e ./output/${outFile} ]; then
		echo "Output file for ${inFileBase} was not found. Exiting"
		exit 1
	fi

	echo -n "${inFileBase}..."

	# Uncomment this line if you would like to redirect STDIN and STDOUT
	#./${progName} < ${inFile} > ./my-output/${outFile}

	# Uncomment the following line if you would like to pass input and output
	# file as command line arguments to the program.
	#./${progName} ${inFile} ./my-output/${outFile}

	diff -bi ./my-output/${outFile} ./output/${outFile} &> /dev/null


	if [ $? -eq 1 ]; then
		echo 'FAIL'
	else	
		echo 'PASS'
	fi
done
