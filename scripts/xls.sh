../../xls/bazel-bin/xls/contrib/xlscc/xlscc "$1".cc > minhash.ir
../../xls/bazel-bin/xls/tools/opt_main minhash.ir > minhash.opt.ir
../../xls/bazel-bin/xls/tools/codegen_main minhash.opt.ir \
  --generator=combinational \
  --delay_model="unit" \
  --output_verilog_path="$1".v \
  --module_name=min_hash \
  --top=minhash
rm minhash.ir
rm minhash.opt.ir

