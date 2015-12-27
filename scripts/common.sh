#!/bin/bash

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

function find_files_with_exts() {
	if [[ -z "$1" ]]
	then
		return 
	fi
	exts="${1// /\\|}"
	files=`find $PROJ_DIR -regex ".*\.\($exts\)"`
	echo $files
}

