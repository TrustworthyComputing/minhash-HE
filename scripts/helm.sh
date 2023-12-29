current_dir=$(pwd)
cd ../../helm

cargo run --bin preprocessor --release \
   --manifest-path=./hdl-benchmarks/Cargo.toml -- \
   --input ../minhash/yosys-netlists/"$1"_in.v \
   --output ../minhash/helm-preprocessed-netlists/"$1"_out.v
cargo run --bin helm --release -- \
    --verilog ../minhash/helm-preprocessed-netlists/"$1"_out.v
cd "$current_dir"
