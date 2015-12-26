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

function find_files_with_exts() {
	if [[ -z "$1" ]]
	then
		return 
	fi
	exts="${1// /\\|}"
	files=`find $PROJ_DIR -regex ".*\.\($exts\)"`
	echo $files
}

echo $PROJ_DIR
RULE_FILE="rename.rules"

EXT="h c cpp"

parse_argument "$@"

if [[ ! -f "${RULE_FILE}" ]]
then
	echo "rule file not exists."
	exit
fi

sed -ie "s/\r//g" ${RULE_FILE}

src_files=`find_files_with_exts "${EXT}"`
#echo $src_files

{
	read from to 
	while [[ $? == 0 ]]
	do
		echo Replacing \"$from\" with \"$to\"

		#./rename.sed 

		read from to
	done
} < "$RULE_FILE"
