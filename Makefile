.PHONY: $(MAKECMDGOALS)

CC=clang-13
LLD=lld-13
RUSTFLAGS="-Clinker-plugin-lto -Clinker=${CC} -Clink-arg=-fuse-ld=${LLD}"

build:
	cd rust_src && CC=${CC} RUSTFLAGS=${RUSTFLAGS} \
		cargo build --release

run:
	rust_src/target/release/xlanglto

objdump:
	objdump -d ./rust_src/target/release/xlanglto | grep "<multiply>:" -A3
