export DEBIAN_FRONTEND=noninteractive
apt update -y && apt upgrade -y
apt install -y \
    clang-13 lld-13 \
    curl \
    gcc g++ \
    cmake \
    make
curl https://sh.rustup.rs -sSf | sh -s -- -y
export PATH="$HOME/.cargo/bin:$PATH"
