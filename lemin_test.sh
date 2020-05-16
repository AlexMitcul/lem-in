RED='\033[0;31m'
NC='\033[0m'
BLUE='\033[0;34m'
echo "${BLUE}Testing Lem-in by fstreet & cjinn.${NC}"

make re

## flow-one maps
echo "\n${RED}<----- Flow one maps ----->${NC}"
tail -1 maps/flow-one1.map
echo "result : "
./lem-in < maps/flow-one1.map | wc -l

tail -1 maps/flow-one2.map
echo "result : "
./lem-in < maps/flow-one2.map | wc -l

tail -1 maps/flow-one3.map
echo "result : "
./lem-in < maps/flow-one3.map | wc -l

tail -1 maps/flow-one4.map
echo "result : "
./lem-in < maps/flow-one4.map | wc -l

tail -1 maps/flow-one5.map
echo "result : "
./lem-in < maps/flow-one5.map | wc -l

## flow-ten maps
echo "\n${RED}<----- Flow ten maps ----->${NC}"

tail -1 maps/flow-ten1.map
echo "result : "
./lem-in < maps/flow-ten1.map | wc -l

tail -1 maps/flow-ten2.map
echo "result : "
./lem-in < maps/flow-ten2.map | wc -l

tail -1 maps/flow-ten3.map
echo "result : "
./lem-in < maps/flow-ten3.map | wc -l

tail -1 maps/flow-ten4.map
echo "result : "
./lem-in < maps/flow-ten4.map | wc -l

tail -1 maps/flow-ten5.map
echo "result : "
./lem-in < maps/flow-ten5.map | wc -l

## flow-thousand maps
echo "\n${RED}<----- Flow thousand maps ----->${NC}"

tail -1 maps/flow-thousand1.map
echo "result : "
./lem-in < maps/flow-thousand1.map | wc -l

tail -1 maps/flow-thousand2.map
echo "result : "
./lem-in < maps/flow-thousand2.map | wc -l

tail -1 maps/flow-thousand3.map
echo "result : "
./lem-in < maps/flow-thousand3.map | wc -l

tail -1 maps/flow-thousand4.map
echo "result : "
./lem-in < maps/flow-thousand4.map | wc -l

tail -1 maps/flow-thousand5.map
echo "result : "
./lem-in < maps/flow-thousand5.map | wc -l

## big maps
echo "\n${RED}<----- Big maps ----->${NC}"

tail -1 maps/big1.map
echo "result : "
./lem-in < maps/big1.map | wc -l

tail -1 maps/big2.map
echo "result : "
./lem-in < maps/big2.map | wc -l

tail -1 maps/big3.map
echo "result : "
./lem-in < maps/big3.map | wc -l

tail -1 maps/big4.map
echo "result : "
./lem-in < maps/big4.map | wc -l

tail -1 maps/big5.map
echo "result : "
./lem-in < maps/big5.map | wc -l

## big superposition maps
echo "\n${RED}<----- Big superposition maps ----->${NC}"

tail -1 maps/big-superposition1.map
echo "result : "
./lem-in < maps/big-superposition1.map | wc -l

tail -1 maps/big-superposition2.map
echo "result : "
./lem-in < maps/big-superposition2.map | wc -l

tail -1 maps/big-superposition3.map
echo "result : "
./lem-in < maps/big-superposition3.map | wc -l

tail -1 maps/big-superposition4.map
echo "result : "
./lem-in < maps/big-superposition4.map | wc -l

tail -1 maps/big-superposition5.map
echo "result : "
./lem-in < maps/big-superposition5.map | wc -l
