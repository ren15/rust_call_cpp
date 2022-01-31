.PHONY: $(MAKECMDGOALS)

CC=clang-13
CXX=clang++-13
LLD=lld-13
RUSTFLAGS="-Clinker-plugin-lto -Clinker=${CC} -Clink-arg=-fuse-ld=${LLD}"
RUSTFLAGS_NOLTO="-Clinker=${CC} -Clink-arg=-fuse-ld=${LLD}"

CXX_SOURCE_DIR=${PWD}/rust_src/cxx
CXX_BUILD_DIR=${PWD}/build

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

cxx_configure:
	mkdir -p ${CXX_BUILD_DIR}
	rm -rf ${CXX_BUILD_DIR}/*
	CC=${CC} CXX=${CXX} cmake -S ${CXX_SOURCE_DIR} -B ${CXX_BUILD_DIR} \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
		-DCMAKE_BUILD_TYPE=Release \
		-G Ninja
	ln -f -s ${CXX_BUILD_DIR}/compile_commands.json \
		${CXX_SOURCE_DIR}/compile_commands.json
cxx_build:
	cmake --build ${CXX_BUILD_DIR} -j
cxx_run:
	${CXX_BUILD_DIR}/bin/test
