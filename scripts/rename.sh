#!/bin/bash

. ./path

function parse_argument() {
	while [[ $# > 1 ]]
	do
		key="$1"
		
		case $key in
			-f)
				RULE_FILE="$2"
				shift
				;;
		esac
		shift
	done

	echo RULE_FILE = "$RULE_FILE"
}

RULE_FILE="rename.rules"

parse_argument "$@"

if [[ ! -f "${RULE_FILE}" ]]
then
	echo "rule file not exists."
	exit
fi

sed -ie "s/\r//g" ${RULE_FILE}

{
	read from to 
	while [[ $? == 0 ]]
	do
		echo Replacing \"$from\" with \"$to\"


		read from to
	done
} < "$RULE_FILE"
