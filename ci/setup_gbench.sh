set -xe

BUILD_DIR="build"

git clone https://github.com/google/benchmark.git || true
cd benchmark

cmake -E make_directory ${BUILD_DIR}
cmake -S ${PWD} -B ${BUILD_DIR} \
    -DBENCHMARK_DOWNLOAD_DEPENDENCIES=True \
    -DCMAKE_BUILD_TYPE=Release \
    -G Ninja
cmake --build ${BUILD_DIR} --config Release -j$(nproc)
