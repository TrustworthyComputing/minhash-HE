bash xls.sh "$1"
yosys -s yosys.ys "$1".v
mv minhash_in.v ../yosys-netlists/"$1"_in.v