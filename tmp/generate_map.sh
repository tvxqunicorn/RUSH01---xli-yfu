RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
g++ map.cpp -o test
./test $1 > test_case.txt
make -C ../
cat test_case.txt | ../ofc > result
diff result real > diff.txt
rm -rf test
if [[ -s "diff.txt" ]]
then	printf "${RED}KO${NC}\n"
else
	rm -rf diff.txt test_case.txt result real 
	printf "${GREEN}OK${NC}\n"
fi