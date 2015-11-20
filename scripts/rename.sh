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

parse_argument "$@"

if -n "${RULE_FILE}"
then
	
