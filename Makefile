.PHONY: $(MAKECMDGOALS)

CC=clang-13
CXX=clang++-13
LLD=lld-13
RUSTFLAGS="-Clinker-plugin-lto -Clinker=${CC} -Clink-arg=-fuse-ld=${LLD}"
RUSTFLAGS_NOLTO="-Clinker=${CC} -Clink-arg=-fuse-ld=${LLD}"

build:
	cd rust_src && CC=${CC} CXX=${CXX} RUSTFLAGS=${RUSTFLAGS} \
		cargo build --release
build_nolto:
	cd rust_src && CC=${CC} CXX=${CXX} RUSTFLAGS=${RUSTFLAGS_NOLTO} \
		cargo build --release

run:
	rust_src/target/release/xlanglto

objdump:
	objdump -d ./rust_src/target/release/xlanglto | grep "<multiply>:" -A5
	objdump -d ./rust_src/target/release/xlanglto | grep "<add_rust>:" -A5
