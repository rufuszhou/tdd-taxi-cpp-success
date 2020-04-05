# TDD-Taxi-Cpp
docker build -t ubuntu-build-essential .
docker run -it ubuntu-build-essential
mkdir build
cd build
cmake ..
make
make test

