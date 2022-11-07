#!/bin/bash
#A simple shell script/code to that passes the Betty checks
BIN_PATH="/usr/local/bin"
BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"
if [ "$#" = "0" ]; then
	echo "No argumentshave been passed."
	exit 1
fi
for argument in "$@" ; do
	 echo -e "\n======== $argument ========"
	 ${BIN_PATH}/${BETTY_STYLE} "$argument"
	 ${BIN_PATH}/${BETTY_DOC} "$argument"
done
