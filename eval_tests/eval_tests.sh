RED='\033[0;31m'
GREEN='\033[0;32m'
Color_Off='\033[0m'

error_file="./test_files/error_tests.txt"
invalid_instructions="./test_files/invalid_instructions.txt"
invalid_instructions_2="./test_files/invalid_instructions_2.txt"
invalid_instructions_3="./test_files/invalid_instructions_3.txt"


# Wrong input
echo "${GREEN}Testing invalid input - only error texts should show up!${Color_Off}"
sleep 2
while IFS= read -r line;
	do ../checker "$line";
	# do echo "$line";
done < $error_file

# Without arguments
echo "${GREEN}Testing without any args - Only prompt should come back.${Color_Off}"
sleep 2
../checker 
echo ""

#Invalid operations
echo "${GREEN}Testing with invalid operations - Errors should come up.${Color_Off}"
sleep 2
ARG="3 1 2"; cat $invalid_instructions | ../checker $ARG

# Operations with extra spaces
echo "${GREEN}Testing with operations with extra spaces - Errors should come up.${Color_Off}"
sleep 2
ARG="3 1 2"; cat $invalid_instructions_2 | ../checker $ARG
ARG="3 1 2"; cat $invalid_instructions_3 | ../checker $ARG

# False tests
echo "${GREEN}False test -> KO expected${Color_Off}"
sleep 2
ARG="0 9 1 8 2 7 3 6 4 5"; echo "sa\npb\nrrr" | ../checker $ARG

# Right tests tests
echo "${GREEN}Right tests -> OK expected${Color_Off}"
../checker 0 1 2
ARG="0 9 1 8 2"; echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ../checker $ARG

