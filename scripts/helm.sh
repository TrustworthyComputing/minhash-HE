current_dir=$(pwd)
cd ../helm

cargo run --bin preprocessor --release \
   --manifest-path=./hdl-benchmarks/Cargo.toml -- \
   --input ../minhash/"$1"_in.v \
   --output ../minhash/"$1"_out.v
cargo run --bin helm --release -- \
    --verilog ../minhash/"$1"_out.v
cd "$current_dir"
