#!/bin/bash

#. ./path

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

pushd $DIR > /dev/null
. ./common.sh

PROJ_DIR=$SCRIPTS_DIR/../
echo $PROJ_DIR
RULE_FILE="rename.rules"

EXT="h c cpp"

parse_argument "$@"

if [[ ! -f "./${RULE_FILE}" ]]
then
	echo "rule file not exists."
	exit
fi

sed -i -e "s/\r//g" ./${RULE_FILE}

src_files=`find_files_with_exts "${EXT}"`
#echo $src_files

{
	read from to 
	while [[ $? == 0 ]]
	do
		echo Replacing \"$from\" with \"$to\"

		#./rename.sed 
		for file in $src_files
		do
			sed -i -e "s/$from/$to/g" $file
		done

		read from to
	done
} < "./$RULE_FILE"

popd > /dev/null
