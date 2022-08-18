
# Colors for echos
RED='\033[0;31m'
BGREEN='\033[1;32m' 
GREEN='\033[0;32m'
CYAN='\033[0;36m'
PURPLE='\033[0;35m' 
YELLOW='\033[0;33m'
OFF='\033[0m'

PASS_MSG="[PASS]"
FAIL_MSG="[FAIL]"

# Files
test_5="./test_files/5_values.txt"
test_100="./test_files/100_values.txt"

# Values for scores
max_5=12
kudos_count=9
max_100=1500
two_points_100=1300
three_points_100=1100
four_points_100=900
five_points_100=700

# 5 Integer tests
# echo "${PURPLE}5 INTEGER TEST${OFF}"
# sleep 2
# while IFS= read -r line;
# 	do operation_count=$(../push_swap "$line" | wc -l | xargs);
# 	operation_count=$((operation_count));

# 	if [ $operation_count -gt $max_5 ];
# 	then
# 		echo "${RED} ${FAIL_MSG} -> ${OFF}$operation_count"
# 	elif [ $operation_count -lt $kudos_count ];
# 	then
# 		echo "${GREEN} ${PASS_MSG} + ${CYAN}KUDOS -> ${OFF}$operation_count"
# 	else
# 		echo "${GREEN} ${PASS_MSG} -> ${OFF}$operation_count"
# 	fi
# done < $test_5

# 100 Integer tests
echo "${PURPLE}100 INTEGER TEST${OFF}"
sleep 2
while IFS= read -r line;
	do operation_count=$(../push_swap "$line" | wc -l | xargs);
	operation_count=$((operation_count));

	if [ $operation_count -ge $max_100 ];then
		echo "${RED} ${FAIL_MSG} -> ${OFF}$operation_count -> ${RED}0${OFF}"
	elif [ $operation_count -lt $five_points_100 ];then
		echo "${GREEN} ${PASS_MSG} -> ${OFF}$operation_count -> ${BGREEN}5${OFF}"
	elif [ $operation_count -lt $four_points_100 ];then
		echo "${GREEN} ${PASS_MSG} -> ${OFF}$operation_count -> ${GREEN}4${OFF}"
	elif [ $operation_count -lt $three_points_100 ];then
		echo "${GREEN} ${PASS_MSG} -> ${OFF}$operation_count -> ${YELLOW}3${OFF}"
	elif [ $operation_count -lt $two_points_100 ];then
		echo "${GREEN} ${PASS_MSG} -> ${OFF}$operation_count -> ${YELLOW}2${OFF}"
	else
		echo "${GREEN} ${PASS_MSG} -> ${OFF}$operation_count -> ${RED}1${OFF}"
	fi
done < $test_100