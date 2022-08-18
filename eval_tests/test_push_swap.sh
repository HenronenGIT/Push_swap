RED='\033[0;31m'
GREEN='\033[0;32m'
OFF='\033[0m'

test_5="./test_files/5_values.txt"
operation_count_str=""
max_operation_count=12

temp=1
temp_2=2

echo "${GREEN}5 value tests${OFF}"
while IFS= read -r line;
	# do ../push_swap "$line" | wc -l > temp.txt;
	do operation_count=$(../push_swap "$line" | wc -l | xargs);
	operation_count=$((operation_count));

	if [ $operation_count -gt $max_operation_count ];then
		echo "${RED}FAIL${OFF}"
	else
		echo "${GREEN}PASS${OFF}"
	fi
done < $test_5