#!/bin/bash
NC='\033[0m'
RED='\033[0;31m'
CYAN='\033[0;36m'

# find maps files
find maps -name "*.map" > output.txt

# sortind the file with maps and print them
printf "${CYAN}Files"
sort -r output.txt
printf "\n\n${NC}"

# get lines number in maps file
lines=$( cat output.txt | wc -l )


for ((i=1; i<=$lines; i++))
do
	filename=$( head -$i output.txt | tail -1 )
	printf "${CYAN} file $filename ${NC}\n"
	printf "Required lines is = ${RED}$(tail -1 $filename | awk '{print $8}') ${NC}"
	printf " our lem-in is =${RED}$(./lem-in < $filename | wc -l) ${NC}\n"
done
